#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *string = stringfn_to_lowercase(" 123 abc ABC !@#$%^&*()_+-=\\/?<>| ");

  assert_string_equal(string, " 123 abc abc !@#$%^&*()_+-=\\/?<>| ");

  free(string);
}


int main()
{
  test_run(test_impl);
}

