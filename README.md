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
