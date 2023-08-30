cmake -S ./ -B build/

cmake --build build/

PUSHD build

PUSHD Debug

call nnc.exe
