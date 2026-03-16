# TCP Market Data Server for Kalshi  

## Overview
This project implements a TCP server in C++ that funnels real-time market data from a Kalshi trade execution client** to multiple subscribed clients. The server acts as a hub: it receives trade packets from the execution client, processes them, and disperses them to all connected clients efficiently.  

Designed with **C++20** paradigms, it leverages modern concurrency and low-latency networking techniques while providing reliability features to recover from outages.  

---

## Features

- **TCP Server Architecture**  
  Accepts connections from a trade execution client and multiple subscriber clients over TCP.  

- **Packet Broadcasting**  
  Incoming packets from the execution client are distributed in real time to all connected subscribers.  

- **Low-Latency Networking**  
  Optimized using TCP options like TCP_NODELAY and TCP_CORK to reduce latency.  

- **Multithreading**  
  Uses modern C++20 concurrency features:  
  - `std::jthread` for safe thread management with automatic joining.  
  - `std::atomic` variables for thread-safe packet handling and server state.  

- **Reliable Restore / Replay**  
  - All incoming trade packets are stored in a binary file.  
  - In case of a server crash or outage, the server can replay recent trades sequentially to restore the order book and bring subscriber clients back up to date.  

- **Scalable Design**  
  Can handle multiple simultaneous subscribers efficiently, ensuring high-frequency market data is processed without blocking.  

---

## Architecture


- **Execution Client → Server:** Sends trade packets.
- **Server → Subscribers:** Broadcasts packets in real-time.
- **Trade Logging:** Stores all trades in a binary file for recovery.
- **Order Book Replay:** Replays trades sequentially on restart to rebuild state.

---

## Usage



