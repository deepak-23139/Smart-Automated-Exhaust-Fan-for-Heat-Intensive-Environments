# Smart Automated Exhaust Fan for Heat-Intensive Environments

## Overview
The Smart Automated Exhaust Fan for Heat-Intensive Environments is an IoT-based automation system designed to regulate ventilation in industrial and high-temperature environments. The system continuously monitors ambient temperature using a DHT22 sensor and automatically adjusts the exhaust fan speed based on real-time temperature conditions. By utilizing ESP32, Zero Cross Detection, and TRIAC-based phase-angle control, the system improves energy efficiency, reduces manual intervention, and maintains a comfortable working environment.

## Objectives
- Monitor environmental temperature in real time.
- Automatically control exhaust fan speed based on temperature.
- Improve ventilation efficiency in heat-intensive areas.
- Reduce power consumption through intelligent fan control.
- Enable remote monitoring through an IoT dashboard.

## Components Used
- ESP32 Development Board
- DHT22 Temperature & Humidity Sensor
- Zero Cross Detector (ZCD)
- MOC3021 Optocoupler
- BT136 TRIAC
- Bridge Rectifier
- Step-Down Transformer
- Voltage Regulator
- AC Exhaust Fan
- Resistors and Capacitors
- PCB/Breadboard
- Jumper Wires
- Power Supply Unit
- Blynk / ThingSpeak IoT Platform

## Working Principle
1. The DHT22 sensor continuously measures the ambient temperature.
2. The ESP32 reads and processes the temperature data.
3. The Zero Cross Detector synchronizes the control signal with the AC waveform.
4. Based on the temperature, the ESP32 calculates the required fan speed.
5. The MOC3021 Optocoupler isolates the control circuit and triggers the BT136 TRIAC.
6. The TRIAC controls the AC power supplied to the exhaust fan using phase-angle control.
7. Fan speed automatically increases or decreases according to temperature changes.
8. Temperature and fan status can be monitored remotely through an IoT dashboard.

## Features
- Automatic Temperature-Based Fan Speed Control
- Real-Time Temperature Monitoring
- Energy-Efficient Operation
- IoT-Based Monitoring and Control
- Reduced Manual Intervention
- Suitable for Industrial and Heat-Intensive Environments
- Reliable and Cost-Effective Solution

## System Architecture
Input Layer:
- DHT22 Temperature Sensor

Processing Layer:
- ESP32 Microcontroller

Control Layer:
- Zero Cross Detector (ZCD)
- MOC3021 Optocoupler
- BT136 TRIAC

Output Layer:
- AC Exhaust Fan

Monitoring Layer:
- Blynk / ThingSpeak Dashboard

## Applications
- Manufacturing Industries
- Server Rooms
- Warehouses
- Workshops
- Laboratories
- Commercial Kitchens
- Heat-Generating Industrial Environments

## Advantages
- Improved Workplace Comfort
- Enhanced Ventilation Management
- Reduced Energy Consumption
- Automated Temperature Regulation
- Easy IoT Integration
- Scalable and Flexible Design

## Software Used
- Arduino IDE
- ESP32 Board Package
- Blynk / ThingSpeak

## Technologies Used
- Embedded Systems
- Internet of Things (IoT)
- Temperature Monitoring
- Power Electronics
- TRIAC Phase Angle Control
- Real-Time Automation
