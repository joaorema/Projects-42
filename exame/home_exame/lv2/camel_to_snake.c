#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int ldown;
	if(ac == 2)
	{
		while(av[1][i])
		{
			ldown = av[1][i] + 32; 
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				write(1, &av[1][i], 1);
			}
			if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				write(1, "_", 1);
				write(1, &ldown, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}	
