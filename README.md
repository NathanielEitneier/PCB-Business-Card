# PCB Business Card — NFC + Onboard Game

A working business card designed, programmed, debugged, and soldered by myself.

<img width="1440" height="1920" alt="image" src="https://github.com/user-attachments/assets/5e13f047-8da9-4247-b39b-4c5c84bda1ea" />


## What this is

My first PCB design: a business-card-sized board built around an ATtiny84, with an onboard NFC tag and a small interactive game built into the card itself. Tap it with a phone and it links straight to this GitHub. I wanted this to be a real learning project, so I designed and programmed everything independently.

## Features

- **NFC tap-to-link** — taps open my GitHub / personal site directly from the card
- **Onboard game** — playable using the card's built-in switches and LEDs
- **ATtiny84-driven** — no separate dev board, just the chip on the card itself
- **Custom PCB** — designed, ordered, and hand-assembled from scratch (5 boards ordered)

## How it works

| Component | Pins |
|---|---|
| LEDs | Arduino-equivalent pins 5, 6, 7 |
| Switches | Arduino-equivalent pins 2, 3, 4 |
| MCU | ATtiny84 |

The game logic runs entirely on the ATtiny84, reading input from the three switches and driving the three LEDs as output/feedback. It is a memorization game where the LEDs will blink in a sequence and you must press the corresponding buttons that match that sequence to continue. For each sequence you get right another step is added. The game is won when 15 steps is reached.

## Build notes

- Programmed the ATtiny84 **before** soldering it onto the card, to avoid the risk of a bad reflow bricking a chip I couldn't easily reprogram in place
- The PCB was designed in KiCad
- nt3h1101 nfc chip
- Ordered 5 boards for assembly and handout

## What I learned

This was my first time taking a board from schematic to a physically assembled, working product. I gained a deeper understanding of the design process, as I completed each step I saw how the steps build upon each other.
## Hardware files

- [Link to schematic](./hardware/PCB_BusinessCard.kicad_sch)
- [Bill of Materials](./hardware/bom.csv)
- [Link to Demo Video](./images/DemoVid1.mov)
- [Link to Demo Video2 ](./images/DemoVid2.mov)

## Contact

**Nathaniel Eitneier**
Electrical Engineering, University of Florida
📧 eitneiern@ufl.edu
🔗 [github.com/NathanielEitneier](https://github.com/NathanielEitneier)
