///////////////////////////////////////
//Author: MLP994					 //
//Email:  blackpower@horsefucker.org //
//Date:   10.02.2018				 //
///////////////////////////////////////

#ifndef __CR_ARP_LR_H__
#define __CR_ARP_LR_H__

#include <linux/if_ether.h>
#include <net/if_arp.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define ARP_HLEN 28

/* This structure will be used for 
   creation of ARP layer */
struct arp_addrs
{
	u_char ar_sha[ETH_ALEN];
	u_char ar_sip[4];
	u_char ar_tha[ETH_ALEN];
	u_char ar_tip[4];
};

/* Full opcodes(this is argument of the function) see in "/usr/include/net/if_arp.h" */

struct arphdr *CreateARPLayer(u_short opcode, u_char *send_mac, u_char *rcv_mac,
							  u_int send_ip, u_int rcv_ip);

#endif
