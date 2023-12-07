## CHANGELOG

### v0.1.6 (2023-12-07)

* New stringfn_clone_or_null function
* Updated header include guard macro name

### v0.1.5 (2022-01-30)

* Fix possible leak in stringfn_vformat
* Added static to internal functions
* Adding lint checks as part of build

### v0.1.4 (2021-08-11)

* New stringfn_format and stringfn_vformat functions.
* Added void to no arg functions
* Added cargo-make makefile for simpler sharing of optional development build instructions.

### v0.1.3 (2021-02-15)

* Fixed memory access issue in split function for empty strings.

### v0.1.2 (2020-12-05)

* New stringfn_is_digits function.
* New stringfn_is_ascii function.
* New stringfn_substring function.
* New stringfn_mut_substring function.

### v0.1.1 (2020-11-29)

* New stringfn_split_lines function.
* New stringfn_split_lines_and_trim function.
* New stringfn_split_words function.
* New stringfn_equal function.
* New stringfn_is_whitespace function.
* All trim functions remove all whitespace types characters including: tab, eol and cr.
* New stringfn_release_strings_struct function.
* New stringfn_new_empty_string function.

### v0.1.0 (2020-11-29)

* Initial release
