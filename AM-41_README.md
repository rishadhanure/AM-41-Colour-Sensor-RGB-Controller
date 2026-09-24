# AM-41 Colour Sensor RGB Controller

Arduino UNO + TCS3200 Colour Sensor + RGB LED + 16×2 LCD

---

## Project Overview

The **AM-41 Colour Sensor RGB Controller** is an Arduino-based colour detection system designed to identify the dominant colour of an object and provide a corresponding visual indication.

The system uses a **TCS3200 colour sensor** to detect Red, Green, and Blue components. The Arduino UNO processes the sensor readings, displays the detected colour on a 16×2 LCD, and activates the corresponding RGB LED.

---

## Key Features

- Real-time colour detection
- Detection of Red, Green, and Blue colours
- TCS3200 frequency-based colour sensing
- Automatic RGB LED control
- 16×2 LCD colour display
- Arduino UNO based control system
- Simple and low-cost implementation

---

## Components Used

| Component | Purpose |
|---|---|
| Arduino UNO | Main controller |
| TCS3200 Colour Sensor | Detects the colour of an object |
| 16×2 LCD | Displays the detected colour |
| Red LED | Indicates Red detection |
| Green LED | Indicates Green detection |
| Blue LED | Indicates Blue detection |
| Resistors | LED current limiting |
| Perfboard | Circuit assembly |
| Jumper Wires | Electrical connections |

---

## Pin Configuration

### TCS3200 Colour Sensor

| TCS3200 | Arduino UNO |
|---|---|
| S0 | A0 |
| S1 | A1 |
| S2 | A2 |
| S3 | A3 |
| OUT | A4 |

### 16×2 LCD

| LCD | Arduino UNO |
|---|---|
| RS | D8 |
| EN | D9 |
| D4 | D10 |
| D5 | D11 |
| D6 | D12 |
| D7 | D13 |

### RGB LED

| LED | Arduino UNO |
|---|---|
| Red | D3 |
| Green | D5 |
| Blue | D6 |

---

## Working Principle

The TCS3200 colour sensor detects the intensity of different colour components and produces a corresponding frequency output.

The Arduino UNO reads the sensor output for:

- Red
- Green
- Blue

These values are compared to determine the dominant colour.

The detected colour is then displayed on the LCD and the corresponding LED is activated.

### Detection Process

```text
Coloured Object
       ↓
TCS3200 Colour Sensor
       ↓
Red / Green / Blue Readings
       ↓
Arduino UNO
       ↓
Colour Detection
       ↓
 ┌─────┴─────┐
 ↓           ↓
LCD       RGB LED
Display   Indication
```

---

## Colour Detection

| Detected Colour | LED Indication | LCD Display |
|---|---|---|
| Red | Red LED ON | RED |
| Green | Green LED ON | GREEN |
| Blue | Blue LED ON | BLUE |
| Unknown | All LEDs OFF | UNKNOWN |

---

## Output

The system provides two outputs:

**LCD Display**

```text
Detected:
RED
```

**RGB LED**

The LED corresponding to the detected colour is activated.

---

## Applications

- Colour detection systems
- Colour sorting
- Object identification
- Robotics projects
- Embedded systems
- Educational projects
- Automation systems

---

## Limitations

The detection accuracy can be affected by:

- Ambient lighting
- Distance between the sensor and object
- Surface reflectivity
- Object colour intensity
- Sensor calibration

---

## Future Improvements

- Automatic sensor calibration
- Improved colour classification
- Ambient light compensation
- Detection of additional colours
- Automatic colour sorting
- IoT-based monitoring
