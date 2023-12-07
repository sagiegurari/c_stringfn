#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_clone_or_null("TEST");

  assert_string_equal(string, "TEST");

  free(string);
}


int main()
{
  test_run(test_impl);
}

