# PCB Business Card — NFC + Onboard Game

A working business card designed, programmed, debugged, and soldered by myself.


<img width="1920" height="1440" alt="Untitled design" src="https://github.com/user-attachments/assets/30db8afc-befd-4c88-afe3-304d4cafffde" />


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

This was my first time taking a board from schematic to a physically assembled, working product. From this I gained a deeper understanding of the design process and how each step builds upon the last. This made me realize the importance of good habits like proper labeling and footprints on schematics when designing a PCB, because any short cuts taken will come back to haunt you later on in the design. I learned a few lessons the hard way. Programming the board with a USBasp did not work for me after hours of trying, and I eventually found a way to do it with a Arduino Uno R3. Additionally, soldering the SMD MCUs was a nightmare and if I make this project again I will switch to a through-hole MCU. Overall, the most important thing I learned from this was that I am capable of teaching myself and attempting projects that I may not have the skills to complete when I start them.
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
