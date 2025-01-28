#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>  // for testing return values

void ft_putstr(char *str, int *len)
{
    if(!str)
        str = "(null)";
    while(*str)
        *len = *len + write(1, str++, 1);
}
void ft_putnbr(int nb, int base, int *len)
{
    char *hex = "0123456789abcedf";

    if(nb < 0)
    {
        write(1, "-", 1);
        len++;
        nb = -nb;
    }
    if(nb >= base)
        ft_putnbr((nb / base), base, len);
    *len = *len + write(1, &hex[nb % base], 1);
}

int ft_printf(const char *type, ...)
{
    va_list args;
    int i = 0;
    int len = 0;

    va_start(args, type);
    while(type[i])
    {
        if((type[i] == '%') && (type[i + 1] != '\0'))
        {
            i++;
            if(type[i] == 's')
                ft_putstr(va_arg(args, char *), &len);
            else if(type[i] == 'd')
                ft_putnbr(va_arg(args, int), 10, &len);
            else if(type[i] == 'x')
                ft_putnbr(va_arg(args, int), 16, &len);
        }
        else
        {
            len = len + write(1, &type[i], 1);
        }
        i++;
    }
    va_end(args);
    return len;
}

int main()
{
    char *teste = NULL;
    char *teste1 = "lets test len!";
    int og = 0;
    int mine = 0;

    ft_printf("1* Test:\n");
    ft_printf("%s\n", "toto");
    ft_printf("\n");

    ft_printf("2* Test:\n");
    ft_printf("Magic %s is %d\n", "number", 2);
    ft_printf("\n");

    ft_printf("3* Test:\n");
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    ft_printf("\n");

    ft_printf("4* Test:\n");
    ft_printf("A Null string : %s\n", teste);
    ft_printf("\n");

    mine = ft_printf("5* Test: %s\n", teste1);
    og = printf("5* Test: %s\n", teste1);
    ft_printf("The len of my ft: %d\n", mine);
    ft_printf("The len of orignal: %d\n", og);

}