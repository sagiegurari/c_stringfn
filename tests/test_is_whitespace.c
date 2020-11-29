#include "stringfn.h"
#include "test.h"


void test_impl()
{
  assert_true(stringfn_is_whitespace(' '));
  assert_true(stringfn_is_whitespace('\n'));
  assert_true(stringfn_is_whitespace('\r'));
  assert_true(stringfn_is_whitespace('\t'));
  assert_true(!stringfn_is_whitespace('a'));
}


int main()
{
  test_run(test_impl);
}

