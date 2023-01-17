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
extern unsigned short checksum(unsigned char buf[], int length); // external function checksum, from checksum.c

int main(int argc, char *argv[])
{
	unsigned short server_port;
	unsigned int server_address;
	unsigned char buf[MAXLINE] = "";
	int sd, n, in;

	if (argc < 5) {
		fprintf(stderr, "Usage: %s address port input-filename output-filename\n", argv[0]);
		exit(1);
	}
	
	// set values for server address and port number
	server_address = inet_addr(argv[1]);	// server address
	server_port = htons(atoi(argv[2]));		// port number
	char *in_file = argv[3];				// input file from command line
	char *out_file = argv[4];				// output filename

	// connect to the swap server
	sd = swap_open(server_address, server_port);
	if (sd < 0) {
		fprintf(stderr, "swap_open error\n");
		exit(0);
	} 
	
	//Students to code the following:

	//open input file for reading
	printf("Open Input file for reading...\n");
	FILE *f; 								// file pointer
	
	char line[MAXLINE] = "";				// temporary variable to hold the line

	f = fopen(in_file,"r");					// opening file for reading
	printf("File Opened %s\n",in_file);		

	//send output file name to the server

	swap_write(sd,out_file,strlen(out_file));

	/*
	 *	Project Requirements say 5 lines is enough.
	 *	Text file contents: 
	 *	Shiv Thakar
	 *	T00721804
	 *	TRU
	 *	COMP
	 *	3271 
	 */

	fgets(line,sizeof(buf),(FILE *)f);		// get the first line of text file
    strcpy(buf,line);						// concatenate buf and line

	swap_write(sd,buf,strlen(buf));

    while(!feof((FILE *)f)){ // loop until end of file

        fgets(line,sizeof(buf),(FILE *)f);	// read line-by-line
        strcpy(buf,line);

		swap_write(sd,buf,strlen(buf));		// send contents to server

    } // end-loop

		
	// close the connection to the swap server		
	swap_close(sd);

	//close connection to input file
	printf("Name: Shiv Thakar, Student No: T00721804\n");
	fclose(f);
}
