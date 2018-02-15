#ifndef __DNS_CONVERT_H__
#define __DNS_CONVERT_H__

#include <string.h>

unsigned char *strtodns(const unsigned char *str);
unsigned char *dnstostr(const unsigned char *dns_name);

#endif