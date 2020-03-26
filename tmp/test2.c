#include <stdio.h>

int	main()
{
	unsigned long long	llu;
	unsigned char			c;
	
	llu = (unsigned char)-1;
	printf("%llu\n", llu);
	llu = (c = (unsigned char)-1);
	printf("%llu\n", llu);
	return (0);
}
