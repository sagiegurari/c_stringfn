#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("");
  char *string = stringfn_mut_substring(input, 0, 0);

  assert_string_equal(string, "");

  free(input);
}


int main()
{
  test_run(test_impl);
}

