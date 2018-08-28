# CPP_Command_Line_Utility

The goal of this project is to create a small library that will allow a
programmer to:
  1) Establish a set of valid command line options,
  2) Process and validate command line options supplied by a user,
  3) Allow the programmer to supply handling for valid command line options.

For testing purposes, the main function will be a simple file management
utility that allows a user to append to or overwrite files either with text
given on the command line or with files.

Here I conceptualize command line arguments in two categories: values and
options. A value can be considered simply as a string literal as supplied by
the user on the command line. Though it may ultimately be meant as an integer
or a double or some other data type, it need only be considered as a string
for purposes of processing the command line arguments.

An option is a string which begins either with '-' or '--'. The determination
of which prefix will be used should be made when the program instantiates the
object that processes the command line arguments. An option can have zero or
more values immediately following it. An option can also have zero or more
options.

The command line should be conceptualized as a sequence of argument trees.
Values are always leaf nodes in the trees. Arguments which are invalid will be
ignored. An invalid argument is an argument which violates the rules
established by the program for arguments.

There are three phases of command line processing:

1) First, the programmer establishes a set of valid arguments for the program.
2) Second, at runtime, command line arguments are processed and a sequence of
   valid argument trees is created.
3) Third, the sequence of valid argument trees is passed on to the handler
   provided by the programmer.

It should be possible for the programmer to supply error messages for invalid
arguments.

There are several important items to note.

First, values which are not required for specific options are required for the
program as a whole. For both types of values, if they are expected, the
programmer must specify where they should appear relative to the option. This
should be given in terms of an offset index. The default is 1 which means that
the expected value should be the argument immediately following the option or
the program name (argument 0 on the command line).

Second, because options may themselves have options, each option will have a
set data structure just like the main program.

Third, the programmer should work only with the Command Line Operation (CLO)
class using some standard operations such as adding an option or expected value
to the set of valid arguments.

The standard set-up operations of the CLO class include:

bool add_expected_value(string,size_t) : returns true if successful. Throws
appropriate error otherwise. Expects a string indicating the existing option to
which the expected value should be added, otherwise main program is assumed
vis-a-vis overloading. Expects a size_t which indicates where the expected
value should be located in a command line. Class maintains a size_t which is
incremented whether an argument is supplied or not.

bool add_optional_value(string,size_t) : returns true if successful. Throws
appropriate error otherwise. Similar to previous, but value is only assessed if
the argument at the given location (size_t) is not an option. This means that
if the argument at the assumed location has the option prefix ('-' or '--'),
then it is assumed that the user has not supplied the optional value. Note that
the class will not allow the programmer to have more that one value at the same
location

bool add_option(string) : returns true if successful. Throws appropriate error
otherwise. This simply adds an option to the set of options for the CLO. It
will not allow duplicates.

Option &get_option(string) : returns an option reference. Since options can be
added to options, this method gives the programmer access to options within the
CLO. It can also be called on options themselves to access their existing
options. Does not create new option if given option does not exist. Note that
options are identified without the prefix.

bool set_prefix_single() : returns true if successful. Throws appropriate error
otherwise. Tells CLO to read a string prefixed with a single minus sign as an
option.

bool set_prefix_double() : returns true if successful. Throws appropriate error
otherwise. Tells CLO to read a string prefixed with two minus signs as an
option.

bool set_prefix_both() : returns true if successful. Throws appropriate error
otherwise. Tells CLO to read a string prefixed with either a single minus sign
or two minus signs as an option.

Errors:

UnknownOption() : thrown when an option is not in the relevant option set
ExpectedValueMissing() : thrown when an expected value is not found
UnassociatedValue() : thrown when a non-option argument is found with no
                    association to an option or to the program
Note: Any argument regardless of prefix in the position of an expected value is
read as a value.

The standard processing operations of the CLO class include:

bool get_command_line(int,char**) : returns true if successful. Throws
appropriate error otherwise. This sets the internal state of the CLO object to
read from the main program's command line arguments. Expects the standard argc
and argv as parameters.

bool process_command_line() : returns true if reaches end of command line
arguments. Throws appropriate error otherwise. This creates the internal valid
argument sequence. If an error is thrown, the internal state of the iterators
is preserved, allowing the program to continue the process from the next
argument, if the last argument has not been reached. Expects argc and argv from
the command line. Call the method again to continue the operation after an
error is thrown.

Argument get_next_argument() : returns a copy of the next argument in the
sequence of valid arguments generated from the process_command_line method.
Note that until process_command_line has finished, get_next_argument cannot be
called.
