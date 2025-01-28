int ft_isdigit(int c)
{
	return((c >= '0') && (c <= '9'));
}

int ft_islower(int c)
{
	return((c >= 'a') && (c <= 'z'));
}

int ft_isupper(int c)
{
	return((c >= 'A') && (c <= 'Z'));
}

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int r = 0;
	int sign = 1;

	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while(str[i])
	{
		r = r * str_base;
		if(ft_isdigit(str[i]))
		{
			r = r + (str[i] - '0');
		}
		else if(ft_islower(str[i]))
		{
			r = r + (str[i] - 87);
		}
		else if(ft_isupper(str[i]))
		{
			r = r + (str[i] - 55);
		}
		i++;
	}
	return ( r * sign);
}


#include <stdio.h>

int main(void)
{
    const char *str = "1A";
    int base = 16;
    int result = ft_atoi_base(str, base);
    printf("The result is: %i\n", result);
    return 0;
}

