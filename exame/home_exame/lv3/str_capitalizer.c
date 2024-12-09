#include <unistd.h>

void cap(char *str)
{
	int i = 0;
	
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	i = 0;
	while(str[i])
	{
		if((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\0'))
		{
			str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char *av[])
{
	if(ac < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	if(ac > 1)
	{
		int i = 1;
		int last = (ac - 1);
		while(i <= last)
		{
			cap(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return 0;
}
		
