#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_trim_start("             ");

  assert_string_equal(string, "");

  free(string);
}


int main()
{
  test_run(test_impl);
}

