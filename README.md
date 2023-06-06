Network-Interface

This repository contains the majority of my work from the class CS_431: Computer Networks. I utilized UTM to run a FreeBSD virtual environment in which I tested all of my code. The command vde_switch creates a virtual switch which the program connects to in order to simulate interface behavior.  Stack.c is the program in which I implement a network interface that currently receives ethernet frames and checks them for destination and source addresses, valid frame check sequence, and frame size.  Sender.c is used to send frames to Stack.c.  Next, I will extend the interface to implement an IP router, receiving multiple packets from multiple sources and routing them to multiple destinations. This includes implementing ARP requests and ICMP feedback messages.
