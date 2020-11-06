#include <stdio.h>
#include <stdlib.h>

int __remaining_alloc = -1;

#define calloc(a,b) \
  (__remaining_alloc \
    ? __remaining_alloc--, calloc(a,b) \
    : NULL)
#define malloc(a) \
  (__remaining_alloc \
    ? __remaining_alloc--, malloc(a) \
    : NULL)
#define realloc(a,b) \
  (__remaining_alloc \
    ? __remaining_alloc--, realloc(a,b) \
    : NULL)



void tps_test_error(char *msg) {
  printf("%s", msg);
  {
      printf(" [ FAILED ]\n");
  }
}

#define tps_assert(expr) \
  do { \
    if (!(expr)) { \
      tps_test_error("assertion failed: " #expr); \
      exit(1); \
      return; \
    } \
  } while (0)
