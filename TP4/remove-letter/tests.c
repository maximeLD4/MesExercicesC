#include <stdio.h>
#include <string.h>
#include "tps_unit_test.h"
#include "remove-letter.h"

void test_example_1(void)
{
  char str[] = "Hello";
  removeLetter(str, 'e');
  tps_assert(strcmp(str, "Hllo") == 0);
}

void test_example_2(void)
{
  char str[] = "Hello";
  removeLetter(str, 'l');
  tps_assert(strcmp(str, "Heo") == 0);
}

void test_example_3(void)
{
  char str[] = "Hello";
  removeLetter(str, 'a');
  tps_assert(strcmp(str, "Hello") == 0);
}

void test_example_4(void)
{
  char str[] = "";
  removeLetter(str, 'a');
  tps_assert(strcmp(str, "") == 0);
}

void test_example_5(void)
{
  char str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  removeLetter(str, 'a');
  tps_assert(strcmp(str, "") == 0);
}

void test_example_6(void)
{
  char str[] = "\0a";
  removeLetter(str, '\0');
  tps_assert(str[0] == '\0');
  tps_assert(str[1] == 'a');
  tps_assert(str[2] == '\0');
}


int main(void) {

  test_example_1();
  test_example_2();
  test_example_3();
  test_example_4();
  test_example_5();
  test_example_6();
  return 0;
}
