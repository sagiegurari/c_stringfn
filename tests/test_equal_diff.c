#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  bool result = stringfn_equal("test1", "test2");

  assert_true(!result);
}


int main()
{
  test_run(test_impl);
}

