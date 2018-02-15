struct dnshdr
{
	unsigned short tn_id; 	// transaction id
	unsigned short flags; 	// flags
	unsigned short quest; 	// questions number
	unsigned short answ_rrs; // answer RRs number
	unsigned short auth_rrs; // authority RRs number
	unsigned short add_rrs;	 // additional RRs number
};

struct query_end
{
	unsigned short type;
	unsigned short addr_class;
};