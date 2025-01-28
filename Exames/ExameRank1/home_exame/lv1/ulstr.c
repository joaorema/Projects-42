#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int lup;
	int ldown;

	if(ac == 2)
	{
		while(av[1][i])
		{
			lup = av[1][i] - 32;
			ldown = av[1][i] + 32;
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				write(1, &lup, 1);
			}
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				write(1, &ldown, 1);
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
