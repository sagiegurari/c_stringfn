#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *string = stringfn_to_uppercase(" 123 abc ABC !@#$%^&*()_+-=\\/?<>| ");

  assert_string_equal(string, " 123 ABC ABC !@#$%^&*()_+-=\\/?<>| ");

  free(string);
}


int main()
{
  test_run(test_impl);
}

