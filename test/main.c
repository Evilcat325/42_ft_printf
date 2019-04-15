#include "ft_printf.h"
#include "libft.h"

int main()
{
	void *ptr;
	double d = 5.123456781234567;
	float f = 5.1234567;
	int i = 5;

	ft_printf("");
	ft_printf("%%");
	ft_printf("test \n");
	ft_printf("test %c\n", 'c');
	ft_printf("test %p\n", ptr);
	ft_printf("test %s\n", "a string");
	ft_printf("test %d\n", d);
	ft_printf("test %i\n", i);
	return 0;
}
