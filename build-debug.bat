cmake -G Ninja -B build/Debug -DCMAKE_BUILD_TYPE=Debug

cmake --build build/Debug

PUSHD build
PUSHD Debug

call nnc.exe