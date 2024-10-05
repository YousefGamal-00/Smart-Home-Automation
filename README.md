# Smart Home Automation Using ATmega32

## Project Overview
This project implements a **Smart Home Automation System** using the ATmega32 microcontroller. The system automatically controls lighting and fan speed based on environmental conditions, such as light intensity and temperature. It also includes fire detection capabilities and real-time feedback through an LCD display.

### Key Features
- **Automatic Lighting Control**: Adjusts three LEDs based on ambient light intensity using an LDR sensor.
- **Temperature-Controlled Fan**: The fan speed is adjusted proportionally using PWM, based on temperature readings from the LM35 sensor.
- **Fire Detection**: The system triggers an alert when fire is detected via a flame sensor and displays a "Critical alert!" on the LCD.
- **LCD Display**: Provides real-time updates on fan status, temperature, and light intensity.

### Specifications
1. **Lighting Control (LDR)**:
   - Intensity < 15%: All LEDs (Red, Green, and Blue) ON.
   - Intensity 16–50%: Red and Green LEDs ON.
   - Intensity 51–70%: Red LED ON.
   - Intensity > 70%: All LEDs OFF.
   
2. **Fan Speed Control (LM35)**:
   - Temp ≥ 40°C: Fan ON at 100% speed.
   - Temp ≥ 35°C < 40°C: Fan ON at 75% speed.
   - Temp ≥ 30°C < 35°C: Fan ON at 50% speed.
   - Temp ≥ 25°C < 30°C: Fan ON at 25% speed.
   - Temp < 25°C: Fan OFF.

3. **Fire Detection**:
   - Fire detection triggers an alarm and displays "Critical alert!" on the LCD.

### System Architecture
The project is designed using a **layered model architecture** for better code organization and scalability. It features custom **MCAL (Microcontroller Abstraction Layer)** and **HAL (Hardware Abstraction Layer)** drivers to manage hardware interactions.

### Components
- **Microcontroller**: ATmega32
- **Sensors**:
  - **LDR**: Measures ambient light intensity.
  - **LM35**: Measures room temperature.
  - **Flame Sensor**: Detects fire.
- **Actuators**:
  - **Fan**: Controlled via PWM for speed adjustment.
  - **LEDs**: Indicate light intensity levels.
  - **Buzzer**: Alerts during fire detection.
- **Display**: 16x2 LCD for real-time feedback.
