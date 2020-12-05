#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_substring("test", -3, 2);

  assert_string_equal(string, "es");

  free(string);
}


int main()
{
  test_run(test_impl);
}

