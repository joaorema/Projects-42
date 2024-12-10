#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	int i;
	int nb;
	if(ac == 2)
	{
		nb = atoi(av[1]);
		i = 1;
		if(nb == 1)
		{
			printf("1\n");
			return 0;
		}
		while(nb >= i++)
		{
			if(nb % i == 0)
			{
				printf("%d", i);
				if(i == nb)
				{
					break;
				}
				printf("*");
				nb = nb / i;
				i = 1;
			}
		}
	}
	printf("\n");
	return 0;
}

