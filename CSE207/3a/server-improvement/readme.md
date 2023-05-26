MILOS OUNDJIAN (milos.oundjian) and ERIK DZIEKONSKI (erik.dziekonski-bautista)
CSE207 - Tutorial 3a

The goal of this tutorial was to implement a threaded UDP client and server. The client sends a message to the server, which then echoes the message back to the client continuously until the client sends a new message. The client prints the messages it receives to the screen.

To run the program, first run `make` in order to compile the program. Then, run `./server PORT` in one terminal window and `./client IP_ADDRESS PORT` in another. The client will prompt you to enter a message, which will then be echoed back continuously to the client and printed to the screen. You will also see the message printed in the server terminal window.