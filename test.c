#include "main.h"
int main()
{
	int count;
	char *name = "Nora B";
	char c = 'N';


	count = _printf("My name is %s!\n", name);
	printf("Printed %d characters.\n", count);

	count = _printf("1234567890\n");
	printf("normaly 11 char are printed %d", count);
	count = _printf("single character C %c\n", c);
	printf("Printed %d characters.\n", count);

	_printf("testing double percentage %% ");
	printf("Printed %d characters.\n", count);

	return 0;
}
