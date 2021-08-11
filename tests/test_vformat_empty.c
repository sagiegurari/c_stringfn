#include "string.h"
#include "stringfn.h"
#include "test.h"


void test_with_args(char *format, ...)
{
  va_list args;

  va_start(args, format);
  char *string = stringfn_vformat(format, args);

  assert_string_equal(string, "");
  assert_num_equal(strlen(string), 0);
  va_end(args);

  free(string);
}


void test_impl()
{
  test_with_args("", "test");
}


int main()
{
  test_run(test_impl);
}

