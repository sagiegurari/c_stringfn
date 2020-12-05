#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_substring("test", 0, 0);

  assert_string_equal(string, "test");

  free(string);
}


int main()
{
  test_run(test_impl);
}

