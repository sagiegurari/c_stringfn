#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char **strings = malloc(sizeof(char *) * 3);

  strings[0] = "first line";
  strings[1] = "second line";
  strings[2] = "3rd";
  char *string = stringfn_concat(strings, 0, 3);

  assert_string_equal(string, "first linesecond line3rd");

  free(string);
  free(strings);
}


int main()
{
  test_run(test_impl);
}

