char *ft_strrev(char *str)
{
	int i = 0;
	char temp;
	int len = 0;

	while(str[len])
	{
		len++;
	}
	len = len - 1;
	while(i < len - i)
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
	}
	return str;
}
#include <stdio.h>
int main()
{
	char str1[] = "iehnag";
	printf("%s\n", ft_strrev(str1));
}


