#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split("abc", 'c');

  assert_signed_num_equal(strings.count, 2);
  assert_string_equal(strings.strings[0], "ab");
  assert_string_equal(strings.strings[1], "");

  stringfn_release_strings_struct(strings);
}


int main()
{
  test_run(test_impl);
}

