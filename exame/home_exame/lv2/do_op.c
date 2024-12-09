#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[])
{
	int str1;
	int str2;

	if(ac != 4)
	{
		write(1, "\n", 1);
		return 0;
	}
	if(ac == 4)
	{
		str1 = atoi(av[1]);
		str2 = atoi(av[3]);
		if(av[2][1] == '\0')
		{
			if(av[2][0] == '+')
			{
				printf("%d\n", (str1 + str2));
			}
			if(av[2][0] == '-')
			{
				printf("%d\n", (str1 - str2));
			}
			if(av[2][0] == '*')
                        {
                                printf("%d\n", (str1 * str2));
                        }
			if(av[2][0] == '/')
                        {
                                printf("%d\n", (str1 / str2));
                        }
			if(av[2][0] == '%')
                        {
                                printf("%d\n", (str1 % str2));
                        }
		}
	}
	
	
}
