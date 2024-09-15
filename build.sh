clang -o sortalgo main.c -Iinclude -Llib -ldl -lc -lraylib

if [[ "$1" == "run" ]]; then
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$PWD/lib"
    ./sortalgo
fi
