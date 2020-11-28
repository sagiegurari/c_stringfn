#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("             123");
  char *string = stringfn_mut_trim_start(input);

  assert_string_equal(string, "123");

  free(input);
}


int main()
{
  test_run(test_impl);
}

