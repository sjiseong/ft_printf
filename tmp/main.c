#include <stdio.h>
#include "includes/ft_printf.h"

int	main()
{
	int		i = 42;
	char	c = 42;
	short	s = 42;
	float	f = 12345.6789f;
	double	lf = 123456789123456789.123456789123456789;
	long double	Lf = 123456789123456789.123456789123456789L;
	unsigned long long int llu = 18446744073709551615U;
//	printf("%2$*d, %4$*d", 5, i, 10, i);
//	printf("e: %e\nf: %f\ng: %g\n", f, f, f);
//	printf("%o", i);
//	printf("%.1f", f); //For floating point numeric types, it specifies the number of digits to the right of the decimal point that the output should be rounded.
//	printf("%-2$-+10.5d", i);
//	printf("%2$*1$-d", 10, i);
//	printf("f : %f\nlf : %lf\nLf : %Lf\n", f, lf, Lf);
//	printf("%+20l10+30.5$+d, %i\n", 12345678, 10);
//	printf("%010%%hf\n", lf);
//	printf("%%%hf\n", lf);
//	printf("%llx\n", llu);
//	printf("%s\n", ft_ulltoa_base(42, 2));
//	printf("%010.5ua\n", i);
//	printf("%0 +-#10.5p\n", 546789);
//	printf("%0 +-#10.5x\n", 546789);
	printf("@moulitest: %#.0x %#5.0x", 0, 0);
	return 0;
}
