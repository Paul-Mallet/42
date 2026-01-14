# Net_practice - Project_10

## 📝 Overview

The **net_practice** project is a theoretical and practical discovery of **networking**. Unlike previous coding projects, the goal here is to solve several network configuration puzzles to make computers communicate with each other in under 15min.

This project covers essential concepts such as **IP Addressing** (IPv4), **Subnet Masks**, **CIDR notation**, **Default Gateways**, and **Routing Tables**. Mastering these concepts is crucial for understanding how data travels across the internet and local networks.

## 🔍 Key Concepts

To solve the levels, you must master the following rules:

1. IP Address & Subnet Mask
The Subnet Mask determines which part of the IP address belongs to the Network and which part belongs to the Host.

**Example** : For 192.168.1.10 /24, the mask is 255.255.255.0. The first 24 bits are the network.

2. Network & Broadcast Addresses
* **Network Address** : The first address of a range (e.g., 192.168.1.0).

* **Broadcast Address** : The last address of a range (e.g., 192.168.1.255).

* **Usable IPs** : All addresses between these two.

3. Routing & Gateways
For two devices on different networks to communicate, they must go through a **Router** (Gateway). The routing table must have a rule that directs the traffic to the correct interface.

---

## 📥 Installation

Clone the repository and navigate to the project folder :

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd net_practice
```

Then you will find 10 json files which represent my filled exercises at evaluation time.
You will not be able to use them since you have not access to this webpage.
But you can still understand relations between IP's choices to solve each level.

## 🚀 Ressources I recommand to learn faster

* [IP & Subnetting](https://www.subnetting.net/Start.aspx)
* [CIDR Table](https://cidr.xyz/)
* [GNS3](https://www.gns3.com/software/download)