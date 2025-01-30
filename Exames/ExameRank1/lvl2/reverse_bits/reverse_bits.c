unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char rest = 0;

	while(i--)
	{
		rest <<= 1;
		rest |= (octet & 1);
		octet >>= 1;
	}
	return rest;
}

#include <stdio.h>
int main()
{
    unsigned char octet = 0b01000001; // Example value
    unsigned char reversed = reverse_bits(octet);
    printf("Original: %u, Reversed: %u\n", octet, reversed);
    return 0;
}

