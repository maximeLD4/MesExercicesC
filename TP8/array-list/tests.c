#include <stdio.h>
#include "tps_unit_test.h"
#include "array-list.h"

TEST_INIT_GLOBAL

int *create_int(int i)
{
  int * p = malloc(sizeof(int));
  *p = i;
  return p;
}

void test_create(void)
{
  list_t* l = list_create();
  tps_assert(l != NULL);
  list_free(l);
}

void test_size(void)
{
    list_t* l = list_create();
    list_append(l, create_int(1));
    list_append(l, create_int(2));
    list_append(l, create_int(3));

    tps_assert(list_size(l) == 3);
    list_free(l);
}
void test_prepend(void)
{
    list_t* l = list_create();
    list_prepend(l, create_int(1));
    list_prepend(l, create_int(2));
    list_prepend(l, create_int(3));
    tps_assert(*(int*)list_get(l,0) == 3);
    tps_assert(*(int*)list_get(l,1) == 2);
    tps_assert(*(int*)list_get(l,2) == 1);

    list_free(l);
}

void test_size2(void)
{
    list_t* l = list_create();

    for(int i = 0; i < 10000; i++)
    {
      list_prepend(l, create_int(i));
    }

    for(int i = 0; i < 100000; i++)
    {
      tps_assert(list_size(l) == 10000);
    }
    list_free(l);
}

void test_get2(void)
{
    list_t* l = list_create();

    for(int i = 0; i < 10000; i++)
    {
      list_append(l, create_int(i));
    }

    for(int i = 0; i < 100000; i++)
    {
      tps_assert(*(int*)list_get(l, 5000) == 5000);
    }
    list_free(l);
}

void test_set(void)
{
  list_t* l = list_create();
  tps_assert(l != NULL);
  list_append(l, create_int(1));
  list_append(l, create_int(2));
  list_append(l, create_int(3));
  list_set(l, 1, create_int(10));
  tps_assert(*(int*)list_get(l, 0) == 1);
  tps_assert(*(int*)list_get(l, 1) == 10);
  tps_assert(*(int*)list_get(l, 2) == 3);
  list_free(l);
}
void test_take(void)
{
  list_t* l = list_create();
  tps_assert(l != NULL);
  list_append(l, create_int(1));
  list_append(l, create_int(2));
  list_append(l, create_int(3));
  int *el = list_take(l, 1);
  tps_assert(*(int*)list_get(l, 0) == 1);
  tps_assert(*(int*)list_get(l, 1) == 3);
  tps_assert(*el == 2);
  free(el);
  list_free(l);
}
void test_insert(void)
{
  list_t* l = list_create();
  tps_assert(l != NULL);
  list_append(l, create_int(1));
  list_append(l, create_int(2));
  list_append(l, create_int(3));
  list_insert(l, 1, create_int(10));
  tps_assert(*(int*)list_get(l, 0) == 1);
  tps_assert(*(int*)list_get(l, 1) == 10);
  tps_assert(*(int*)list_get(l, 2) == 2);
  list_free(l);
}

void test_error_malloc(void)
{
  __remaining_alloc = 0;
  list_t* l = list_create();
  tps_assert(l == NULL);
}
void test_error_malloc2(void)
{
  __remaining_alloc = 1;
  list_t* l = list_create();
  tps_assert(l == NULL);
}
void test_error_malloc3(void)
{
  __remaining_alloc = -1;
  list_t* l = list_create();

  int *v[100];
  int i;
  for(i = 0; i < 100; i++)
  {
    v[i] = create_int(10);
  } 
  __remaining_alloc = 0;
 
  int ok = 1;
  for(i = 0; i < 100; i++)
  {
    ok = list_prepend(l, v[i]);
    if(!ok)
    {
      break;
    }
  }

  tps_assert(ok == 0);
  list_free(l);

  for(i; i < 100; i++)
  {
    free(v[i]);
  }
}

int main(void)
{
  TEST(test_create);
  TEST(test_size);
  TEST(test_prepend);
  TEST(test_size2);
  TEST(test_get2);
  TEST(test_set);
  TEST(test_take);
  TEST(test_insert);
  TEST(test_error_malloc);
  TEST(test_error_malloc2);
  TEST(test_error_malloc3);
}
