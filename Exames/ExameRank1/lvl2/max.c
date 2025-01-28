int max(int *tab, unsigned int len)
{
	int max = 0;
	unsigned int i = -1;

	while(++i < len)
	{
		if(tab[i] > max)
		{
			max = tab[i];
		}

	}
	return max;
}
#include <stdio.h>
int main()
{
	int array[5] = {10, 5, 15, 25, 3};
	int r = 5;
	int value;

	value = max(array, r);
	printf("%d\n", value);
}

