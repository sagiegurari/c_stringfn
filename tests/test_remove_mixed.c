#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_remove("12344321 test abc ABC 12344321", "1bC ");

  assert_string_equal(string, "234432testacAB234432");

  free(string);
}


int main()
{
  test_run(test_impl);
}

