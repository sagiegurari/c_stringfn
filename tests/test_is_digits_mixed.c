#include "stringfn.h"
#include "test.h"


void test_impl()
{
  assert_true(!stringfn_is_digits("1234567890a1234567890"));
}


int main()
{
  test_run(test_impl);
}

