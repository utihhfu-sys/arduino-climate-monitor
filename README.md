# 🌡️ Arduino Climate Monitor Dashboard

A real-time web dashboard for monitoring **temperature and humidity** data from an **Arduino + DHT22 sensor**.

![Dashboard Preview](preview.png)

## Features

- 📊 Live temperature & humidity gauges
- 📈 Real-time history chart (last 20 readings)
- 🌡️ Heat index & dew point calculations
- 📋 System event log
- 📟 Built-in Arduino sketch reference
- ⚡ Zero dependencies — pure HTML/CSS/JS

## Hardware Required

| Component | Details |
|-----------|---------|
| Arduino | Uno / Nano / Mega |
| Sensor | DHT22 (AM2302) |
| Resistor | 10kΩ pull-up |
| Wiring | Data pin → D2 |

## Wiring Diagram

```
DHT22 Pin 1 (VCC) → Arduino 5V
DHT22 Pin 2 (Data) → Arduino D2 + 10kΩ to 5V
DHT22 Pin 4 (GND) → Arduino GND
```

## Arduino Setup

1. Install the **DHT sensor library** by Adafruit in the Arduino IDE
2. Open `arduino/climate_monitor.ino`
3. Upload to your Arduino board
4. Open Serial Monitor at **9600 baud** to verify readings

## Web Dashboard

Simply open `index.html` in any browser — no server required.

To connect to real Arduino data, modify the JavaScript section in `index.html` to use the **Web Serial API**:

```js
const port = await navigator.serial.requestPort();
await port.open({ baudRate: 9600 });
```

## Project Structure

```
arduino-climate-monitor/
├── index.html          # Main dashboard
├── arduino/
│   └── climate_monitor.ino  # Arduino sketch
└── README.md
```

## License

MIT — free to use and modify.
