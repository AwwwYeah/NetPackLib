///////////////////////////////////////
//Author: MLP994					 //
//Email:  blackpower@horsefucker.org //
//Date:   10.02.2018				 //
///////////////////////////////////////

#ifndef __CR_BOOTP_LAYER_H__
#define __CR_BOOTP_LAYER_H__

#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "../../protocols/dhcp.h"

struct bootphdr *CreateBootpLayer(u_char type, u_char htype, u_char hlen, u_char hops,
					 			  u_int xid, u_short secs, u_short flags, u_int ciaddr,
					   			  u_int yaddr, u_int siaddr, u_int giaddr, u_char *chaddr,
					   			  u_char *sname, u_char *file, u_int cookie);

#endif