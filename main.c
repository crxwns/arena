#include "arena.h"
#include <stdio.h>

#define N 1000
#define ARENA_SIZE (N * (sizeof(char[20]) + sizeof(int) + sizeof(float)))

typedef struct {
  char (*names)[20];
  int *ages;
  float *gpas;
} StudentData;

void structure_of_arrays(MemoryArena *arena) {
  StudentData data;

  data.names = (char(*)[20])arena_alloc(arena, N * sizeof(char[20]));
  data.ages = (int *)arena_alloc(arena, N * sizeof(int));
  data.gpas = (float *)arena_alloc(arena, N * sizeof(float));

  if (!data.names || !data.ages || !data.gpas) {
    printf("Memory allocation in arena failed!\n");
    free_arena(arena);
    exit(1);
  }

  for (int i = 0; i < N; i++) {
    snprintf(data.names[i], 20, "Student%d", i);
    data.ages[i] = 18 + (i % 5);
    data.gpas[i] = 3.0 + (i % 10) * 0.1;
  }

  for (int i = 0; i < 5; i++) {
    printf("Name: %s, Age: %d, GPA: %.2f\n", data.names[i], data.ages[i],
           data.gpas[i]);
  }
}

int main(int argc, char *argv[]) {
  MemoryArena arena;
  init_arena(&arena, ARENA_SIZE);

  structure_of_arrays(&arena);

  reset_arena(&arena);
  free_arena(&arena);

  return 0;
}
