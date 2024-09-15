#include "util.c"
#include "sound.c"
#include <raylib.h>

#define ARR_SIZE 64

void draw_list(int a[], int length, int max_value, float width, float height,
               float margin, float padding, int cursor, bool done) {
  float real_width = width - (margin * 2);
  float real_height = height - (margin * 2);
  for (int i = 0; i < length; i++) {
      Color col;
    if (!done) {
        col = i == cursor ? GREEN : RAYWHITE;
    } else {
        col = i <= cursor ? GREEN : RAYWHITE;
    }
    DrawRectangle(margin + (real_width / length) * i + padding,
                  (margin + real_height) -
                      (real_height * (float)(a[i]) / (float)(max_value)),
                  real_width / length - padding,
                  (real_height * (float)(a[i]) / (float)(max_value)),
                  col);
  }
}

int main() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(960, 540, "Sort Algo");

  init_sound();

  SetTargetFPS(60);

  int a[256];
  populate_list(a, ARR_SIZE);
  print_list(a, ARR_SIZE);

  int cursor = 0;
  int iteration = 0;
  bool done = false;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    if (!done) {
        bubble_step(a, ARR_SIZE, &cursor, &iteration, 3);
        if (!is_sorted(a, ARR_SIZE)) {
            play_note( 0.5 + ((float)a[cursor] / ARR_SIZE) * 2);
        } else {
            done = true;
            cursor = 0;
        }
    } else {
        if (cursor < ARR_SIZE) {
            play_note( 0.5 + ((float)a[cursor] / ARR_SIZE) * 2);
            cursor++;
        }
    }
    draw_list(a, ARR_SIZE, ARR_SIZE, GetScreenWidth(), GetScreenHeight(), 8, 2,
            cursor, done);

    if (IsKeyPressed(KEY_SPACE)) {
      populate_list(a, ARR_SIZE);
      cursor = 0;
      iteration = 0;
      done = false;
    }

    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();
}
