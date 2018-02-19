#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>



int main (int argc, char **argv)
{
	/** 
 	* ET_P_ALL = All packet protocols. 
 	* SOCK_RAW = access to header.
    */
	int sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

	/* sockaddr_ll = mac address or network interface. */
	struct sockaddr_ll addr, listenaddr;

	listenaddr.sll_family = AF_PACKET;
	listenaddr.sll_protocol = htons(ETH_P_ALL);
	
	/* ifindex = interface index (ethernet, virtual, etc) */
	listenaddr.sll_ifindx = if_nametoindex("h1-eth0"); //Mininet interface.
	
	/* Listen to packets on h1-eth0 interface only. */
	bind(sockfd, (struct sockaddr *) &listenaddr, sizeof(listenaddr));

}
