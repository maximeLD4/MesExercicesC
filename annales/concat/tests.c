#include <stdio.h>
#include <string.h>
#include "tps_unit_test.h"
#include "concat.h"
#include "concat.h"// <- permet de vérifié que votre .h est
                    //    protégé contre les doubles inclusions
int __remaining_alloc;
int note;

void test_error_malloc(void)
{
  __remaining_alloc = 0;
  char *concatenation = concat("test1", "test2");
  tps_assert(concatenation == NULL);
}

void test_example_1(void)
{
  __remaining_alloc = 10;
  char str1[] = "test1";
  char str2[] = "test2";
  char *concatenation = concat(str1, str2);
  tps_assert(strcmp(concatenation, "test1test2") == 0);
  tps_assert(concatenation != str1);
  tps_assert(concatenation != str2);
  free(concatenation);
}
void test_example_2(void)
{
  __remaining_alloc = 10;
  char str1[] = "";
  char str2[] = "test2";
  char *concatenation = concat(str1, str2);
  tps_assert(strcmp(concatenation, "test2") == 0);
  tps_assert(concatenation != str1);
  tps_assert(concatenation != str2);
  free(concatenation);
}

void test_example_3(void)
{
  __remaining_alloc = 10;
  char str1[] = "test1";
  char str2[] = "";
  char *concatenation = concat(str1, str2);
  tps_assert(strcmp(concatenation, "test1") == 0);
  tps_assert(concatenation != str1);
  tps_assert(concatenation != str2);
  free(concatenation);
}

void test_example_4(void)
{
  __remaining_alloc = 10;
  char str1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  char str2[] = "";
  char *concatenation = concat(str1, str2);
  tps_assert(strcmp(concatenation, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == 0);
  tps_assert(concatenation != str1);
  tps_assert(concatenation != str2);
  free(concatenation);
}


int main(void) {

  TEST(test_example_1);
  note = 10;
  TEST(test_example_2);
  TEST(test_example_3);
  TEST(test_example_4);
  note = 20;
  TEST(test_error_malloc);
  return 0;
}
