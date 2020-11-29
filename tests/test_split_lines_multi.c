#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split_lines("123\n321\n123");

  assert_signed_num_equal(strings.count, 3);
  assert_string_equal(strings.strings[0], "123");
  assert_string_equal(strings.strings[1], "321");
  assert_string_equal(strings.strings[2], "123");

  stringfn_release_strings_struct(strings);
}


int main()
{
  test_run(test_impl);
}

