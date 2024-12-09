#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int lower;
	int upper;
	if(ac == 2)
	{
		while(av[1][i])
		{
			lower = ('a' + 'z') - av[1][i];
			upper = ('A' + 'Z') - av[1][i];
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				write(1, &lower, 1);
			}
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				write(1, &upper, 1);
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
