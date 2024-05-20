#include "libmap.h"

Map *NewMap(Map *optional) {
  Map *map = (Map *)malloc(sizeof(Map));

  if (map == NULL) {
    printf("MAP INIT Exception -> Failed to allocate memory!\n");
    free(map);
    exit(EXIT_FAILURE);
  }

  map->keys = (Entries *)malloc(sizeof(Entries));
  map->values = (Entries *)malloc(sizeof(Entries));
  map->keys->entries = (void **)malloc(INIT_CAP * sizeof(void *));
  map->values->entries = (void **)malloc(INIT_CAP * sizeof(void *));

  map->keys->size = 0;
  map->values->size = 0;
  map->entrySize = 0;

  if (optional != NULL) {
    MapCopy(optional, map);
  }

  return map;
}

void FreeMapMemory(Map *map) {
  free(map->keys->entries);
  free(map->values->entries);
  free(map->keys);
  free(map->values);

  map->keys = NULL;
  map->values = NULL;

  free(map);
}

void MapPut(Map *map, void *key, void *value) {
  if (map->keys->size >= INIT_CAP + 1) {
    printf("MAP PUT Exception -> Reached capacity!\n");
    return;
  }

  map->keys->entries[map->keys->size] = key;
  map->values->entries[map->values->size] = value;

  map->keys->size++;
  map->values->size++;
  map->entrySize++;
}

void *MapGet(Map *map, void *key) {
  for (size_t i = 0; i < map->keys->size; i++) {
    if (map->keys->entries[i] == key) {
      return map->values->entries[i];
    }
  }

  return NULL;
}

void MapDelete(Map *map, void *key) {
  for (size_t i = 0; i < map->keys->size; i++) {
    if (map->keys->entries[i] == key) {
      for (size_t j = i; j < map->keys->size - 1; j++) {
        map->keys->entries[j] = map->keys->entries[j + 1];
        map->values->entries[j] = map->values->entries[j + 1];
      }

      map->keys->size--;
      map->values->size--;
      map->entrySize--;
      break;
    }
  }
}

void MapClear(Map *map) {
  map->keys->size = 0;
  map->values->size = 0;
  map->entrySize = 0;
}

void *MapKeys(Map *map) {
  if (MapSize(map) == 0) return NULL;
  return map->keys->entries;
}

void *MapValues(Map *map) {
  if (MapSize(map) == 0) return NULL;
  return map->values->entries;
}

size_t MapSize(Map *map) { return map->entrySize; }

void MapCopy(Map *source, Map *dest) {
  dest->entrySize = source->entrySize;

  for (size_t i = 0; i < source->keys->size; i++) {
    dest->keys->entries[i] = source->keys->entries[i];
    dest->values->entries[i] = source->values->entries[i];
  }

  dest->keys->size = source->keys->size;
  dest->values->size = source->values->size;
}