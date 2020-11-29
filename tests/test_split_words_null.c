#include "stringfn.h"
#include "test.h"


void test_impl()
{
  struct StringFNStrings strings = stringfn_split_words(NULL);

  assert_signed_num_equal(strings.count, -1);

  stringfn_release_strings_struct(strings);
}


int main()
{
  test_run(test_impl);
}

