#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  bool result = stringfn_ends_with("1234", "234");

  assert_true(result);
}


int main()
{
  test_run(test_impl);
}

