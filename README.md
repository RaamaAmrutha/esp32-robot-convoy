# ESP32 Robot Convoy – Leader-Follower Using ESP-NOW

This project demonstrates a multi-robot coordination system using ESP32 boards. One robot acts as the leader and communicates via ESP-NOW protocol with multiple follower robots to synchronize motion.

## Hardware Used
- ESP32 Devkit V1
- L298N Motor Driver
- 4WD Robot Chassis
- 11.1V Li-ion Battery

## Functionality
- The leader sends movement commands via ESP-NOW.
- Followers replicate the movement.
- If any robot stops, a halt signal is broadcasted.

##  Files
- `leader.ino`: Code for the leader ESP32
- `follower.ino`: Code for follower ESP32s

