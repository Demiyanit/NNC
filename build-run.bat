cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Debug

cmake --build build/

PUSHD build

call nnc.exe