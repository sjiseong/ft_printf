#include <stdio.h>
#include <stdarg.h>

int	test(char *last, ...)
{
	va_list ap;

	va_start(ap, last);
	char	c = va_arg(ap, char);
	char	*s = va_arg(ap, char*);
	long long int	lld = va_arg(ap, long long);
	int		i2 = va_arg(ap, int);
	va_end(ap);
	printf("%c, %s, %lld, %d\n", c, s, lld, i2);
	return (0);
}

int	main()
{
//	printf("sizeof : int %lu, long %lu, longlong %lu, double %lu, long double %lu, va_list %lu\n", 
//			sizeof(int), sizeof(long), sizeof(long long), sizeof(double), sizeof(long double), sizeof(va_list));
	long long int lld = 1234567891234567891;
	char *str = "Hello World";
	char *s = "FUCk the printf";
	test(str, 'a', s, lld, 242424);
	return (0);
}
