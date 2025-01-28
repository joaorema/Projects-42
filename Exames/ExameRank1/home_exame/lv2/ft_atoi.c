int ft_atoi(const char *str)
{
	int i = 0;
	int r = 0;
	int sign = 1;

	while((str[i] >= 9 && str[i] <= 13) && (str[i] == 32))
	{
		i++;
	}
	if(str[i] == '-')
	{
		sign = -1;
	}
	while(str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * sign);
}

#include <stdio.h>
int main(int ac, char *av[])
{
	if(ac == 2)
	{
		printf("%d\n", ft_atoi(av[1]));
	}
	return 0;
}
		





