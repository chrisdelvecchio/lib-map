#include <stdio.h>

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

int main() {
  Map *map = NewMap(NULL);
  MapPut(map, (void *)"key1", (void *)2);
  MapPut(map, (void *)"key2", (void *)"fuck69");
  printf("Gotten value from 'key1': %d\n", MapGet(map, (void *)"key1"));

  Map *copyMap = NewMap(map);

  FreeMapMemory(map);
  FreeMapMemory(copyMap);
  return 0;
}