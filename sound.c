#define SUNVOX_MAIN
#include <raylib.h>
#include <stdio.h>

Sound beep;

int init_sound() {
    InitAudioDevice();
    beep = LoadSound("beep.wav");
    return 0;
}

void play_note(float pitch) {
    SetSoundPitch(beep, pitch);
    PlaySound(beep);
}
