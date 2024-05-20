#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#include "libmap.h"

// -> Create a new Empty Map                                    = Map
// *NewMap(Map *optional);
// -> Free all map memory allocated                             = void
// FreeMapMemory(Map *map);
// -> Insert a key with a value                                 = void
// MapPut(Map *map, void *key, void *value);
// -> Return a value from key                                   = void
// *MapGet(Map *map, void *key);
// -> Delete a key                                              = void
// MapDelete(Map *map, void *key);
// -> Return all Key 'entries'                                  = void
// *MapKeys(Map *map);
// -> Return all Value 'value's'                                = void
// *MapValues(Map *map);
// -> Clear the map                                             = void
// MapClear(Map *map);
// -> Return entry size of map                                  = size_t
// MapSize(Map *map);
// -> Copy one map to another map                               = void
// MapCopy(Map *source, Map *dest);

long long currentTimeInMillis() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main() {
  long long startTimeMillis = currentTimeInMillis();

  Map *map = NewMap(NULL);
  for (int i = 0; i < 1024; i++) {
    MapPut(map, (void *)(intptr_t)i, (void *)(intptr_t)i - 1);
    printf("Key: %d, Value: %d\n", i, MapGet(map, (void *)(intptr_t)i - 1));
  }

  FreeMapMemory(map);

  long long endTimeMillis = currentTimeInMillis();
  printf("\nTime taken: %lld ms\n", endTimeMillis - startTimeMillis);
  return 0;
}