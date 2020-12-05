#include "stringfn.h"
#include "test.h"


void test_impl()
{
  assert_true(stringfn_is_digits("12345678901234567890"));
}


int main()
{
  test_run(test_impl);
}

