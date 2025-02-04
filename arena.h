#include <stdint.h>
#include <stdlib.h>

typedef struct {
  uint8_t *memory;
  size_t offset;
  size_t capacity;
} MemoryArena;

void init_arena(MemoryArena *arena, size_t size);
void *arena_alloc(MemoryArena *arena, size_t size);
void reset_arena(MemoryArena *arena);
void free_arena(MemoryArena *arena);