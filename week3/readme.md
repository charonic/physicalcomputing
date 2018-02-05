[Video Link]: https://youtu.be/Sf8oKlcvKY8 
![Project 2 Image](physicalcomputing/week3/IMG_1347)

# Project 2 Process:
   Setup so that all my gear is close at hand and the book is open.
   Review what exactly everything is.
   1. Wire 5V to the highest voltage area, the + row on the power bus
   2. Slot in a wire from the GND to the the low voltage areas
   3. slot in 2 Red LEDs and a Green LED, making sure that the cathodes are all facing the top of the breadboard
   4. slot in 4 resistors, making sure they in the same row as their respective LED cathodes to the negative columns on the power bus
   5. connect the anodes to different slots, 4-5 for the red LEDs and 3 for the green LED
   6. slot in the button on the breadboard
   7. rig the button so the top half goes into the positive column
   8. the bottom half is where the 10k-ohm resistor slots in
   9. the bottom side of the switch is attached to pin 2. 
   10. Coding
   11. Define the interger of the switchState to = 0  int switchState = 0;
   12. define which pin is an INPUT or an OUTPUT for pins 2-5
     12a. pinmode(3,OUTPUT);
   13. define the switchState to be switchStatae = digitalRead(2);
     13a. when the pin has power surging through it, the switchState == HIGH
   14. Define a default state, if the switchState does not have power surging through it(pin 2 does not have power through it) then the Red LEDs are dim and the Green LED is active.
   15. Define what happens if the switchState == HIGH. Green is LOW, Red1 is LOW and Red2 is High, this set up allows me to make the blinking LEDs but making sure one LED starts off the alternating blinking process.
   16. code out the blinking proccess, ensuring there is a delay so that human eyes can process the change.
   17. take video of arduino once the code is clean.
   18. upload stuff
    