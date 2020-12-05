#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_substring("abc", 1, 0);

  assert_string_equal(string, "bc");

  free(string);
}


int main()
{
  test_run(test_impl);
}

