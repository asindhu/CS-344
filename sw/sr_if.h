/*-----------------------------------------------------------------------------
 * file:  sr_if.h
 * date:  Sun Oct 06 14:13:13 PDT 2002 
 * Contact: casado@stanford.edu 
 *sr_router
 * Description:
 *
 * Data structures and methods for handling interfaces
 *
 *---------------------------------------------------------------------------*/

#ifndef sr_INTERFACE_H
#define sr_INTERFACE_H

#ifdef _LINUX_
#include <stdint.h>
#endif /* _LINUX_ */

#ifdef _SOLARIS_
#include </usr/include/sys/int_types.h>
#endif /* SOLARIS */

#ifdef _DARWIN_
#include <inttypes.h>
#endif

#include "sr_protocol.h"

#define sr_IFACE_NAMELEN 32

struct sr_router;

/* ----------------------------------------------------------------------------
 * struct sr_if
 *
 * Node in the interface list for each router
 *
 * -------------------------------------------------------------------------- */

struct sr_if
{
    char name[sr_IFACE_NAMELEN];
    unsigned char addr[ETHER_ADDR_LEN];
    uint32_t ip;
    uint32_t speed;
    struct sr_if* next;
};

struct sr_if* sr_get_interface(struct sr_router* sr, const char* name);
void sr_add_interface(struct sr_router*, const char*);
void sr_set_ether_addr(struct sr_router*, const unsigned char*);
void sr_set_ether_ip(struct sr_router*, uint32_t ip_nbo);
void sr_print_if_list(struct sr_router*);
void sr_print_if(struct sr_if*);

#endif /* --  sr_INTERFACE_H -- */
