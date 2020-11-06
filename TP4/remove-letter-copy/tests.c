#include <stdio.h>
#include <string.h>
#include "tps_unit_test.h"
#include "remove-letter.h"

void test_error_malloc(void)
{
  __remaining_alloc = 0;
  char str[] = "Hello";
  char *str2 = removeLetter(str, 'e');
  tps_assert(str2 == 0);
}

void test_example_1(void)
{
  __remaining_alloc = -1;
  char str[] = "Hello";
  char *str2 = removeLetter(str, 'e');
  str[0] = '\0';
  tps_assert(strcmp(str2, "Hllo") == 0);
  free(str2);
}

void test_example_2(void)
{
  __remaining_alloc = -1;
  char str[] = "Hello";
  char *str2 = removeLetter(str, 'l');
  str[0] = '\0';
  tps_assert(strcmp(str2, "Heo") == 0);
  free(str2);
}

void test_example_3(void)
{
  char str[] = "Hello";
  char *str2 = removeLetter(str, 'a');
  str[0] = '\0';
  tps_assert(strcmp(str2, "Hello") == 0);
  free(str2);
}

void test_example_4(void)
{
  char str[] = "";
  char *str2 = removeLetter(str, 'a');
  str[0] = '\0';
  tps_assert(strcmp(str2, "") == 0);
  free(str2);
}

void test_example_5(void)
{
  char str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char *str2 = removeLetter(str, 'a');
  tps_assert(strcmp(str2, "") == 0);
  free(str2);
}


int main(void) {

  test_error_malloc();
  test_example_1();
  test_example_2();
  test_example_3();
  test_example_4();
  test_example_5();
  return 0;
}
