#include "util.c"
#include <raylib.h>

#define ARR_SIZE 64

void draw_list(int a[], int length, int max_value, float width, float height,
               float margin, float padding, int cursor) {
  float real_width = width - (margin * 2);
  float real_height = height - (margin * 2);
  for (int i = 0; i < length; i++) {
    DrawRectangle(margin + (real_width / length) * i + padding,
                  (margin + real_height) -
                      (real_height * (float)(a[i]) / (float)(max_value)),
                  real_width / length - padding,
                  (real_height * (float)(a[i]) / (float)(max_value)),
                  i == cursor ? GREEN : RAYWHITE);
  }
}

int main() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(960, 540, "Sort Algo");

  SetTargetFPS(60);

  int a[256];
  populate_list(a, ARR_SIZE);
  print_list(a, ARR_SIZE);

  int cursor = 0;
  int iteration = 0;

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    bubble_step(a, ARR_SIZE, &cursor, &iteration, 3);
    draw_list(a, ARR_SIZE, ARR_SIZE, GetScreenWidth(), GetScreenHeight(), 8, 2,
              cursor);

    if (IsKeyPressed(KEY_SPACE)) {
      populate_list(a, ARR_SIZE);
      cursor = 0;
      iteration = 0;
    }

    EndDrawing();
  }

  CloseWindow();
}
