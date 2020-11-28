#include "stringfn.h"
#include <stdio.h>
#include <string.h>


int main()
{
  bool result = stringfn_starts_with("my long text", "my");

  printf("Starts With: %d\n", result);
  result = stringfn_ends_with("my long text", "text");
  printf("Ends With: %d\n", result);

  char *string = stringfn_trim("  value  ");
  printf("Trimmed: %s\n", string);
  free(string);
  string = stringfn_trim_start("  value  ");
  printf("Trimmed Start: %s\n", string);
  free(string);
  string = stringfn_trim_end("  value  ");
  printf("Trimmed End: %s\n", string);
  free(string);

  string = strdup("  value  ");
  char *mut_ptr = stringfn_mut_trim(string);
  printf("Trimmed: %s\n", mut_ptr);
  free(string);
  string  = strdup("  value  ");
  mut_ptr = stringfn_mut_trim_start(string);
  printf("Trimmed Start: %s\n", mut_ptr);
  free(string);
  string  = strdup("  value  ");
  mut_ptr = stringfn_mut_trim_end(string);
  printf("Trimmed End: %s\n", mut_ptr);
  free(string);

  string = stringfn_to_uppercase("aBcD");
  printf("Case Changed: %s\n", string);
  free(string);
  string = stringfn_to_lowercase("aBcD");
  printf("Case Changed: %s\n", string);
  free(string);
  string = strdup("aBcD");
  stringfn_mut_to_uppercase(string);
  printf("Case Changed: %s\n", string);
  free(string);
  string = strdup("aBcD");
  stringfn_mut_to_lowercase(string);
  printf("Case Changed: %s\n", string);
  free(string);

  string = stringfn_remove("1;2,3|4", ";,|");
  printf("Removed Chars: %s\n", string);
  free(string);

  string = stringfn_replace("1,2,3,4", ',', ';');
  printf("Replaced Chars: %s\n", string);
  free(string);
  string = strdup("1,2,3,4");
  stringfn_mut_replace(string, ',', ';');
  printf("Replaced Chars: %s\n", string);
  free(string);

  char **strings = malloc(sizeof(char *) * 3);
  strings[0] = "first line";
  strings[1] = "second line";
  strings[2] = "3rd";
  string     = stringfn_join(strings, "\n", 0, 3);
  printf("Joined Strings: %s\n", string);
  free(string);
  string = stringfn_concat(strings, 0, 3);
  printf("Concat Strings: %s\n", string);
  free(string);
  free(strings);

  struct StringFNStrings strings_struct = stringfn_split("first line\nsecond line\n3rd", '\n');
  printf("Strings Count: %d\n%s and %s and %s\n", strings_struct.count, strings_struct.strings[0], strings_struct.strings[1], strings_struct.strings[2]);
  free(strings_struct.strings[0]);
  free(strings_struct.strings[1]);
  free(strings_struct.strings[2]);
  free(strings_struct.strings);

  return(0);
} /* main */

