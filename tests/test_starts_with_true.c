#include "stringfn.h"
#include "test.h"
#include <string.h>


void test_impl()
{
  bool result = stringfn_starts_with("1234", "123");

  assert_true(result);
}


int main()
{
  test_run(test_impl);
}

