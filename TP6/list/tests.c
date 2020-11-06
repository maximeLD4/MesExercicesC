#include <stdio.h>
#include "tps_unit_test.h"
#include "list.h"

void test_create(void)
{
  list_t* l = list_create();
  tps_assert(l != NULL);
  list_free(l);
}

void test_size(void)
{
    list_t* l = list_create();
    list_append(l, 1);
    list_append(l, 2);
    list_append(l, 3);

    tps_assert(list_size(l) == 3);
    list_free(l);
}
void test_prepend(void)
{
    list_t* l = list_create();
    list_prepend(l, 1);
    list_prepend(l, 2);
    list_prepend(l, 3);
    tps_assert(list_get(l,0) == 3);
    tps_assert(list_get(l,1) == 2);
    tps_assert(list_get(l,2) == 1);

    list_free(l);
}

void test_size2(void)
{
    list_t* l = list_create();

    for(int i = 0; i < 100000; i++)
    {
      list_prepend(l, 1);
    }

    for(int i = 0; i < 100000; i++)
    {
      tps_assert(list_size(l) == 100000);
    }
    list_free(l);
}

int main(void)
{
  TEST(test_create);
  TEST(test_size);
  TEST(test_prepend);
  TEST(test_size2);

}
