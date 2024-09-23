# AimBot: The Face-Laser Pointer 
*(Totally not inspired by Michael Reeves… okay, maybe a "little")*

### Overview
Ever wanted to point lasers at your friends? Well, now you can! This project uses **OpenCV** to detect faces and automatically points a laser at them using a pan and tilt servo. 

### How it works
The program uses **OpenCV’s** face detection (with a face cascade) to find and track faces. Once it detects a face, it calculates the height of the eyes and sends the coordinates via the serial port. The servos then map the camera's resolution to their movement angles, and voilà—the laser is now locked onto your face!

### What You'll Need
- 2 Servos 
- A laser 
- A webcam 
- Some wires 

### Features
- **Face Tracking**
- **Laser Pointing**

### Demo
Check out the demo:

[![Laser Face Pointer Demo](https://img.youtube.com/vi/KHP4U4fDEwY/0.jpg)](https://youtu.be/KHP4U4fDEwY)
