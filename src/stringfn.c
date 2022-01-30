#include "stringfn.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>


struct StringFNSubStringIndex
{
  size_t start;
  size_t end;
  size_t length;
  bool   valid;
};

static char *_stringfn_clone_substring(const char *, size_t, size_t);
static struct StringFNSubStringIndex _stringfn_get_substring_index(const char *, int, size_t);
static char *_stringfn_trim(const char *, bool, bool);


char *stringfn_new_empty_string()
{
  char *string = malloc(sizeof(char));

  string[0] = '\0';

  return(string);
}


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


bool stringfn_is_whitespace(char character)
{
  return(isspace(character) || character == '\r' || character == '\n' || character == '\t');
}


bool stringfn_is_digits(const char *string)
{
  if (string == NULL)
  {
    return(false);
  }

  size_t length = strlen(string);
  if (!length)
  {
    return(false);
  }

  for (size_t index = 0; index < length; index++)
  {
    if (!isdigit(string[index]))
    {
      return(false);
    }
  }

  return(true);
}


bool stringfn_is_ascii(const char *string)
{
  if (string == NULL)
  {
    return(false);
  }

  size_t length = strlen(string);
  if (!length)
  {
    return(false);
  }

  for (size_t index = 0; index < length; index++)
  {
    if (!isascii(string[index]))
    {
      return(false);
    }
  }

  return(true);
}


char *stringfn_substring(const char *string, int start, size_t length)
{
  struct StringFNSubStringIndex sub_string_index = _stringfn_get_substring_index(string, start, length);

  if (!sub_string_index.valid)
  {
    return(NULL);
  }

  char *substring = _stringfn_clone_substring(string, sub_string_index.start, sub_string_index.length);

  return(substring);
}


char *stringfn_mut_substring(char *string, int start, size_t length)
{
  struct StringFNSubStringIndex sub_string_index = _stringfn_get_substring_index(string, start, length);

  if (!sub_string_index.valid)
  {
    return(NULL);
  }

  char *substring = &string[sub_string_index.start];
  char *end       = &string[sub_string_index.end];
  *end = '\0';

  return(substring);
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

  while (stringfn_is_whitespace(*string))
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
  while ((counter < len) && stringfn_is_whitespace(*end_ptr))
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

  if (string == NULL)
  {
    return(strings_struct);
  }

  size_t len = strlen(string);
  if (!len)
  {
    strings_struct.strings    = malloc(sizeof(char *));
    strings_struct.strings[0] = stringfn_new_empty_string();
    strings_struct.count      = 1;
    return(strings_struct);
  }

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
    strings_struct.strings[strings_struct.count] = stringfn_new_empty_string();
  }
  strings_struct.count++;

  return(strings_struct);
} /* stringfn_split */

struct StringFNStrings stringfn_split_lines(char *string)
{
  return(stringfn_split(string, '\n'));
}

struct StringFNStrings stringfn_split_lines_and_trim(char *string)
{
  struct StringFNStrings strings = stringfn_split_lines(string);

  for (int index = 0; index < strings.count; index++)
  {
    char *line = strings.strings[index];
    strings.strings[index] = stringfn_trim(line);
    free(line);
  }

  return(strings);
}

struct StringFNStrings stringfn_split_words(char *string)
{
  struct StringFNStrings strings = stringfn_split(string, ' ');

  if (strings.count < 0)
  {
    return(strings);
  }

  int count = 0;
  for (int index = 0; index < strings.count; index++)
  {
    char *word = strings.strings[index];
    strings.strings[index] = stringfn_trim(word);
    free(word);

    if (strlen(strings.strings[index]))
    {
      count++;
    }
    else
    {
      free(strings.strings[index]);
      strings.strings[index] = NULL;
    }
  }

  struct StringFNStrings words;
  words.count   = 0;
  words.strings = malloc(sizeof(char *) * (unsigned int)count);
  for (int index = 0; index < strings.count; index++)
  {
    if (strings.strings[index] != NULL)
    {
      words.strings[words.count] = strings.strings[index];
      words.count++;
    }
  }

  free(strings.strings);

  return(words);
} /* stringfn_split_words */


void stringfn_release_strings_struct(struct StringFNStrings strings)
{
  if (strings.count < 0 || strings.strings == NULL)
  {
    return;
  }

  for (int index = 0; index < strings.count; index++)
  {
    if (strings.strings[index] != NULL)
    {
      free(strings.strings[index]);
    }
  }

  free(strings.strings);
}


char *stringfn_format(const char *format, ...)
{
  if (format == NULL)
  {
    return(NULL);
  }
  va_list args;

  va_start(args, format);
  char *output = stringfn_vformat(format, args);
  va_end(args);

  return(output);
}


char *stringfn_vformat(const char *format, va_list args)
{
  if (format == NULL)
  {
    return(NULL);
  }
  if (!strlen(format))
  {
    return(stringfn_new_empty_string());
  }

  va_list args_clone;
  va_copy(args_clone, args);

  int length = vsnprintf(NULL, 0, format, args);

  if (length < 0)
  {
    va_end(args_clone);
    return(NULL);
  }
  if (!length)
  {
    va_end(args_clone);
    return(stringfn_new_empty_string());
  }

  size_t length_size = (size_t)length;
  char   *buffer     = malloc(sizeof(char) * (length_size + 1));
  vsnprintf(buffer, length_size + 1, format, args_clone);
  buffer[length_size] = '\0';

  va_end(args_clone);

  return(buffer);
}


static char *_stringfn_clone_substring(const char *string, size_t start, size_t length)
{
  if (!length)
  {
    return(stringfn_new_empty_string());
  }

  char *target = malloc(sizeof(char) * (length + 1));

  for (size_t index = 0; index < length; index++)
  {
    target[index] = string[start + index];
  }

  target[length] = '\0';

  return(target);
}

static struct StringFNSubStringIndex _stringfn_get_substring_index(const char *string, int start, size_t length)
{
  struct StringFNSubStringIndex sub_string_index;

  sub_string_index.start  = 0;
  sub_string_index.end    = 0;
  sub_string_index.length = 0;
  sub_string_index.valid  = false;

  if (string == NULL)
  {
    return(sub_string_index);
  }

  size_t max_length          = strlen(string);
  int    unsigned_max_length = (int)max_length;
  size_t start_index         = 0;
  if (start > 0)
  {
    if (start >= unsigned_max_length)
    {
      return(sub_string_index);
    }
    start_index = (size_t)start;
  }
  else if (start < 0)
  {
    int value = unsigned_max_length + start;
    if (value < 0)
    {
      return(sub_string_index);
    }

    start_index = (size_t)value;
  }

  size_t end_index = start_index + length;
  if (end_index > max_length)
  {
    return(sub_string_index);
  }
  if (!length)
  {
    end_index = max_length;
  }

  sub_string_index.start  = start_index;
  sub_string_index.end    = end_index;
  sub_string_index.length = end_index - start_index;
  sub_string_index.valid  = true;

  return(sub_string_index);
} /* _stringfn_get_substring_index */


static char *_stringfn_trim(const char *string, bool trim_start, bool trim_end)
{
  if (string == NULL)
  {
    return(NULL);
  }

  size_t len = strlen(string);
  if (!len)
  {
    return(stringfn_new_empty_string());
  }

  size_t start = 0;
  if (trim_start)
  {
    bool found = false;
    for (size_t index = 0; index < len; index++)
    {
      if (!stringfn_is_whitespace(string[index]))
      {
        found = true;
        start = index;
        break;
      }
    }

    if (!found)
    {
      return(stringfn_new_empty_string());
    }
  }

  size_t end = len - 1;
  if (trim_end)
  {
    for (size_t index = len - 1; index >= start; index--)
    {
      if (!stringfn_is_whitespace(string[index]))
      {
        end = index;
        break;
      }
    }
  }

  len = end - start + 1;
  if (!len)
  {
    return(stringfn_new_empty_string());
  }

  char *trimmed = malloc(sizeof(char) * (len + 1));
  memcpy(trimmed, &string[start], len);
  trimmed[len] = '\0';

  return(trimmed);
} /* _stringfn_trim */

