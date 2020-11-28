#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *string = strdup(" 123 abc ABC !@#$%^&*()_+-=\\/?<>| ");

  stringfn_mut_to_uppercase(string);

  assert_string_equal(string, " 123 ABC ABC !@#$%^&*()_+-=\\/?<>| ");

  free(string);
}


int main()
{
  test_run(test_impl);
}

