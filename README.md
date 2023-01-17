Basic File Transfer Application
=============================================================================================================================
Developd a file transfer application using the SWAP Client and Server developed in ShivThakar18/Stop-and-Wait-Protocol repository. 

Program Implementation
-----------------------------------------------------------------------------------------------------------------------------
The client program reads a small input text file and sends each line as a packet (one-by-one) using SWAP Protocol to send them to the server. 

SWAP Protocol should implement error checking and sequence numbers. 

The server program reads each line and writes it to an output text file. 

Project Requirement
-----------------------------------------------------------------------------------------------------------------------------
Modify source code files for fta_client.c and fta_server.c

1. The soruce file and destination file name musst be given to the client program as arguments. 
    
2. The client program transfers the destination file name to the server program before the data transfer

    * For simplicity sake, the output file name was hardcoded into the server program. The program still sends the file name using SWAP Protocol, but only uses the hardcoded name. 

3. The FTA Client and Server programs only use SWAP and SDI APIs

4. The FTA Client and Server programs should print name

Compile and Run
-----------------------------------------------------------------------------------------------------------------------------
1. Compile the FTA server program

    $ gcc fta_server.c swap_server.c sdp.c checksum.c -o fta_server

2. Run the SWAP server program from the command line; specify the port number on the command line

    ./fta_server 8899

3. Compile the SWAP client program

    $ gcc fta_client.c swap_client.c sdp.c checksum.c -o fta_client

4. Run the client program from the command line; specify the IP address, port number and input-filename.

    ./fta_client 127.0.0.1 8899 input-filename
    
5. Use diff -s [input-filename] [output-filename] command in linux terminal to compare the two files. 
