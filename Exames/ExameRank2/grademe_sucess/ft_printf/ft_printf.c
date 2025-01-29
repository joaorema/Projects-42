#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char *str, int *len)
{
    if(!str)
        str = "(null)";
    while(*str)
        *len = *len + write(1, str++, 1);
}

void    ft_putnbr(int nb, int base, int *len)
{
    char *hex = "0123456789abcdef";
    unsigned int unb = 0;

    if(nb < 0 && base == 10)
    {
        *len = *len + write(1, "-", 1);
        unb = -nb;
    }
    else
        unb = (unsigned int)nb;
    if(unb >= (unsigned int)base)
        ft_putnbr((unb / base), base, len);
    *len = *len + write(1, &hex[(unb % base)], 1);
}

int     ft_printf(const char *type, ...)
{
    int i = 0;
    int len = 0;
    va_list(args);

    va_start(args, type);
    while(type[i])
    {
        if((type[i] == '%') && (type[i+1] != '\0'))
        {
            i++;
            if(type[i] == 's')
                ft_putstr(va_arg(args, char *), &len);
            else if(type[i] == 'd')
                ft_putnbr(va_arg(args, int), 10, &len);
            else if(type[i] == 'x')
               ft_putnbr(va_arg(args, int), 16, &len);
            else if(type[i] == '%')
                len = len + write(1, "%", 1);
        }
        else
            len = len + write(1, &type[i], 1);
        i++;
    }
    va_end(args);
    return len;
}
