#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int nb1;
	int nb2;

	nb1 = atoi(argv[1]);
	nb2 = atoi(argv[2]);
	if(argc == 3)
	{
		if(nb1 > 0 && nb2 > 0)
		{
			while(nb1 != nb2)
			{
				if(nb1 > nb2)
				{
					nb1 = nb1 - nb2;
				}
				else
				{
					nb2 = nb2 - nb1;
				}
			}
			printf("%d", nb1);
		}
	}
	printf("\n");
	return 0;
}
