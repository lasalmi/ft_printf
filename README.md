# The project

Hive Helsinki project ft_printf is a project where we need to recode the famous printf function without certain features.

### What I learned from this project

When this project started I hit an analysis paralysis for the first month. I tried to solve all the problems in advance and in order to break
the paralysis I just started coding without having a plan the project. The code became a mess, but it was a an important lesson 
about taking your time to get to know the actual problem and devising an architecture/plan for your project, because the debugging and
addition of new features in the future would be a struggle without. This project is also the first project where I implemented states in
which the function would run.

## Installation

Clone the repository

In the cloned repository to clone the submodule libft:

git submodule init

git submodule update --recursive --remote

make to create the libftprintf.a library in the root of the repository.

Include the header ft_printf.h and compile with the library.

## Usage

#### Flags

'#' - Alternate form printing

'-' - Left adjustment of the given field

'+' - Sign to always be printed when using signed formats

' ' - A space to left before a positive number when printing a signed format. '+' overrides this flag.

'0' - Zero padding to be used instead of blank-padding. '-' overrides this flag.

#### Field width

Optional digit string to specify a minimum field width that pads the output to meet the minimum requirement. Doesnt truncate the output.

#### Precision

Optional period '.' followed by a digit string to specify the digits to be printed after the decimal point or the maximum number of bytes
to be printed of a string.

#### Supported conversions:

%c - Character

%s - String

%d and %i - Signed decimal

%o - Unsigned octal

%u - Unsigned decimal

%x and %X - Unsigned hexadecimal

%f and %F - Floating point, if no precision is given the preicision of 6 is used by default.
