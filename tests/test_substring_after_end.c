#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_substring("test", 0, 5);

  assert_true(string == NULL);
}


int main()
{
  test_run(test_impl);
}

