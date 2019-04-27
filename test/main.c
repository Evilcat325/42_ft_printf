#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main()
{
	printf("%d\n",  ft_printf("%hU", 4294967296UL));
	// ft_printf("%x", 42);
	return 0;
}
