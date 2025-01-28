unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int i = 0;

	if(a == 0 || b == 0)
	{
		return 0;
	}
	if(a > b)
	{
		i = a;
	}
	else
	{
		i = b;
	}
	while(1)
	{
		if( i % a == 0 && i % b == 0)
		{
			return i;
		}
		i++;
	}
	return i;
}

#include <stdio.h>

int main()
{
	int a = 10;
	int b = 100;
	int r = lcm(a,b);
	printf("%d\n", r);
}
