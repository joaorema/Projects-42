/* you can copy the content to your ft_printf.c file and compile */

#include <stdio.h>
#include <limits.h>

int main (void)
{
	int og;
	int new;

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

	og = printf("Og printf : %s %s", "-", "4");
	printf("\n");
	new = ft_printf("my printf : %s %s", "-", "4");
	printf("\n");
	printf("Len og = %d", og);
	printf("\n");
	ft_printf("Len ft = %d", new);
	printf("\n");

    og = printf("Og printf : %s %s%s", "-", "4", "2");
	printf("\n");
	new = ft_printf("my printf : %s %s%s", "-", "4", "2");
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

}
