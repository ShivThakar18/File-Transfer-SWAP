#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

#define	MAXLINE	128	// maximum bytes to receive and send at once

// External functions
extern int swap_open(unsigned int addr, unsigned short port);
extern int swap_write(int sd, unsigned char buf[], int length);
extern void swap_close(int sd);

int main(int argc, char *argv[])
{
	unsigned short server_port;
	unsigned int server_address;
	unsigned char buf[MAXLINE];
	int sd, n, in;

	if (argc < 4) {
		fprintf(stderr, "Usage: %s address port input-filename\n", argv[0]);
		exit(1);
	}
	
	// set values for server address and port number
	server_address = inet_addr(argv[1]);	// server address
	server_port = htons(atoi(argv[2]));		// port number

	// connect to the swap server
	sd = swap_open(server_address, server_port);
	if (sd < 0) {
		fprintf(stderr, "swap_open error\n");
		exit(0);
	}
	
	//Students to code the following:
	
	//open input file for reading
	
	//send input file name o the server
		
	// loop
		//if there is data in the file, send it to the server
	// end-loop
		
	// close the connection to the swap server		
	swap_close(sd);

	//close connection to input file
	close(in);
}
