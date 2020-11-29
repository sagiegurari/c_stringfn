#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split_lines_and_trim("  \r\t  123  \t  \r  \n321\n  \r\r \t 123  \t   \r");

  assert_signed_num_equal(strings.count, 3);
  assert_string_equal(strings.strings[0], "123");
  assert_string_equal(strings.strings[1], "321");
  assert_string_equal(strings.strings[2], "123");

  free(strings.strings[0]);
  free(strings.strings[1]);
  free(strings.strings[2]);
  free(strings.strings);
}


int main()
{
  test_run(test_impl);
}

