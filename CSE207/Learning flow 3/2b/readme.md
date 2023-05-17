<!-- README file for udp client and server -->
# UDP Client and Server

## Usage
### Server
```
./server.py <port>
```
### Client
```
./fancyclient.py <server ip> <server port>
```
The client will send a message to the server and the server will respond with the same message. It runs on a while loop so it will continue to send messages until the user enters 'exit'.

### Example
```
./server.py 4444
./client.py localhost 4444