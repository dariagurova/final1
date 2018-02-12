#include "./printf.h"

int	main(void)
{
	printf("%04.2i\n", 42);
	ft_printf("%04.2i\n", 42);

	printf("%04.3i\n", 42);
	ft_printf("%04.3i\n", 42);

	printf("%-7.3i\n", 42);
	ft_printf("%-7.3i\n", 42);

	printf("%06.3i\n", 42);
	ft_printf("%06.3i\n", 42);
	return (0);
}
