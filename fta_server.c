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
extern int swap_wait(unsigned short port);
extern int swap_read(int sd, unsigned char buf[]);
extern void swap_close(int sd);
extern unsigned short checksum(unsigned char buf[], int length); // external function checksum, from checksum.c

int main(int argc, char *argv[])
{
	unsigned short server_port;
	unsigned int server_address;
	unsigned char message[MAXLINE];
	int sd, n, out;
	char out_file[MAXLINE]; // hardcode output file name to fta_server.c

	if (argc < 2) {
		fprintf(stderr, "Usage: %s port\n", argv[0]);
		exit(1);
	}

	// set values for server address and port number
	server_port = htons(atoi(argv[1]));

	// connect to the port allocated to the swap server
	sd = swap_wait(server_port);
	if (sd < 0) {
		fprintf(stderr, "swap_open error\n");
		exit(0);
	}

	//Students to code the following:

	//read in the first message as the new name of the file
	swap_read(sd,out_file);
	//open output file for writing
	FILE *f;  	// file pointer

	f = fopen("output.txt","w"); // file open
	
	while((n = swap_read(sd,message)) > 0){	//begin-loop

		message[n] = '\0';
		printf("%s\n",message);		//get the file data from the client until end-of-file

		fprintf(f,"%s",message); // write message to output file
	} //end-loop

	printf("\n\nMessage written to %s file\n",out_file);

	// close the connection to the swap server
	swap_close(sd);
	
	//close connection to output file
	printf("Closing Connection to File\n");
	printf("Name: Shiv Thakar, Student No: T00721804\n");
	fclose(f);
	//close(out);
}
