#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("test");
  char *string = stringfn_mut_substring(input, -3, 2);

  assert_string_equal(string, "es");

  free(input);
}


int main()
{
  test_run(test_impl);
}

