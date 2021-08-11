#include "string.h"
#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_format("test %d format %s", 1, "test");

  assert_string_equal(string, "test 1 format test");
  assert_num_equal(strlen(string), 18);

  free(string);
}


int main()
{
  test_run(test_impl);
}

