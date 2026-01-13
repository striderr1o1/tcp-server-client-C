#TCP Server and CLient Implementation in C

Recently, I got free from third semester of my university, and honestly, It didn'tgo well, especially CCN. But I will be honest, Ive learned alot even though I didn't score well. So, to enhance my understanding of practical networking, I wrote a TCP server and a client in C using sockets.

# How It Works?

## The Three-way Handshake:

TCP uses a three way handshake before establishing a connection, basically, an exchange of flags that permit connection. 
- Client sends SYN flag
- server responds with ACK flag and along with that, it sends its own SYN flag for the client to acknowledge
- the client also responds with ACK flag and hence the connection is established.

## Data Transfer:

TCP takes the data stream and divides it into segments, adding its own TCP header and payload. Segments are sent one by one. For each segment, the server responds with an acknowledgement along with a sequence number. Each segment has its own sequence number.
(Note: There is some detail to this, but to maintain simplicity, it is not being mentioned here. You can look it up on the internet.)

## Connection Ending:

TCP ends the connection gracefully by performing a four way handshake.
- client sends FIN flag, indicating that it's done
- server responds with ACK
- then the server sends a FIN flag too
- client acknowledges the FIN flag with ACK
 
