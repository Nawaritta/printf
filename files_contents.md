#printf.c

* cleanup - cleans up for _printf.

* run_printf - checks the format string for printf function.

* _printf - prints a formatted string.


#modifiers.c

* print_width -  width modifier.

* print_string_width - contains the leading spaces to a buff for a width mod

* print_neg_width - Stores trailing space.


#memory_helper.c

* _memcpy - Copies n bytes from memory area src to

* the buffer contained in a buffer_t struct.

* free_buffer - frees the buffer of the buffer_t struct.

* init_buffer - Initializes a variable of struct type buffer_t.


#handlers.c

* handle_flags - Matches flags with corresponding values.

* handle_length - Matches length modifiers with their corresponding value.

* handle_width - Matches a width modifier with its corresponding value.

* handle_precision - Matches a precision modifier with its corresponding value.

* handle_specifiers - This function pointer takes a format specifier character
  and returns a pointer to a function that handles the specifier.


#convert_strings.c

* convert_s - Converts an argument to a string and stores it to a buffer
  contained in a struct.

* convert_S - Converts an argument to a string and stores it to a buffer
  contained in a struct.

* convert_r - Reverses a string and stores it to a buffer contained in a struct.

* convert_R - Converts a string to ROT13 and stores it to a buffer contained in
  a struct.


#convert_numbers.c

* convert_di - Converts an argument to a signed int and stores it to a buffer
  contained in a struct.

* convert_b - Converts an unsigned int argument to binary and stores it to a
  buffer contained in a struct.

*convert_o - Converts an unsigned int to octal and stores it to a buffer
 contained in a struct.

* convert_u - Converts an unsigned int argument to decimal and stores it to
  a buffer contained in a struct.


#base_converters.c

* convert_sbase - Converts a signed long to an inputted base and stores

* convert_ubase - Converts an unsigned long to an inputted base and stores
 the result to a buffer contained in a struct.



#convert_c_percent.c


* convert_c - Converts an argument to an unsigned char and stores it to a buffer
  contained in a struct.

* convert_percent - Stores a percent sign to a buffer contained in a struct.

* convert_p - Converts the address of an argument to hex and stores it to a
  buffer contained in a struct.


#convert_hex.c


* convert_x - Converts an unsigned int argument to hex using abcdef and stores
 it to a buffer contained in a struct.

* convert_X - Converts an unsigned int argument to hex using ABCDEF and stores
 it to a buffer contained in a struct.
