cmake -G Ninja -B build/Release -DCMAKE_BUILD_TYPE=Release

cmake --build build/Release

PUSHD build
PUSHD Release

call nnc.exe