#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *str, char c)
{
	while(*str)
	{
		if(*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return 0;
}

size_t ft_strspn(const char *s, const char *accept)
{
	int len = 0;

	while(s[len])
	{
		if(ft_strchr(accept, s[len]) == 0)
		{
			break;
		}
		len++;
	}
	return len;
}

#include <stdio.h>

int main()
{
	char str[] = "holaa , andas por aqui?";
	char c[] = "ola";
	int result = ft_strspn(str, c);
	int result1 = strspn(str, c);
	
	printf("%d\n", result);
	printf("%d\n", result1);
}

