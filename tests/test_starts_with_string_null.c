#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  bool result = stringfn_starts_with(NULL, "");

  assert_true(!result);
}


int main()
{
  test_run(test_impl);
}

