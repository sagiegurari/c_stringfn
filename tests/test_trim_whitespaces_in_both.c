#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *string = stringfn_trim("     \r\n\t        123      \r\n\t       ");

  assert_string_equal(string, "123");
  assert_num_equal(strlen(string), 3);

  free(string);
}


int main()
{
  test_run(test_impl);
}

