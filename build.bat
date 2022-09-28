mkdir build
cd build

echo "Build Folder created"
@pause

conan install .. --build=missing  -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cd ..
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build

echo "Compilation Done"
@pause

copy .\Debug\r-type_client.exe .
copy .\Debug\r-type_server.exe .

echo "Executables created"
@pause