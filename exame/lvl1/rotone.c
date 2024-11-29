#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int mvup;
	int swap;
	i = 0;
	if(argc == 2)
	{
		while(argv[1][i])
		{
			mvup = argv[1][i] + 1;
			swap = argv[1][i] - 25;
			if((argv[1][i] >= 'a' && argv[1][i] <= 'x')
					|| (argv[1][i] >= 'A' && argv[1][i] <= 'X'))
			{
				write(1, &mvup, 1);
			}
			else if(argv[1][i] == 'z' || argv[1][i] == 'Z')
			{
				write(1, &swap, 1);
			}
			else
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}

