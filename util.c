#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_list(int a[], int length) {
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < length; i++) {
    int try = rand() % length;
    while (a[try] != 0) {
      try = rand() % length;
    }
    a[try] = i + 1;
  }
}

bool is_sorted(int a[], int length) {
  for (int i = 0; i < length - 1; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}

void swap(int *a, int *b) {
  int buf = *a;
  *a = *b;
  *b = buf;
}

void print_list(int a[], int length) {
  for (int i = 0; i < length; i++) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", a[i]);
  }
  printf("\n");
}

void bubble_step(int a[], int length, int *cursor, int *iteration, int repeat) {
  for (int i = 0; i < repeat; i++) {
    if (!is_sorted(a, length)) {
      if (a[*cursor] > a[*cursor + 1]) {
        swap(&a[*cursor], &a[*cursor + 1]);
      }
      *cursor += 1;
      if (*cursor == length - 1 - *iteration) {
        *cursor = 0;
        *iteration += 1;
      }
    } else {
      break;
    }
  }
}
