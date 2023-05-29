
<details>
<summary> Learning Flow 20: Programming in C</summary>

#### Intro

##### The Morphology 
- Header files provide the interface and function declarations.
- Source files contain the implementations and program logic.

##### Compiling adn Linking
- **Compiling:** refers to "compile" source code (*.h and *.c) to object (*.o) files. The object files are similar to the machines language
`cc -c hello-world.c`

- **Linking:** Refers to creating an executable from object files
`cc -o hello-world hello-world.o`

The `-Wall` enable a set of warning messages during the compilation process.



##### Preprocessor Directives
Preprocessor directives, such as `#define`, `#ifdef`, `#ifndef` and `#endif`, are typically used to make source programs easy to change and easy to compile in different execution environments. 

##### Make and Makefiles
The Makefile consists a set of rules. Each rule include a target, a list of pre-requisites and a command to build/run the target:
```
target: pre-req-1 pre-req-2 pre-req-3 ...
	command-to-run
```
1. It is possible to declare variables in makefiles, by way of a statement like VARIABLENAME=VALUE
1. You then refer to the value of that variable by $(VARIABLENAME)
1. The compiler directive -Dxxxx corresponds to #define xxxx

#### Pointers, references etc

- A **pointer** is a variable that stores the address of another variable.
- The type of a pointer is the type of the variable whose address it stores.
- The unary operator `&` gives the address of a variable.
- The unary operator `*` gives the value of the variable whose address is given by the operand.
- The unary operator `*` is also used to declare a pointer variable.
>```
>type *var-name;
>```


#### Debugging with GDB
To debug a program, we need to generate debugging symbols during compilation and describe the data type of each variable. This is done by adding the `-g` option to the `cc` command.

#### Memory management in C
Whenever you want to use a structure or an array, you must deal with its allocation by yourself.

Hence, you first need to allocate buffers for the structure or array. Then, you need to free the buffers when you are done with them.

You do this by using the `malloc` and `free` functions. Or for arrays, you can simply do `int array[10]` to allocate an array of 10 integers.


##### Memory allocation functions
- `void *malloc(size_t size)`:  allocates memory.
    - **Arg:** The size in bytes
    - **Returns:** Pointer to beginning of allocated memory (type `void*` which holds address of any object type)

- `void *calloc(size_t nitems, size_t size)`: allocates memory. The difference with `malloc` is that `calloc` does not set the memory to zero.
    - **Arg:** 
    *nitems* − This is the number of elements to be allocated.
    *size* − This is the size of elements.
    - **Returns:** same as `malloc`

- `void *realloc( void *ptr, size_t new_size)`
    Reallocation can occur in two ways:
    a) By expanding or contracting the existing memory pointed to by 'ptr'. The contents of the area remain unchanged up to the smaller of the new and old sizes. If the area is expanded, the contents of the new part are undefined.
    b) By allocating a new memory block of 'new_size' bytes, copying the memory area with a size equal to the smaller of the new and old sizes, and freeing the old block.
  - **Arg:** Reallocates the given area of memory. 

> The type `size_t` is the unsigned integer type of the result of sizeof , _Alignof (since C11) and offsetof, depending on the data model.

#### Miscellaneous
- `sizeof(type)`: Queries size of the object or type (in bytes).

</details>


<details>
<summary>Learning Flow 30: Network Programming in C</summary>

#### Understand basic networking concepts

- **Hosts:** The endpoints of the internet (comps/apps). Connections terminate here
- **Routers:** In charge of carrying communications between hosts

##### Unicast/multicast/broadcast
- **Unicast:** Exactly one sender (uniquely identified), exactly one recipient (uniquely identified)
Identifier of connection flow: `({TCP | UDP}Ipaddr1,port1,Ipaddr2,port2)`

- **Multicast:** Exactly one sender (uniquely identified), a set of recipients (named but "unknown")
> Typically only supported locally (not supported on the internet)
- **Anycast:** Exactly one sender (uniquely identified), exactly one recipient (from among "unknown")
> It is a one-to-nearest communication method where data is sent from a sender to the nearest available recipient among a group of potential recipients. 

For a given transport protocol: a 5-tuple


##### Socket
We uniquely identify through "sockets" which is in the form of `Ipaddr:port`. Represents a communication endpoint. The Ipaddr identifies a computer, the port the service running on it. Described as a **tuple**.


##### Connection
- Connection setup:
  1. Server "listens" on a port
  2. Client "connects" to server
  3. Handshake: negotiate connection parameters
> The only difference between a client and server is who sends the first request. Hence Client/Server in networking: ONLY relevant for connection setup.

 
1. "Set up" connection
2. Transmit data back-and-forth
   - "read" from scoket
   - "write" to socket
3. "Tear down" connection


##### Port Number
Well-known ports: `0-1023` require root-privileges

##### Protocol Stack
- **Application Layer (layer 7):** HTTP, FTP, SMTP, DNS, ...
- **Transport Layer (layer 4):** End-to-end. TCP, UDP
> Provides a "Well-defined" transport service to uppers layer. Responsible for how packets are delivered.
- **Network Layer (layer 3):** Multi-hop. E.g: IPv4 and IPv6
> Provides as a service a "best effort" service. It will try its best to deliver the packet, but it may fail. Packets can be re-ordered and lost 
- **Link Layer (layer 2):** 1-hop. E.g.: Ethernet, WiFi, ...
> Provides as a service a "who knows" delivery semantics. It is a best-effort service. It is unreliable, unordered, and may drop packets. 

Sometimes in quizzes L2=layer 2

##### TCP/UDP
- **TCP:** Transmission Control Protocol. Connection-oriented. Reliable, in-order delivery. Flow control. Congestion control.
- **UDP:** User Datagram Protocol. Connectionless (no hand-shake needed). Unreliable, unordered delivery. No flow control. No congestion control.
> Used in some applications where reordering or loss of data is not an issue. E.g: live video streaming, VoIP, DNS, DHCP, ...

An application will choose the socket type and may also ignore the transport layer and receive raw packets from the network layer.

#### TCP - A programmers Perspective
TCP transport semantics:
  - Represent data to receiving application "as they were sent"
  - Preserve ordering, ensure reliability & integrity

1. Server bind and listen to a port, then accept incoming connection request
```c
char* msg = "Hello World !\n";
struct sockaddr_in dest; // sockaddr_in is a struct that contains an internet address
struct sockaddr_in serv; // sockaddr_in is a struct that contains an internet address
int mysocket; // Socket descriptor
socklen_t socksize = sizeof(struct sockaddr_in); // socklen_t is an integer type of width of at least 32 bits

memset(&serv, 0, sizeof(serv)); // set memory to zero
serv.sin_family = AF_INET; // sin_family is the address family
serv.sin_port = htons(PORT); // sin_port is the port number
serv.sin_addr.s_addr = htonl(INADDR_ANY); // sin_addr is the IP address

mysocket = socket(AF_INET, SOCK_STREAM, 0); //AF_INET is Address Family for IPv4 (AF_INET6 for IPv6) , SOCK_STREAM for TCP (SOCK_DGRAM for UDP), 0 means default protocol
bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr)); // Associates socket with an address (sockaddr *) which encapsulates the IP address and port number
listen(mysocket, 2); //Prepares socket to accept incoming connections. 2 is the backlog, the number of connections that can be waiting while the process is handling a particular connection
int consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize); // Wait for request to arrive (IT IS BLOCKING). Returns a new socket descriptor (r) that represents the accepted connection. 
close(mysocket); // Close the socket
```

> IMPORTANT: serv is of type sockaddr_in and it requires to be typecasted

2. Client "connects" to server
```c
mysocket = socket(AF_INET, SOCK_STREAM, 0); // A stream socket (TCP)
connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr_in)); // Connect to server
send(mysocket, msg, strlen(msg), 0); // Send data
```

3. "Handshake": negotiate connection parameters
> Handshake done automatically

#### UDP - A Transport Protocol
UDP transport semantics:
   - "Service Minimum": Ensures packet wasn't corrupted in transit
   - Multicast-capable
UDP assumptions (from network):
   - Best effort (from network): reordering, loss, garbling possible


```c
sockfd = socket(AF_INET, SOCK_DGRAM, 0)

int sendto(int sockfd, const void *msg, int len, unsigned int flags, const struct sockaddr *to, sockln_t tolen);

```

##### Miscellaneous
- `uint16_t htonl(uint32_t hostlong)`: host to network long
- `uint16_t htons(uint16_t hostshort)`: host to network short
- `uint32_t ntohl(uint32_t netlong)`: network to host long
- `uint16_t ntohs(uint16_t netshort)`: network to host short
> Host refers to your machine's byte order 

IPv4:
```
struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET, AF_INET6
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

```

IPv6:
```
struct sockaddr_in6 {
    u_int16_t       sin6_family;   // address family, AF_INET6
    u_int16_t       sin6_port;     // port number, Network Byte Order
    u_int32_t       sin6_flowinfo; // IPv6 flow information
    struct in6_addr sin6_addr;     // IPv6 address
    u_int32_t       sin6_scope_id; // Scope ID
};
```

</details>


<details>

</details>