#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *input  = strdup("123  abc");
  char *string = stringfn_mut_trim_start(input);

  assert_string_equal(string, "123  abc");
  assert_num_equal(strlen(string), 8);

  free(input);
}


int main()
{
  test_run(test_impl);
}

