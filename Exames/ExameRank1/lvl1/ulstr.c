#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int mvup;
	int mvdown;

	i = 0;

	if(argc == 2)
	{
		while(argv[1][i])
		{
		 mvup = argv[1][i] - 32;
               	 mvdown = argv[1][i] + 32;
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				write(1, &mvup, 1);
			}
			else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				write(1, &mvdown, 1);
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
