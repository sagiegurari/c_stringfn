#include "stringfn.h"
#include "test.h"


void test_impl()
{
  assert_true(!stringfn_is_digits(NULL));
}


int main()
{
  test_run(test_impl);
}

