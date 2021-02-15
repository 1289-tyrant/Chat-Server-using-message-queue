# Chat-Server-using-message-queue
This repository contains the code for a basic implementation of chat server using system V message queues in c.
You can can a message from any of the client processes to the server process. The server process then converts all the letters to uppercase and sends it back to the
same process which sent the message.


To compile run the following commands in the terminal:
gcc -o server server.c
gcc -o client1 client1.c
gcc -o client2 client2.c

To execute run the following command in the terminal:
./server
./client1
./client2
