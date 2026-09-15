# PCB Business Card — NFC + Onboard Game

A working business card designed, programmed, debugged, and soldered by myself.

![Board photo](./images/card-front.jpg)
*(swap in a real photo of the soldered board — this is the first thing anyone sees)*

## What this is

My first PCB design: a business-card-sized board built around an ATtiny84, with an onboard NFC tag and a small interactive game built into the card itself. Tap it with a phone and it links straight to this GitHub / my site. I wanted this to be a real learning project rather than a quick checkbox — every part of it, from the pin mapping to the programming order, was a deliberate decision.

## Features

- **NFC tap-to-link** — taps open my GitHub / personal site directly from the card
- **Onboard game** — playable using the card's built-in switches and LEDs
- **ATtiny84-driven** — no separate dev board, just the chip on the card itself
- **Custom PCB** — designed, ordered, and hand-assembled from scratch (~10 boards ordered)

## How it works

| Component | Pins |
|---|---|
| LEDs | Arduino-equivalent pins 5, 6, 7 |
| Switches | Arduino-equivalent pins 2, 3, 4 |
| MCU | ATtiny84 |

The game logic runs entirely on the ATtiny84, reading input from the three switches and driving the three LEDs as output/feedback. [Add a line here on the actual game rules — e.g. "press switches in the correct sequence," "reaction-time game," etc.]

## Build notes

- Programmed the ATtiny84 **before** soldering it onto the card, to avoid the risk of a bad reflow bricking a chip I couldn't easily reprogram in place
- [PCB design software, e.g. KiCad — fill in]
- [NFC chip/module used — fill in]
- Ordered ~10 boards for assembly and handout

## What I learned

This was my first time taking a board from schematic to a physically assembled, working product. [Add a specific challenge or fix here — e.g. a routing mistake, a programming gotcha, a soldering lesson. This section is what turns the repo into a portfolio piece, so it's worth a real sentence or two.]

## Hardware files

- [Link to schematic / KiCad project files]
- [Link to BOM (bill of materials)]
- [Link to Gerber files, if included]

## Contact

**Nathaniel Eitneier**
Electrical Engineering, University of Florida
📧 eitneiern@ufl.edu
🔗 [github.com/NathanielEitneier](https://github.com/NathanielEitneier)
