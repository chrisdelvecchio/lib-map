#ifndef __LIBMAP__
#define __LIBMAP__

#define INIT_CAP 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entries {
  void **entries;
  size_t size;
} Entries;

typedef struct Map {
  Entries *keys;
  Entries *values;
  size_t entrySize;
} Map;

Map *NewMap(Map *optional);
void FreeMapMemory(Map *map);
void MapPut(Map *map, void *key, void *value);
void *MapGet(Map *map, void *key);
void MapDelete(Map *map, void *key);
void *MapKeys(Map *map);
void *MapValues(Map *map);
void MapClear(Map *map);
size_t MapSize(Map *map);

#endif  //__LIBMAP__