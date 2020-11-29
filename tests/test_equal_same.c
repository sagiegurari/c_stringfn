#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  bool result = stringfn_equal("test", "test");

  assert_true(result);
}


int main()
{
  test_run(test_impl);
}

