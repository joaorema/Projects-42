#include <unistd.h>

int ft_atoi(char *str)
{
	int r = 0;
	int i = 0;
	int sign = 1;

	while((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
	{
		i++;
	}
	if(str[i] == '-')
	{
		sign = -1;
	}
	if(str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (sign * r);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if(nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if(nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
}

int main(int argc, char *argv[])
{
	int i;
	int nbr;

	if(argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		i = 1;
		if(nbr < 0)
		{
			return 0;
		}
		while(i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}




