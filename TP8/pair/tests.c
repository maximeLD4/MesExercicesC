#include <stdio.h>
#include "tps_unit_test.h"
#include "pair.h"

TEST_INIT_GLOBAL

void test_create(void)
{
  __remaining_alloc = -1;
  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  int *pfirst = (int*)pair_get_first(pair);
  int first = *pfirst;

  tps_assert(first == 1);
  pair_free(pair);
}

void test_get_second(void)
{
  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  int *psecond = (int*)pair_get_second(pair);
  int second = *psecond;

  tps_assert(second == 2);
  pair_free(pair);
}

void test_swap(void)
{
  int a = 1, b = 2;
  pair_t *pair = pair_create(&a, &b);

  pair_swap(pair);

  int *psecond = (int*)pair_get_second(pair);
  int second = *psecond;
  tps_assert(second == 1);

  int *pfirst = (int*)pair_get_first(pair);
  int first = *pfirst;
  tps_assert(first == 2);

  pair_free(pair);
}
int main(void)
{
  TEST(test_create);
  TEST(test_get_second);
  TEST(test_swap);
}
