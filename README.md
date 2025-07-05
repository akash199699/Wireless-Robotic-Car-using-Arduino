# 🚗 Wireless Robotic Car using Arduino

This project implements a wireless, Bluetooth-controlled robotic car using an Arduino UNO and the Adafruit Motor Shield. The car is controlled via Bluetooth commands sent from a mobile device, allowing movement in all directions. The project was developed as part of the **TechMaghi Internship** with thorough testing and staged development.

---

## 📂 Project Structure

| File Name                                   | Description                                                    |
|---------------------------------------------|----------------------------------------------------------------|
| `1_LED_Blink_Test.ino`                     | Basic LED Blink test to verify Arduino board functionality.    |
| `2_Bluetooth_LED_Control.ino`              | Bluetooth-based LED controller to test HC-05 Bluetooth module. |
| `3_Single_Motor_Test.ino`                  | DC Motor control using Adafruit Motor Shield (single motor test). |
| `4_Four_Motor_Drive_Test.ino`              | 4-Motor drive control code for robot chassis (forward/backward movement test). |
| `5_Tinkercad_Simulation_Code.ino`          | Arduino code used in Tinkercad simulation for virtual testing. |
| `6_Bluetooth_Robot_AltSoftSerial.ino`      | Optimized Bluetooth-controlled robot code with AltSoftSerial.  |
| `7_Final_Bluetooth_Robot.ino`              | Final, working Bluetooth-controlled robotic car code.          |
| `Circuit_Diagram_Wireless_Robotic_Car.pdf` | Official Tinkercad circuit diagram for hardware connections.   |

---

## 🛠️ Features

✅ Wireless control via Bluetooth (HC-05 module)  
✅ Movement: Forward, Backward, Left, Right, Stop  
✅ Uses Adafruit Motor Shield for easy motor control  
✅ Includes safety timeout to stop the car if Bluetooth connection is lost  
✅ Full Tinkercad simulation for virtual testing before hardware build  

---

## 🔌 Hardware Required

- Arduino UNO  
- Adafruit Motor Shield (AFMotor library)  
- 4 x DC Motors  
- HC-05 Bluetooth Module  
- Battery or suitable Power Supply  
- Chassis, Wheels, Jumper Wires  

---

## 💻 Software Required

- Arduino IDE  
- AFMotor Library  
- AltSoftSerial Library (for improved serial communication)  
- Tinkercad (for simulation)  

---

## 🎮 Control Commands

Send the following characters via a Bluetooth terminal app to control the car:

| Command | Action       |
|---------|--------------|
| `F`     | Move Forward  |
| `B`     | Move Backward |
| `L`     | Turn Left     |
| `R`     | Turn Right    |
| `S`     | Stop Movement |

---

## 📝 Circuit Diagram

The complete circuit is designed in Tinkercad. Refer to:  
📄 **Circuit_Diagram_Wireless_Robotic_Car.pdf**  

Alternatively, view the simulation directly on Tinkercad:  
🔗 **[Tinkercad Simulation Link](https://www.tinkercad.com/things/hyFAmloLa9s-wireless-robotic-car-using-arduino?sharecode=lDRVe4BPYtzxx_EdCz1vgR3Z1sXpGWqTHEF-u6VZ5gU)**  

---

## 🗂️ Development Progress

1. ✅ LED Blink Test (`1_LED_Blink_Test.ino`) — Tested Arduino setup  
2. ✅ Bluetooth LED Control (`2_Bluetooth_LED_Control.ino`) — Verified Bluetooth communication  
3. ✅ Single Motor Test (`3_Single_Motor_Test.ino`) — DC motor control validation  
4. ✅ 4-Motor Drive Test (`4_Four_Motor_Drive_Test.ino`) — Full chassis movement testing  
5. ✅ Tinkercad Simulation (`5_Tinkercad_Simulation_Code.ino`) — Complete system simulated  
6. ✅ Bluetooth Robot with AltSoftSerial (`6_Bluetooth_Robot_AltSoftSerial.ino`) — Improved communication version  
7. ✅ Final Bluetooth Robot (`7_Final_Bluetooth_Robot.ino`) — Fully working, production-ready code  

---

## 👨‍🔧 Author & Acknowledgements

Developed by **Akash Krishna** during the **TechMaghi Internship**  
Thanks to TechMaghi for providing practical project exposure and mentorship.  

---

## ⚡ Future Scope

- Mobile app for intuitive control  
- Integration of obstacle avoidance sensors  
- Battery status monitoring via Bluetooth  
- Upgrading to ESP32 for Wi-Fi & Bluetooth control  
