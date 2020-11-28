#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char **strings = malloc(sizeof(char *) * 7);

  strings[0] = "first line";
  strings[1] = "second line";
  strings[2] = "3rd";
  strings[3] = "some line";
  strings[4] = "4!!!";
  strings[5] = "bad";
  strings[6] = "worse";
  char *string = stringfn_join(strings, "\nmiddle\n", 2, 3);

  assert_string_equal(string, "3rd\nmiddle\nsome line\nmiddle\n4!!!");

  free(string);
  free(strings);
}


int main()
{
  test_run(test_impl);
}

