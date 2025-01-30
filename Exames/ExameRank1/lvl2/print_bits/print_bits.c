#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while(i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int print;

	if(argc == 2)
	{
		print = atoi(argv[1]);
		print_bits(print);
	}
	printf("\n");
	return 0;
}
