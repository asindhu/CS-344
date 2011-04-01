#include "sr_if.h"

struct sr_router {
	struct sr_if* if_list; /* list of interfaces */
	/* Pointer to ARP cache */
	/* Pointer to routing table */
	/* Any other state */
};
