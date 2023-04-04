# Exit on error
$ErrorActionPreference = "Stop"

# Restore NuGet packages
Write-Host "Restoring NuGet packages..."
nuget restore SortingVisualizer.sln

# Install packages via Vcpkg
Write-Host "Installing packages via Vcpkg..."
vcpkg install yaml-cpp:x64-windows gtest:x64-windows sfml:x64-windows

# Integrate Vcpkg with MSBuild
Write-Host "Integrating Vcpkg with MSBuild..."
vcpkg integrate install

# Configure yaml-cpp with CMake
Write-Host "Configuring yaml-cpp with CMake..."
cmake -S external/yaml-cpp -B external/yaml-cpp/build -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake -DYAML_BUILD_SHARED_LIBS=ON

# Build yaml-cpp
Write-Host "Building yaml-cpp..."
cmake --build external/yaml-cpp/build --config Debug

Write-Host "Build complete."
