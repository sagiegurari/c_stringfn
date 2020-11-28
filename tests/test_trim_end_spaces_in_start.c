#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_trim_end("             123");

  assert_string_equal(string, "             123");

  free(string);
}


int main()
{
  test_run(test_impl);
}

