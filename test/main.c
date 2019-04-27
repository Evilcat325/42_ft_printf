#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

#define TEST(x) ret = ft_printf(x); printf("%d\n", ret)
#define TEST2(x, y) ret = ft_printf(x, y); printf("%d\n", ret)

int main()
{
	void *ptr;
	double d = 5.123456781234567;
	float f = 5.1234567;
	int i = 5;
	int ret = 0;

	// TEST("");
	// TEST("%%");
	// TEST("test \n");
	// TEST2("test %c\n", 'c');
	// TEST2("test %p\n", ptr);
	// TEST2("test %s\n", "a string");
	// TEST2("test %d\n", d);
	// TEST2("test %i\n", i);
	// ft_printf("%#x\n", 42);
	// ft_printf("%#x\n", 42);
	// ft_printf("%s", "abc");
	// printf("%d\n", ft_printf("%5%"));
	printf("%d\n", ft_printf("%.2c", NULL));

	return 0;
}
