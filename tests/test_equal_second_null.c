#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  bool result = stringfn_equal("1", NULL);

  assert_true(!result);
}


int main()
{
  test_run(test_impl);
}

