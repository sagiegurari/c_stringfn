#include "stringfn.h"
#include "test.h"


void test_impl()
{
  assert_true(stringfn_is_ascii("190azAZ-=_+"));
}


int main()
{
  test_run(test_impl);
}

