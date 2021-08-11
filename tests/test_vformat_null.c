#include "stringfn.h"
#include "test.h"


void test_with_args(char *format, ...)
{
  va_list args;

  va_start(args, format);
  char *string = stringfn_vformat(format, args);

  assert_true(string == NULL);
  va_end(args);
}


void test_impl()
{
  test_with_args(NULL, "test");
}


int main()
{
  test_run(test_impl);
}

