# 🌡️ Temperature Alert System using Arduino

A simple Arduino project that monitors temperature and indicates the level using LEDs.  
When the temperature becomes too high, a buzzer alerts the user.

## 🚀 Project Idea

Initially, the idea was to use a **DC motor as a fan** that would automatically increase speed when the temperature rises during summer.

For this prototype, I implemented the concept using:
- LEDs to indicate temperature levels
- A buzzer to alert when the temperature is too high

This makes it a simple **temperature monitoring and alert system**.

## ⚙️ How it Works

1. The **DHT11 sensor** reads the temperature.
2. Arduino processes the temperature data.
3. LEDs indicate the temperature level:
   - 🔹 1 LED → Low temperature
   - 🔹 2 LEDs → Medium temperature
   - 🔹 3 LEDs → High temperature
4. When temperature crosses the threshold (35°C), the **buzzer turns ON**.

## 🧰 Components Used

See full list here:  
📄 components/components_list.md

## 🔌 Circuit Connections

See wiring diagram here:  
📁 connections/wiring_diagram.png

## 💻 Arduino Code

Code is available in the **code folder**:


## 🔗 Project Post on LinkedIn

Check out the project post here:  

🔗 **[View the LinkedIn Post](https://www.linkedin.com/posts/-rahuljana_arduino-electronics-diyprojects-activity-7367657120516788224-qPdX)**

