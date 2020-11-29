#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_new_empty_string();

  assert_string_equal(string, "");

  free(string);
}


int main()
{
  test_run(test_impl);
}

