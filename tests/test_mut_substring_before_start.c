#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("test");
  char *string = stringfn_mut_substring(input, -5, 0);

  assert_true(string == NULL);

  free(input);
}


int main()
{
  test_run(test_impl);
}

