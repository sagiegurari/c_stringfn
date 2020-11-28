#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("             ");
  char *string = stringfn_mut_trim_end(input);

  assert_string_equal(string, "");

  free(input);
}


int main()
{
  test_run(test_impl);
}

