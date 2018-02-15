#include "headers/dns_convert.h"

unsigned char *strtodns(const unsigned char *str)
{
	static unsigned char dns[76]; // completed dns name
	int num_position;	   // number's position instead dot
	int number;			   // number
	int i, a;

	memset(dns, 0x0, 76);

	num_position = 0;

	for(i = 0, a = i + 1; str[i] != '\0'; i++, a++)
	{
		if(str[i] == '.')
		{
			number = i - num_position;  // value before a domain

			dns[num_position] = number;

			num_position = i + 1;

			continue;
		}

		dns[a] = str[i];
	}

	number = i - num_position;

	dns[num_position] = number;
	dns[i + 1] = '\0';

	return dns;
}

unsigned char *dnstostr(const unsigned char *dns_name)
{
	static unsigned char str[76];
	unsigned short i, a;
	int copied = 0;

	memset(str, 0x0, 76);

	/* Set first value of characters
	   6google3com 
	   6 - first value, so 'copied = 6' */

	copied = dns_name[0];

	for(i = 1, a = 0; dns_name[i] != 0; i++)
	{
		while(copied--)
			str[a++] = dns_name[i++];

		str[a++] = '.';

		copied = dns_name[i];
	}

	str[--a] = '\0';

	return str;
}