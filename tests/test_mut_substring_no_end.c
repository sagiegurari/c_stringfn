#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("abc");
  char *string = stringfn_mut_substring(input, 1, 0);

  assert_string_equal(string, "bc");

  free(input);
}


int main()
{
  test_run(test_impl);
}

