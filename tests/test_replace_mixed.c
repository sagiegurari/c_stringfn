#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  char *string = stringfn_replace(" 12ts3 abstc ABSTC !@#$%^&*()_+-=\\/?<>| s", 's', 't');

  assert_string_equal(string, " 12tt3 abttc ABSTC !@#$%^&*()_+-=\\/?<>| t");

  free(string);
}


int main()
{
  test_run(test_impl);
}

