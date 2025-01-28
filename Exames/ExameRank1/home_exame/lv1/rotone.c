#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int lup;
	int z;

	if(ac == 2)
	{
		while(av[1][i])
		{
			lup = av[1][i] + 1;
			z = av[1][i] - 25;
			if((av[1][i] >= 'a' && av[1][i] <= 'y') || (av[1][i] >= 'A' && av[1][i] <= 'Y'))
			{
				write(1, &lup, 1);
			}
			else if(av[1][i] == 'z' || av[1][i] == 'Z')
			{
				write(1, &z, 1);
			}
			else
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
