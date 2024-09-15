#define SUNVOX_MAIN
#include <dlfcn.h>
#include "sunvox.h"
#include <stdio.h>

int init_sound() {
    sv_load_dll();
    if (sv_init(NULL, 44100, 2, SV_INIT_FLAG_AUDIO_FLOAT32) < 0) {
        printf("Error initializing SoundVox");
        return 1;
    }
    sv_open_slot(0);
    if (sv_load(0, "tri.sunvox")) {
        printf("Error loading file.");
        return 1;
    }
    return 0;
}

void play_note(int which) {
    sv_send_event(0, 0, which, 127, 2, 0, 0);
}

void deinit_sound() {
    sv_close_slot(0);
    sv_deinit();
    sv_unload_dll();
}
