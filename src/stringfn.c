#include "stringfn.h"
#include <ctype.h>
#include <string.h>


char *_stringfn_clone_substring(const char *, size_t, size_t);
char *_stringfn_trim(const char *, bool, bool);
bool _stringfn_is_whitespace(char);


bool stringfn_equal(const char *string1, const char *string2)
{
  if (string1 == NULL || string2 == NULL)
  {
    return(false);
  }

  return(strcmp(string1, string2) == 0);
}


bool stringfn_starts_with(const char *string, const char *prefix)
{
  if (string == NULL || prefix == NULL)
  {
    return(false);
  }

  size_t len = strlen(prefix);
  if (!len)
  {
    return(true);
  }

  return(strncmp(prefix, string, len) == 0);
}


bool stringfn_ends_with(const char *string, const char *suffix)
{
  if (string == NULL || suffix == NULL)
  {
    return(false);
  }

  size_t suffix_len = strlen(suffix);
  if (!suffix_len)
  {
    return(true);
  }

  size_t string_len = strlen(string);
  if (suffix_len > string_len)
  {
    return(false);
  }

  char *ptr = (char *)string + string_len - suffix_len;

  return(strncmp(ptr, suffix, suffix_len) == 0);
}


char *stringfn_trim(const char *string)
{
  return(_stringfn_trim(string, true, true));
}


char *stringfn_trim_start(const char *string)
{
  return(_stringfn_trim(string, true, false));
}


char *stringfn_trim_end(const char *string)
{
  return(_stringfn_trim(string, false, true));
}


char *stringfn_mut_trim(char *string)
{
  char *trimmed = stringfn_mut_trim_start(string);

  return(stringfn_mut_trim_end(trimmed));
}


char *stringfn_mut_trim_start(char *string)
{
  if (string == NULL)
  {
    return(NULL);
  }

  while (_stringfn_is_whitespace(*string))
  {
    string++;
  }

  return(string);
}


char *stringfn_mut_trim_end(char *string)
{
  if (string == NULL)
  {
    return(NULL);
  }

  size_t len = strlen(string);
  if (!len)
  {
    return(string);
  }

  char   *end_ptr = string + len - 1;
  size_t counter  = 0;
  while ((counter < len) && _stringfn_is_whitespace(*end_ptr))
  {
    end_ptr--;
    counter++;
  }
  *(end_ptr + 1) = '\0';

  return(string);
}


char *stringfn_to_uppercase(const char *string)
{
  if (string == NULL)
  {
    return(NULL);
  }

  char *clone = strdup(string);
  stringfn_mut_to_uppercase(clone);

  return(clone);
}


char *stringfn_to_lowercase(const char *string)
{
  if (string == NULL)
  {
    return(NULL);
  }

  char *clone = strdup(string);
  stringfn_mut_to_lowercase(clone);

  return(clone);
}


void stringfn_mut_to_uppercase(char *string)
{
  if (string == NULL)
  {
    return;
  }

  size_t len = strlen(string);

  for (size_t index = 0; index < len; index++)
  {
    if (islower(string[index]))
    {
      string[index] = (char)toupper(string[index]);
    }
  }
}


void stringfn_mut_to_lowercase(char *string)
{
  if (string == NULL)
  {
    return;
  }

  size_t len = strlen(string);

  for (size_t index = 0; index < len; index++)
  {
    if (isupper(string[index]))
    {
      string[index] = (char)tolower(string[index]);
    }
  }
}


char *stringfn_remove(char *string, char *search)
{
  if (string == NULL)
  {
    return(NULL);
  }

  if (search == NULL)
  {
    return(strdup(string));
  }

  size_t string_len = strlen(string);
  size_t search_len = strlen(search);

  if (!string_len || !search_len)
  {
    return(strdup(string));
  }

  bool   *flags   = malloc(sizeof(bool) * (string_len + 1));
  size_t new_size = 0;
  for (size_t string_index = 0; string_index < string_len; string_index++)
  {
    char character = string[string_index];

    flags[string_index] = true;
    for (size_t search_index = 0; search_index < search_len; search_index++)
    {
      if (character == search[search_index])
      {
        flags[string_index] = false;
        break;
      }
    }

    if (flags[string_index])
    {
      new_size++;
    }
  }

  char   *updated = malloc(sizeof(char) * (new_size + 1));

  size_t updated_index = 0;
  for (size_t index = 0; index < string_len; index++)
  {
    if (flags[index])
    {
      updated[updated_index] = string[index];
      updated_index++;
    }
  }

  free(flags);
  updated[new_size] = '\0';

  return(updated);
} /* stringfn_remove_all */


char *stringfn_replace(const char *string, char source, char target)
{
  if (string == NULL)
  {
    return(NULL);
  }

  char *clone = strdup(string);
  stringfn_mut_replace(clone, source, target);

  return(clone);
}


void stringfn_mut_replace(char *string, char source, char target)
{
  if (string == NULL)
  {
    return;
  }

  size_t len = strlen(string);

  for (size_t index = 0; index < len; index++)
  {
    if (string[index] == source)
    {
      string[index] = target;
    }
  }
}


char *stringfn_join(char **strings, char *separator, size_t start_index, size_t count)
{
  if (strings == NULL)
  {
    return(NULL);
  }

  if (separator == NULL)
  {
    separator = "";
  }

  size_t separator_size = strlen(separator);
  size_t total_size     = 0;
  size_t end_index      = start_index + count;
  for (size_t index = start_index; index < end_index; index++)
  {
    if (strings[index] != NULL)
    {
      if (total_size)
      {
        total_size = total_size + separator_size;
      }
      total_size = total_size + strlen(strings[index]);
    }
  }

  char   *string = malloc(sizeof(char) * (total_size + 1));
  size_t ptr     = 0;
  for (size_t index = start_index; index < end_index; index++)
  {
    if (strings[index] != NULL)
    {
      if (ptr)
      {
        for (size_t i = 0; i < separator_size; i++)
        {
          string[ptr] = separator[i];
          ptr++;
        }
      }

      size_t len = strlen(strings[index]);
      for (size_t i = 0; i < len; i++)
      {
        string[ptr] = strings[index][i];
        ptr++;
      }
    }
  }

  string[ptr] = '\0';

  return(string);
} /* stringfn_join */


char *stringfn_concat(char **strings, size_t start_index, size_t count)
{
  return(stringfn_join(strings, NULL, start_index, count));
}

struct StringFNStrings stringfn_split(char *string, char separator)
{
  struct StringFNStrings strings_struct;

  strings_struct.strings = NULL;
  strings_struct.count   = -1;

  if (string != NULL)
  {
    size_t len = strlen(string);

    size_t counter = 1;
    for (size_t index = 0; index < len; index++)
    {
      if (string[index] == separator)
      {
        counter++;
      }
    }

    strings_struct.strings = malloc(sizeof(char *) * (counter + 1));

    counter              = 0;
    strings_struct.count = 0;
    for (size_t index = 0; index < len; index++)
    {
      if (string[index] == separator)
      {
        char *sub_string = _stringfn_clone_substring(string, index - counter, counter);

        strings_struct.strings[strings_struct.count] = sub_string;
        strings_struct.count++;

        counter = 0;
      }
      else
      {
        counter++;
      }
    }
    if (string[len - 1] != separator)
    {
      char *sub_string = _stringfn_clone_substring(string, len - counter, counter);

      strings_struct.strings[strings_struct.count] = sub_string;
    }
    else
    {
      strings_struct.strings[strings_struct.count] = strdup("");
    }
    strings_struct.count++;
  }

  return(strings_struct);
} /* stringfn_split */

struct StringFNStrings stringfn_split_lines(char *string)
{
  return(stringfn_split(string, '\n'));
}


char *_stringfn_clone_substring(const char *string, size_t start, size_t size)
{
  char *target = malloc(sizeof(char) * (size + 1));

  for (size_t index = 0; index < size; index++)
  {
    target[index] = string[start + index];
  }

  target[size] = '\0';

  return(target);
}


char *_stringfn_trim(const char *string, bool trim_start, bool trim_end)
{
  if (string == NULL)
  {
    return(NULL);
  }

  size_t len = strlen(string);
  if (!len)
  {
    return(strdup(""));
  }

  size_t start = 0;
  if (trim_start)
  {
    bool found = false;
    for (size_t index = 0; index < len; index++)
    {
      if (!_stringfn_is_whitespace(string[index]))
      {
        found = true;
        start = index;
        break;
      }
    }

    if (!found)
    {
      return(strdup(""));
    }
  }

  size_t end = len - 1;
  if (trim_end)
  {
    for (size_t index = len - 1; index >= start; index--)
    {
      if (!_stringfn_is_whitespace(string[index]))
      {
        end = index;
        break;
      }
    }
  }

  len = end - start + 1;
  if (!len)
  {
    return(strdup(""));
  }

  char *trimmed = malloc(sizeof(char) * (len + 1));
  memcpy(trimmed, &string[start], len);
  trimmed[len] = '\0';

  return(trimmed);
} /* _stringfn_trim */


bool _stringfn_is_whitespace(char character)
{
  return(isspace(character) || character == '\r' || character == '\n' || character == '\t');
}

