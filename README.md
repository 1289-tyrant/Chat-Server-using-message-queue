#Chat-Server-using-message-queue-in-c

This repository contains the code for a basic implementation of char server using system V message queues in c.

You can send a message from any of the client processes to the server process. The server process then converts the message to uppercase and returns it to the process which sent it.

To compile run the following commands in the terminal:
gcc -o server server.c
gcc -o client1 client1.c
gcc -o client2 client2.c

To execute run the following command in the terminal:
./server
./client1
./client2