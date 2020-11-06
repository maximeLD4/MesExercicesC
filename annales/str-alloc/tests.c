#include <stdio.h>
#include <string.h>
#include "tps_unit_test.h"
#include "str-alloc.h"

void test_example_1(void)
{
  __remaining_alloc = -1;

  student_t s;
  strAlloc(&s, 10);
  tps_assert(s.first_name != NULL);
  tps_assert(s.last_name != NULL);
  free(s.first_name);
  free(s.last_name);
}

void test_example_2(void)
{
  __remaining_alloc = -1;

  student_t s;
  strAlloc(&s, 10000);
  tps_assert(s.first_name != NULL);
  tps_assert(s.last_name != NULL);
  free(s.first_name);
  free(s.last_name);
}

void test_access(void)
{
  __remaining_alloc = -1;

  student_t s;
  strAlloc(&s, 100000);
  tps_assert(s.first_name != NULL);
  tps_assert(s.last_name != NULL);
  s.first_name[99999] = 'A';
  free(s.first_name);
  free(s.last_name);
}

void test_value(void)
{
    __remaining_alloc = -1;

  student_t s;
  strAlloc(&s, 1000);
  tps_assert(s.first_name != NULL);
  tps_assert(s.last_name != NULL);
  for(int i = 0; i < 1000; i++)
  {
    tps_assert(s.first_name[i] == 0);
    tps_assert(s.last_name[i] == 0);
  }
  free(s.first_name);
  free(s.last_name);
}

void test_alloc_1(void)
{
    __remaining_alloc = 0;

    student_t s;
    strAlloc(&s, 10);
    tps_assert(s.first_name == NULL);
    tps_assert(s.last_name == NULL);
}
void test_alloc_2(void)
{
    __remaining_alloc = 1;

    student_t s;
    strAlloc(&s, 10);
    tps_assert(s.first_name == NULL);
    tps_assert(s.last_name == NULL);
}


int main(int argc, char ** argv) {

  int test_idx = argc > 1 ? atoi(argv[1]) : -1;

  switch(test_idx){
    default:
    case 5:
    test_alloc_2();
    case 4:
    test_alloc_1();
    case 3:
    test_value();
    case 2:
    test_access();
    case 1:
    test_example_2();
    case 0:
    test_example_1();
  }

  return 0;
}
