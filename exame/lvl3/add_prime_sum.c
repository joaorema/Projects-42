#include <unistd.h>

int is_prime(int nb)
{
	int i = 2;
	if(nb == 0)
	{
		return 0;
	}
	while( i * i <= nb)
	{
		if(nb % i == 0)
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int ft_atoi(char *str)
{
	int r = 0;
	int i = 0;
	
	while(str[i])
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return r;
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

int main(int ac, char *av[])
{
	
	int nb = 0;
	int r = 0;

	if(ac == 2)
	{
		nb = ft_atoi(av[1]);
		if(nb < 0)
		{
			write(1, "0\n", 2);
               	 	return 0;
		}
		while(nb > 1)
		{
			if(is_prime(nb))
			{
				r = r + nb;
			}
			nb--;
		}
		ft_putnbr(r);
		write(1, "\n", 1);
		return 0;
	}
	if(ac != 2)
	{
		write(1, "0\n", 2);
		return 0;
	}
	
}
