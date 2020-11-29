#ifndef __STRINGFN_H__
#define __STRINGFN_H__

#include <stdbool.h>
#include <stdlib.h>

struct StringFNStrings
{
  char **strings;
  int  count;
};

/**
 * Returns new dynamically allocated empty string.
 * Once done, this char array must be released.
 */
char *stringfn_new_empty_string();

/**
 * Returns true if both strings are equal.
 * If any string is NULL, false will be returned.
 */
bool stringfn_equal(const char *, const char *);

/**
 * Returns true if the provided prefix is found at the start of the given string.
 */
bool stringfn_starts_with(const char * /* string */, const char * /* prefix */);

/**
 * Returns true if the provided suffix is found at the end of the given string.
 */
bool stringfn_ends_with(const char * /* string */, const char * /* suffix */);

/**
 * Returns true if the char is a whitespace char: space, EOL, CR.
 */
bool stringfn_is_whitespace(char);

/**
 * Trims all whitespaces and returns a new char array.
 * Once done, this char array must be released.
 */
char *stringfn_trim(const char *);

/**
 * Trims all starting whitespaces and returns a new char array.
 * Once done, this char array must be released.
 */
char *stringfn_trim_start(const char *);

/**
 * Trims all ending whitespaces and returns a new char array.
 * Once done, this char array must be released.
 */
char *stringfn_trim_end(const char *);

/**
 * Trims all whitespaces by modifying the provided char array.
 */
char *stringfn_mut_trim(char *);

/**
 * Trims all starting whitespaces by modifying the provided char array.
 */
char *stringfn_mut_trim_start(char *);

/**
 * Trims all ending whitespaces by modifying the provided char array.
 */
char *stringfn_mut_trim_end(char *);

/**
 * Converts all ascii chars to uppercase and returns a new char array.
 * Once done, this char array must be released.
 */
char *stringfn_to_uppercase(const char *);

/**
 * Converts all ascii chars to lowercase and returns a new char array.
 * Once done, this char array must be released.
 */
char *stringfn_to_lowercase(const char *);

/**
 * Modifies the provided array and converts all ascii chars to uppercase.
 */
void stringfn_mut_to_uppercase(char *);

/**
 * Modifies the provided array and converts all ascii chars to lowercase.
 */
void stringfn_mut_to_lowercase(char *);

/**
 * Removes all chars taken from the search value and are found in the
 * input string and returns a new string without them.
 * Once done, this char array must be released.
 */
char *stringfn_remove(char * /* string */, char * /* search */);

/**
 * Creates a new char array with the source char value replaced by the target char.
 * Once done, this char array must be released.
 */
char *stringfn_replace(const char *, char /* source */, char /* target */);

/**
 * Modifies the provided array and the source char value with the target.
 */
void stringfn_mut_replace(char *, char /* source */, char /* target */);

/**
 * Joins all provided char arrays into a new single char array seperated by the
 * provided separator.
 * If the separator is NULL, it will behave as empty string.
 * Once done, this char array must be released.
 */
char *stringfn_join(char ** /* strings */, char * /* separator */, size_t /* start_index */, size_t /* count */);

/**
 * Concats all provided char arrays into a new single char array.
 * Once done, this char array must be released.
 */
char *stringfn_concat(char ** /* strings */, size_t /* start_index */, size_t /* count */);

/**
 * Splits the provided string into a new string array of newly allocated strings.
 * Once done, the strings array and strings must be released.
 */
struct StringFNStrings stringfn_split(char *, char);

/**
 * Splits the provided string into a new string array of newly allocated strings per line.
 * Once done, the strings array and strings must be released.
 */
struct StringFNStrings stringfn_split_lines(char *);

/**
 * Splits the provided string into a new string array of newly allocated strings per line.
 * Each line will be trimmed.
 * Once done, the strings array and strings must be released.
 */
struct StringFNStrings stringfn_split_lines_and_trim(char *);

/**
 * Release utility function.
 */
void stringfn_release_strings_struct(struct StringFNStrings);

#endif

