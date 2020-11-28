#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_remove("test", "");

  assert_string_equal(string, "test");

  free(string);
}


int main()
{
  test_run(test_impl);
}

