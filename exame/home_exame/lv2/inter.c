#include <unistd.h>

int main(int ac, char *av[])
{
	unsigned char check[256] = {0};
	int i;
	int j;

	if(ac == 3)
	{
		i = 0;
		while(av[1][i])
		{
			j = 0;
			while(av[2][j])
			{
				if(av[1][i] == av[2][j])
				{
					if(check[(unsigned char)av[1][i]] == '\0')
					{
						write(1, &av[1][i], 1);
						check[(unsigned char)av[1][i]] = 1;
					}
					break;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
