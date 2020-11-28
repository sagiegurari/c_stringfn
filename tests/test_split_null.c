#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split(NULL, ' ');

  assert_signed_num_equal(strings.count, -1);
  assert_true(strings.strings == NULL);
}


int main()
{
  test_run(test_impl);
}

