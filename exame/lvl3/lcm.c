unsigned int lcm(unsigned int a, unsigned int b)
{
	int i;

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
		if(i % a == 0 && i % b == 0)
		{
			return i;
		}
		i++;
	}
}

#include <stdio.h>

int main()
{
    unsigned int a = 12;
    unsigned int b = 18;
    unsigned int result = lcm(a, b);
    printf("LCM of %u and %u is %u\n", a, b, result);
    return 0;
}

