///////////////////////////////////////
//Author: MLP994					 //
//Email:  blackpower@horsefucker.org //
//Date:   10.02.2018				 //
///////////////////////////////////////

#ifndef __CR_PROT_LR_H
#define __CR_PROT_LR_H

#include <stdlib.h>
#include <string.h>
#include <linux/if_ether.h>
#include <net/if_arp.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include "proto/bootp.h"

/* Ethernet header creation */
struct ethhdr *CreateEthLayer(u_char *dst, u_char *src, u_short prot);

/* ARP header creation */
#define ARP_HLEN 28

struct arphdr *CreateARPLayer(u_short opcode, u_char *send_mac, u_char *rcv_mac,
							  u_int send_ip, u_int rcv_ip);


/* IP header creation */
#define IP_HLEN 20

struct iphdr *CreateIPLayer(u_char hl, u_char vers, u_char tos, u_short id, 
							u_short off, u_char ttl, u_char prot, u_int src,
						    u_int dst, u_short prot_len);

/* UDP header creation */
#define UDP_HLEN 8

struct udphdr *CreateUDPLayer(u_short source, u_short dest, u_short prot_len);

/* BOOTP header creation */
#define BOOTP_HLEN 240

struct bootphdr *CreateBootpLayer(u_char type, u_char htype, u_char hlen, u_char hops,
					 			  u_int xid, u_short secs, u_short flags, u_int ciaddr,
					   			  u_int yaddr, u_int siaddr, u_int giaddr, u_char *chaddr,
					   			  u_char *sname, u_char *file, u_int cookie);

/* DHCP header creation(standart messages) */
#define STAND_DISC_LEN 22
#define STAND_REQ_LEN 34
#define STAND_REL_LEN 10

u_char *CreateStandartDiscover(u_int ls_time, u_int rn_time, u_int rb_time);

u_char *CreateStandartRequest(u_int req_addr, u_int ls_time, u_int rn_time,
							  u_int rb_time, u_int srv_addr);

u_char *CreateStandartRelease(u_int srv_addr);

#endif
