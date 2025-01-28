#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int j;

	if(ac == 3)
	{
		i = 0;
		j = 0;
		while(av[1][i] && av[2][j])
		{
			if(av[1][i] != av[2][j])
			{
				j++;
			}
			else
			{
				i++;
			}
		}
		if(av[1][i] == '\0')
		{
			write(1, "1", 1);
		}
		else
		{
			write(1, "0", 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}
