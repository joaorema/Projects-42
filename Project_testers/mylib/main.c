/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:24:58 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/11/14 11:50:58 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <limits.h>

char sample_function(unsigned int i, char c)
	{
    	return c - 32;   /// change case
	}
	
int main (void)
{
	int og;
	int new;

	char ltr = 'C';
	
	printf("\n");
	printf("Testing ft_printc (char)\n");  /////////////////////////////////
	printf("\n");

	og = printf("Og printf : %c", ltr);
	printf("\n");
	new = ft_printf("my printf : %c", ltr);
	printf("\n");
	
	ltr = '\0';
	og = printf("Og printf : %c", ltr);
        printf("\n");
        new = ft_printf("my printf : %c", ltr);
        printf("\n");
	og = printf("Og printf : %c", '0' + 256);
        printf("\n");
        new = ft_printf("my printf : %c", '0' + 256);
        printf("\n");

	og = printf("Og printf : %c %c %c", '2', '1', 0);
        printf("\n");
        new = ft_printf("my printf : %c %c %c", '2', '1', 0);
        printf("\n");

	og = printf("Og printf : %c %c %c", ' ', ' ', ' ');
        printf("\n");
        new = ft_printf("my printf : %c %c %c", ' ', ' ', ' ');
        printf("\n");
   
        char *str = "space cow";
        printf("\n");
        printf("Testing ft_prints(string)\n");  ///////////////////////////////////////
        printf("\n");
        
        og = printf("Og printf : %s", str);
	printf("\n");
	new = ft_printf("my printf : %s", str);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	char long_str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        
        og = printf("Og printf : %s", long_str);
	printf("\n");
	new = ft_printf("my printf : %s", long_str);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
        
        
        char str2[] = " it's a trap!!! , run you fools.";
        
        og = printf("Og printf : %s", str2);
	printf("\n");
	new = ft_printf("my printf : %s", str2);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
        
        og = printf("Og printf : %s", "");
	printf("\n");
	new = ft_printf("my printf : %s", "");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

        char *hmm = NULL;
	
	og = printf("Og printf : %s", hmm);
	printf("\n");
	new = ft_printf("my printf : %s", hmm);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
        printf("\n");
	printf("Testing ft_printp (pointer)\n");  /////////////////////////////////////
	printf("\n");
	
	char *ptr = "c";
	og = printf("Og printf : %p", ptr);
	printf("\n");
	new = ft_printf("my printf : %p", ptr);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	char *hmm_ptr = NULL;
	og = printf("Og printf : %p", hmm_ptr);
	printf("\n");
	new = ft_printf("my printf : %p", hmm_ptr);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %p", (void *)-1);
	printf("\n");
	new = ft_printf("my printf : %p", (void *)-1);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %p", (void *)15);
	printf("\n");
	new = ft_printf("my printf : %p", (void *)15);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %p %p", (void *)0, (void *)0);
	printf("\n");
	new = ft_printf("my printf : %p %p", (void *)0, (void *)0);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printp (pointer) with long & int (min and max)");
	printf("\n");
	
	og = printf("Og printf : %p %p", (void *)INT_MIN, (void *)INT_MAX);
	printf("\n");
	new = ft_printf("my printf : %p %p", (void *)INT_MIN, (void *)INT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %p %p", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("\n");
	new = ft_printf("my printf : %p %p", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %p %p", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("\n");
	new = ft_printf("my printf : %p %p", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printd (Decimal base 10)\n");  /////////////////////////////////////
	printf("\n");

	printf("Testing ft_printd (Positive numbers)\n"); 
	
	
	int nbr1 = 42;
	
	og = printf("Og printf : %d", nbr1);
	printf("\n");
	new = ft_printf("my printf : %d", nbr1);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %d", INT_MAX);
	printf("\n");
	new = ft_printf("my printf : %d", INT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printd (Negative numbers)\n"); 
	
	int nbr2 = -42;
	
	og = printf("Og printf : %d", nbr2);
	printf("\n");
	new = ft_printf("my printf : %d", nbr2);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	int nbr3 = -1000000;
	
	og = printf("Og printf : %d", nbr3);
	printf("\n");
	new = ft_printf("my printf : %d", nbr3);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %d", -50000454);
	printf("\n");
	new = ft_printf("my printf : %d", -50000454);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %d", INT_MIN);
	printf("\n");
	new = ft_printf("my printf : %d", INT_MIN);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printd (Integer base 10)\n");  /////////////////////////////////////
	printf("\n");
	
	og = printf("Og printf : %i", 42);
	printf("\n");
	new = ft_printf("my printf : %i", 42);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printu (unsigned decimal base 10)\n");  //////////////////////////////
	printf("\n");
	
	og = printf("Og printf : %u", 42);
	printf("\n");
	new = ft_printf("my printf : %u", 42);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %u", 429496729u);
	printf("\n");
	new = ft_printf("my printf : %u", 429496729u);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	int nbr4 = -16;
	
	og = printf("Og printf : %u", nbr4);
	printf("\n");
	new = ft_printf("my printf : %u", nbr4);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	int nbr5 = -101;
	
	og = printf("Og printf : %u", nbr5);
	printf("\n");
	new = ft_printf("my printf : %u", nbr5);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %u", INT_MAX);
	printf("\n");
	new = ft_printf("my printf : %u", INT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %u", INT_MIN);
	printf("\n");
	new = ft_printf("my printf : %u", INT_MIN);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printx (Hexadecimal)\n");  //////////////////////////////
	printf("\n");
	
	unsigned nbr6 = 420;
	
	og = printf("Og printf : %x", nbr6);
	printf("\n");
	new = ft_printf("my printf : %x", nbr6);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", 17);
	printf("\n");
	new = ft_printf("my printf : %x", 17);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", 999999);
	printf("\n");
	new = ft_printf("my printf : %x", 999999);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", 4294967293u);
	printf("\n");
	new = ft_printf("my printf : %x", 4294967293u);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", 0);
	printf("\n");
	new = ft_printf("my printf : %x", 0);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", INT_MAX);
	printf("\n");
	new = ft_printf("my printf : %x", INT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", UINT_MAX);
	printf("\n");
	new = ft_printf("my printf : %x", UINT_MAX);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_printx (Negative numbers)\n"); 
	
	og = printf("Og printf : %x", -100);
	printf("\n");
	new = ft_printf("my printf : %x", -100);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", -17);
	printf("\n");
	new = ft_printf("my printf : %x", -17);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %x", INT_MIN);
	printf("\n");
	new = ft_printf("my printf : %x", INT_MIN);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");	
	
	og = printf("Og printf : %x", -150);
	printf("\n");
	new = ft_printf("my printf : %x", -150);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Testing ft_print (Percent sign)\n");  //////////////////////////////
	printf("\n");
	
	og = printf("Og printf : %%");
	printf("\n");
	new = ft_printf("my printf : %%");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %% %%");
	printf("\n");
	new = ft_printf("my printf : %% %%");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	og = printf("Og printf : %% %% %%");
	printf("\n");
	new = ft_printf("my printf : %% %% %%");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Test (multiple letters)\n");  //////////////////////////////
	printf("\n");

	og = printf("Og printf : %%%s %%%s %%%d %x", "teste1", "teste2", 18, 520);
	printf("\n");
	new = ft_printf("my printf : %%%s %%%s %%%d %x", "teste1", "teste2", 18, 520);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Test (if string ends with percentage sign)\n");  //////////////////////////////
	printf("\n");
	ft_printf("tamanho : %d\n",ft_printf("%"));
	printf("\n");
	og = printf("Og printf : %%%s %%%s %%%d %d", "teste1", "teste2 %", 18, 520);
	printf("\n");
	new = ft_printf("my printf : %%%s %%%s %%%d %d", "teste1", "teste2 %", 18, 520);
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");
	
	printf("\n");
	printf("Test ft_strlen\n");  //////////////////////////////
	const char *str6 = "ola bem vindos";
	
	printf("\n");
	size_t length = ft_strlen(str6);
    	printf("Length of '%s': %zu\n", str6, length);
    	printf("\n");
    	
    	printf("Test ft_strncmp\n");  //////////////////////////////
	printf("\n");
    	const char *str7 = "Hello, world!";
    	const char *str8 = "Hello, 42!";
    	size_t n = 10;
	
    	int result = ft_strncmp(str7, str8, n);
    	printf("1st - Hello, world! | 2nd - Hello, 42!\n");
    	printf("Comparison result: %d\n", result); 
    	
	printf("\n");
	printf("Test ft_memcpy\n");  //////////////////////////////
	printf("\n");
	
	char src[] = "Hello, world!";
    	char dest[20];
	
	printf("Original source : Hello, world!\n");
    	ft_memcpy(dest, src, 13);
    	printf("The new one : %s\n", dest); 
	
	
	printf("\n");
	printf("Test ft_itoa\n");  //////////////////////////////
	printf("\n");
	
	int number1 = -12345;
    	char *str9 = ft_itoa(number1);
    	printf("Valor : -12345 \n");
    	printf("ft_itoa : %s\n", str9);
    	free(str9);

	printf("\n");
	printf("Test ft_memchr\n");  //////////////////////////////
	printf("\n");
	
	char str10[] = "Hello, world!";
    	char *result3 = ft_memchr(str10, 'o', 13);
    	char *result4 = ft_memchr(str10, 'd', 13);
    	printf("Original string : Hello, world! | We are going to look for the letter o and next letter d\n");
        printf("Found 'o' at position: %ld\n", result3 - str10);
   	printf("Found 'd' at position: %ld\n", result4 - str10);
	
	printf("\n");
	printf("Test ft_strnstr\n");  //////////////////////////////
	printf("\n");
	
	const char *big = "Hello, world";
    	const char *little = "world";
    	size_t len6 = 12;

    	char *result5 = ft_strnstr(big, little, len6);
    	printf("String : Hello, world | Substring is : world\n");
    	printf("Found substring: %s\n", result5);
    	
    	printf("\n");
	printf("Test ft_strmapi\n");  //////////////////////////////
	printf("\n");
	
	
    	const char *str11 = "hello";
    	char *result6 = ft_strmapi(str11, sample_function);
    	printf("Gonna turn the letters to uppercase letters\n");
    	printf("hello becomes : %s\n", result6);

	printf("\n");
	printf("Test ft_split | It's a trap!!!\n");  //////////////////////////////
	printf("\n");

	char *s = "   It's a trap!!!   ";
	char **v = ft_split(s, ' ');
	while(*v)
	{
	printf("%s\n", *v++);
	}
	
	printf("\n");
	printf("Test get_next_line | 3 lines from test file\n");  //////////////////////////////
	printf("\n");
	
	 int fd = open("test.txt", O_RDONLY);
    	if (fd == -1)
    	{
        perror("Error opening file");
        return 1;
   	}

    	char *line;
    	while ((line = get_next_line(fd)) != NULL)
   	{
        printf("%s", line);
        free(line);
    	}

    	close(fd);
    	return 0;
}

	





