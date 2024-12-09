#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int mvup;
	int mvdown;
	if(ac == 2)
	{
		while(av[1][i])
		{
			mvup = av[1][i] + 13;
			mvdown = av[1][i] - 13;
			if((av[1][i] >= 'a' && av[1][i] <= 'm') || (av[1][i] >= 'A' && av[1][i] <= 'M'))
			{
				write(1, &mvup, 1);
			}
			else if((av[1][i] >= 'n' && av[1][i] <= 'z') || (av[1][i] >= 'N' && av[1][i] <= 'Z'))
			{
				write(1, &mvdown, 1);
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
