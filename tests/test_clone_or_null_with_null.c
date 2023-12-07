#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_clone_or_null(NULL);

  assert_true(string == NULL);
}


int main()
{
  test_run(test_impl);
}

