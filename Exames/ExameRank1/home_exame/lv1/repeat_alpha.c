#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;
	int r;

	if(ac == 2)
	{
		while(av[1][i])
		{
			r = 1;
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				r = av[1][i] + r - 'a';
			}
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				r = av[1][i] + r - 'A';
			}
			while(r)
			{
				write(1, &av[1][i], 1);
				r--;
			}
			i++;
		}
		
	}
	write(1, "\n", 1);
	return 0;
}
