gcc -o sortalgo main.c -lc -lraylib

if [[ "$1" == "run" ]]; then
    ./sortalgo
fi
