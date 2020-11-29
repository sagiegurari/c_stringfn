# stringfn

[![CI](https://github.com/sagiegurari/c_stringfn/workflows/CI/badge.svg?branch=master)](https://github.com/sagiegurari/c_stringfn/actions)
[![Release](https://img.shields.io/github/v/release/sagiegurari/c_stringfn)](https://github.com/sagiegurari/c_stringfn/releases)
[![license](https://img.shields.io/github/license/sagiegurari/c_stringfn)](https://github.com/sagiegurari/c_stringfn/blob/master/LICENSE)

> String functions for C.

* [Overview](#overview)
* [Usage](#usage)
* [Contributing](.github/CONTRIBUTING.md)
* [Release History](CHANGELOG.md)
* [License](#license)

<a name="overview"></a>
## Overview
This library provides many string related functions that you always looked for and are missing in the C standard library.

<a name="usage"></a>
## Usage

```c
#include "stringfn.h"
#include <stdio.h>
#include <string.h>


int main()
{
  printf("Library Examples:\n");

  bool result = stringfn_equal("test", "test");
  printf("Strings Same: %d\n", result);

  result = stringfn_starts_with("my long text", "my");
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
  stringfn_release_strings_struct(strings_struct);

  strings_struct = stringfn_split_lines("first line\nsecond line\n3rd");
  printf("Strings Count: %d\n%s and %s and %s\n", strings_struct.count, strings_struct.strings[0], strings_struct.strings[1], strings_struct.strings[2]);
  stringfn_release_strings_struct(strings_struct);

  strings_struct = stringfn_split_lines_and_trim("  first line  \n\tsecond line\t\n  3rd");
  printf("Strings Count: %d\n%s and %s and %s\n", strings_struct.count, strings_struct.strings[0], strings_struct.strings[1], strings_struct.strings[2]);
  stringfn_release_strings_struct(strings_struct);

  strings_struct = stringfn_split_words("word1 2 3   another \tlast");
  printf("Strings Count: %d\n%s and %s and %s and %s and %s\n", strings_struct.count, strings_struct.strings[0], strings_struct.strings[1], strings_struct.strings[2], strings_struct.strings[3], strings_struct.strings[4]);
  stringfn_release_strings_struct(strings_struct);

  return(0);
} /* main */
```

## Contributing
See [contributing guide](.github/CONTRIBUTING.md)

<a name="history"></a>
## Release History

See [Changelog](CHANGELOG.md)

<a name="license"></a>
## License
Developed by Sagie Gur-Ari and licensed under the Apache 2 open source license.
