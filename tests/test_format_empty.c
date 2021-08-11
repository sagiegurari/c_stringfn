#include "string.h"
#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_format("", "test");

  assert_string_equal(string, "");
  assert_num_equal(strlen(string), 0);

  free(string);
}


int main()
{
  test_run(test_impl);
}

