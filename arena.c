#include "arena.h"
#include <stdio.h>

void init_arena(MemoryArena *arena, size_t size) {
  arena->memory = (uint8_t *)malloc(size);
  arena->offset = 0;
  arena->capacity = size;

  if (!arena->memory) {
    printf("Memory allocation for arena failed!\n");
    exit(1);
  }
}

void *arena_alloc(MemoryArena *arena, size_t size) {
  if (arena->offset + size > arena->capacity) {
    printf("Arena out of memory!\n");
    return NULL;
  }

  void *ptr = arena->memory + arena->offset;
  arena->offset += size;
  return ptr;
}

void reset_arena(MemoryArena *arena) { arena->offset = 0; }

void free_arena(MemoryArena *arena) {
  free(arena->memory);
  arena->memory = NULL;
  arena->offset = 0;
  arena->capacity = 0;
}