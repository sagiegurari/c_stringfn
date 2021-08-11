#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_format(NULL, "test");

  assert_true(string == NULL);
}


int main()
{
  test_run(test_impl);
}

