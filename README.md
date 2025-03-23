# LED Brightness Control with Switches using PWM

This project demonstrates basic PWM (Pulse Width Modulation) control using two switches to adjust an LED's brightness on an AVR microcontroller. Pressing Switch 1 lights the LED at low brightness, Switch 2 increases it to medium brightness, and pressing both switches together sets the LED to maximum brightness. If no switches are pressed, the LED remains off. The implementation uses Timer0 in Fast PWM mode with different duty cycles mapped to switch states for brightness control.
