# Minitalk - ✅125/100

#### Grade rating
- ✅ = Okay project
- ⭐ = Outstanding project

## Overview

This project is a small data exchange program implemented using UNIX signals. It consists of a client and a server for communication between processes.

## Signals Used

- **SIGUSR1**: Used by the client to send messages to the server.
- **SIGUSR2**: Used by the server to acknowledge the receipt of messages from clients.

Since two signals are only permitted, the only way to send information from the server to the client is by sending 0 and 1 bits.

## Server

1. To start the server, execute the server program. After its launch, the server will print its Process ID (PID).

2. The server is designed to quickly receive and display strings sent by clients. If it takes too long (more than 1 second for displaying 100 characters), it's considered too slow.

3. The server can handle communication from multiple clients in a row without needing to be restarted.

4. The server supports Unicode characters.

## Client

1. To use the client, you need to provide two parameters:
   - The server's PID (Process ID).
   - The string you want to send to the server.

2. The client sends the specified string as a signal to the server using UNIX signals (SIGUSR1 and SIGUSR2).

3. The server acknowledges every message received by sending back a signal to the client.

## Example Usage

To start the server:

```shell
$ ./server
Server PID: [Server_PID]
```

To send a message from the client to the server:

```shell
$ ./client [Server_PID] "Hello, Minitalk!"
```

The server will display the received message.


