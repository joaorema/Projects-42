#include <unistd.h>

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
int ft_atoi(char *str)
{
	int i = 0;
	int r = 0;
	while(str[i])
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return r;
}

int main(int ac, char *av[])
{
	if(ac < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	if(ac == 2)
	{
		int nb = ft_atoi(av[1]);
		int i = 1;

		while(i <= 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(i * nb);
			write(1, "\n", 1);
			i++;
		}
	}
	return 0;
}
