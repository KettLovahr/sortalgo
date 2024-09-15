#include <raylib.h>

#define SLOTS 32

static Sound beep[SLOTS];
static int cursor = 0;

int init_sound() {
    InitAudioDevice();
    for (int i = 0; i < SLOTS; i++) {
        beep[i] = LoadSound("beep.wav");
    }
    return 0;
}

void play_note(float pitch) {
    StopSound(beep[cursor]);
    SetSoundPitch(beep[cursor], pitch);
    PlaySound(beep[cursor]);
    cursor = (cursor + 1) % 5;
}
