#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char **strings = malloc(sizeof(char *) * 3);

  strings[0] = "first line";
  strings[1] = "second line";
  strings[2] = "3rd";
  char *string = stringfn_join(strings, "\nmiddle\n", 0, 3);

  assert_string_equal(string, "first line\nmiddle\nsecond line\nmiddle\n3rd");

  free(string);
  free(strings);
}


int main()
{
  test_run(test_impl);
}

