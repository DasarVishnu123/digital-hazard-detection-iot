
# Digital Hazard Detection & Mitigation System (IoT)

## Overview
An ESP32-based IoT system designed to detect gas leakage and fire hazards in real time and provide immediate alerts to ensure safety in domestic and industrial environments.

## Features
- Gas leakage detection
- Flame/fire detection
- Buzzer and LED alerts
- Automatic exhaust fan control
- Real-time cloud monitoring using ThingSpeak
- SMS alerts for emergencies

## Hardware Components
- ESP32
- Gas Sensor (MQ series)
- Flame Sensor
- Buzzer
- LED
- Relay Module
- Exhaust Fan
- Power Supply

## Software & Tools
- Arduino IDE
- Embedded C
- ThingSpeak Cloud
- Git & GitHub

## Working Principle
Sensors continuously monitor the environment. When gas or fire is detected beyond a threshold, the ESP32 triggers local alerts and uploads data to ThingSpeak. SMS alerts are sent to the user for immediate action.

## Applications
- Smart kitchens
- Industrial safety systems
- Gas leakage monitoring
- Fire prevention systems

## Future Scope
- Mobile app integration
- AI-based hazard prediction
- Multi-node IoT monitoring
- GSM backup communication
