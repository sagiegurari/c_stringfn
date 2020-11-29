#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split_words("  \r\t  1    2 \t \t 3  \t  \r  \n321\n  \r\r \t 123  \t   \r");

  assert_signed_num_equal(strings.count, 5);
  assert_string_equal(strings.strings[0], "1");
  assert_string_equal(strings.strings[1], "2");
  assert_string_equal(strings.strings[2], "3");
  assert_string_equal(strings.strings[3], "321");
  assert_string_equal(strings.strings[4], "123");

  stringfn_release_strings_struct(strings);
}


int main()
{
  test_run(test_impl);
}

