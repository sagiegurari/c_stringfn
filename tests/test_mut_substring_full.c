#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("test");
  char *string = stringfn_mut_substring(input, 0, 4);

  assert_string_equal(string, "test");

  free(input);
}


int main()
{
  test_run(test_impl);
}

