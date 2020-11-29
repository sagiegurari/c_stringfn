#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split(";123;321;123;", ';');

  assert_signed_num_equal(strings.count, 5);
  assert_string_equal(strings.strings[0], "");
  assert_string_equal(strings.strings[1], "123");
  assert_string_equal(strings.strings[2], "321");
  assert_string_equal(strings.strings[3], "123");
  assert_string_equal(strings.strings[4], "");

  stringfn_release_strings_struct(strings);
}


int main()
{
  test_run(test_impl);
}

