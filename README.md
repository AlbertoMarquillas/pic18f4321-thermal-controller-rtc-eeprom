# pic18f4321-thermal-controller-rtc-eeprom

![License](https://img.shields.io/badge/license-MIT-green.svg)
![Toolchain](https://img.shields.io/badge/MPLAB%20X-IDE-blue)
![Compiler](https://img.shields.io/badge/XC8-Compiler-informational)
![MCU](https://img.shields.io/badge/MCU-PIC18F4321-lightgrey)
![Status](https://img.shields.io/badge/status-portfolio--ready-brightgreen)

Embedded system for **thermal management** on **PIC18F4321**: real‑time monitoring, **PWM dual‑fan control**, **RTC (DS3231)** timestamps, **EEPROM** critical‑event logging, **RAM 62256** temperature history, and **UART protocol** for host integration. Designed from an academic assignment and converted into a **professional, reproducible** portfolio project.

---

## 📌 Overview

The firmware implements a controller intended for a server‑room‑like environment. It samples temperature, evaluates thresholds and **state machine** (LOW / MODERATE / HIGH / CRITICAL), drives two fans via PWM, and signals status through an **RGB LED** (including flashing on critical). Critical events are persisted to **external EEPROM** with **RTC** timestamps; periodic samples are stored in **external RAM** for graphing.

**Key Features**

* PIC18F4321 bare‑metal firmware (XC8).
* **RTC DS3231** for wall‑clock time (I²C).
* **24xx EEPROM** logging (I²C): circular buffer of critical events with timestamps.
* **62256 RAM** history buffer (parallel): periodic temperature samples for graphs.
* **Dual PWM fan control** with state‑dependent duty.
* **RGB LED + joystick + push‑button** user interface.
* **UART protocol** (text commands) for initialization, time setting, log/historic retrieval.

---

## 🧩 Architecture (high‑level)

```
[Temp Sensor] → [PIC18F4321] → PWM → [Fan A]
                                PWM → [Fan B]
                          I²C → [DS3231 RTC]
                          I²C → [24xx EEPROM]
                         GPIO → [62256 RAM]
                         UART → [Host PC / Java client]
                        GPIOs → [RGB LED, Joystick, Button]
```

---

## 🧱 Bill of Materials (BOM)

* MCU: **PIC18F4321**
* RTC: **DS3231** (+ CR battery)
* EEPROM: **24xx series** (e.g., 24LC256)
* RAM: **62256** (static RAM)
* Temp sensor: e.g., **TMP36 / LM35** (or the one used on your board)
* 2 × DC fans (PWM‑driven), RGB LED, joystick + push‑button, level‑appropriate passives
* Programmer: **PICkit** / ICD

> If your exact parts differ, update this list and the pinout table below.

---

## 🔌 Pinout (placeholder)

Add/adjust according to your wiring/board.

| Function      |     PIC Pin | Notes                      |
| ------------- | ----------: | -------------------------- |
| UART TX       |       `RC6` | Host serial out            |
| UART RX       |       `RC7` | Host serial in             |
| I²C SDA       |       `RC4` | DS3231 / EEPROM            |
| I²C SCL       |       `RC3` | DS3231 / EEPROM            |
| PWM Fan A     |      `CCP1` | Duty per state             |
| PWM Fan B     |      `CCP2` | Duty per state             |
| RGB LED R/G/B | `RA? / RB?` | Update per board           |
| Joystick X/Y  |       `AN?` | Analog inputs              |
| Push button   |       `RB?` | Pull‑up                    |
| RAM 62256     |     `PORT?` | Address/data/control lines |

> Replace `?` with actual ports from your project.

---

## 🛠 Toolchain & Requirements

* **MPLAB X IDE**: (specify version you used)
* **XC8 Compiler**: (specify version)
* **PICkit** / ICD for programming
* Windows (PowerShell scripts provided as helpers)

---

## 📂 Repository Structure

```
src/
  firmware/            # MPLAB X projects (*.X)
docs/
  specs/               # Assignment PDF and notes
  assets/              # Diagrams, pinouts, photos
tools/                 # Helper scripts (flash, serial tests)
test/                  # Smoke tests (UART/LED)
build/                 # Local artifacts (ignored)
README.md
```

---

## 🚦 States & Control Logic (summary)

* **LOW**: fans off/low duty, LED steady (e.g., green)
* **MODERATE**: medium duty, LED color update
* **HIGH**: high duty, LED warning
* **CRITICAL**: max duty + LED flashing, **EEPROM log entry** with timestamp

Thresholds and hysteresis are defined in firmware constants.

---

## 🧮 Data Persistence

* **EEPROM (critical logs)**: circular buffer (\~15 entries by default). Each entry contains timestamp + event code + last temperature.
* **RAM 62256 (history)**: fixed‑rate samples for graphing (retrieved via UART as a “datagraph” frame).

---

## 🗣 UART Protocol (host interface)

Typical commands (ASCII, newline‑terminated):

* `INITIALIZE` – reset state/log indices, default config
* `SET_TIME,<YYYY-MM-DD HH:MM:SS>` – set RTC
* `GET_LOGS` – dump EEPROM critical events
* `GET_GRAPH` – dump RAM history samples (datagraph)
* `RESET` – soft reset state machine

> Adjust names/terminators to your actual implementation and document the exact frame format.

---

## ▶️ Build & Flash

**Option A — MPLAB X IDE**

1. Open the desired `*.X` project under `src/firmware/`.
2. Select device **PIC18F4321** and your **XC8** toolchain.
3. Build the project; program the device with **PICkit/ICD**.

**Option B — Helpers (placeholders)**

* `tools/flash.ps1`  → add your preferred `pk2cmd`/`mplabcommander`/MPLAB X CLI call.
* `tools/serial-smoke.ps1` → open COM port, send a command (e.g., `GET_LOGS`) and print response.

---

## 🔎 Smoke Tests

Quick checks to validate the build on hardware:

1. **LED test**: power on → LED shows LOW state color.
2. **Fan PWM test**: force HIGH → duty increases; CRITICAL → max duty and LED flashes.
3. **EEPROM log**: trigger CRITICAL and confirm a new entry via `GET_LOGS`.
4. **RTC**: set time with `SET_TIME`, power cycle, verify persistence.
5. **Graph**: request `GET_GRAPH` and confirm frame length and structure.

Automate #3–#5 via a simple PowerShell serial script in `tools/`.

---

## 🧭 Roadmap

* [ ] Finalize pinout table and block diagram
* [ ] Provide example **.hex** in Releases (if license allows)
* [ ] Add `tools/flash.ps1` and `tools/serial-smoke.ps1`
* [ ] Document UART frame format (CRC/terminator)
* [ ] Add unit/simulation notes (if any) and timing diagrams

---

## 📜 License

MIT — see `LICENSE`. If vendor headers or libraries are included, keep their original notices and cite the source.
