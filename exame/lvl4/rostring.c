#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int start;
	int end;
	int flag;
	char *str;

	if(ac < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	if(ac > 1)
	{
		i = 0;
		flag = 0;
		str = av[1];
		while((str[i]) && (str[i] == ' ' || str[i] == '\t'))
		{
			i++;
		}
		start = i;
		while(str[i] && str[i] != ' ' && str[i] != '\t')
		{
			i++;
		}
		end = i - 1;
		while((str[i]) && (str[i] == ' ' || str[i] == '\t'))
		{
			i++;
		}
		if(str[i])
		{
			while(str[i])
			{
				if(str[i] == ' ' || str[i] == '\t')
				{
					while(str[i] == ' ' || str[i] == '\t')
					{
						i++;
						flag++;
					}
					
				}
				else
				{
					if(flag)
					{
						write(1, " ", 1);
					}
					write(1, &str[i++], 1);
					flag = 0;
				}
			}
			write(1, " ", 1);
			
		}
		while(start <= end)
		{
			write(1, &str[start++], 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}
