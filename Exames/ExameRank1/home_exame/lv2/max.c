int max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int r = 0;

	if(len == 0)
	{
		return 0;
	}
	r = tab[i];
	while(i < len)
	{
		if(r < tab[i])
		{
			r = tab[i];
		}
		i++;
	}
	return r;
}

#include <stdio.h>

int main()
{
	int tab[7] = {2, 5, 1, 25, 2, 33, 6};
	printf("%d\n", max(tab, 5));
	printf("%d\n", max(tab, 7));
}
