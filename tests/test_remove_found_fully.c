#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_remove("111111", "1");

  assert_string_equal(string, "");

  free(string);
}


int main()
{
  test_run(test_impl);
}

