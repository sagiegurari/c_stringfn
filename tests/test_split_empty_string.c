#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split("", ' ');

  assert_string_equal(strings.strings[0], "");
  assert_signed_num_equal(strings.count, 1);

  free(strings.strings[0]);
  free(strings.strings);
}


int main()
{
  test_run(test_impl);
}

