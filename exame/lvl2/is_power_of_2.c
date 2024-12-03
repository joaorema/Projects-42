int is_power_of_2(unsigned int n)
{
	if(n == 0)
	{
		return 0;
	}
	return (n & (n - 1)) == 0;
}

#include <stdio.h>

int main()
{
	int teste = 1;
	int result = is_power_of_2(teste);
	printf("%i\n", result);
}
