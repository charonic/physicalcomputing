Fortune Telling with Sticks!

# Item List:
*	Tilt Sensor
*	220 ohm resisters
*	LCD Monitor 
*	10k ohm Resister
*   Various Length of Jumper Wire
	
	
# Premise:
	Based off Chinese stick fortune telling, the user will tilt the sensor and then receive a random fortune that will read out on the LCD monitor.
    
# Why did I choose this project:
It combined two things; projects I believe I can do and a flash of inspiration. I don't know why I first thought of stick fortune telling but that's the first one that came to mind.

# Size:
Hopefully this'll be something small and compact. Ideally it would basically be something small enough to fit in a bag or pocket so you could take it out, give the lever a shake and then get a fortune.

# Coding thoughts:
1.	Make an array that contains X amount of fortunes.
2.	Make the tilt sensor an INPUT that that causes an element of the array to be randomly chosen.
3.	Once the element is chosen, it will be displayed on the LED
## Inputs:
    * Should just be the tilt sensor, the user will tilt the sensor and receive a fortune displayed on the lcd.
    * This was the only component that I felt mimicked the actual stick part of fortune telling.
    
## Outputs:
    * The LCD is the only component in this kit that actually displays text, which seems like it'd be really valuable in fortune telling, I suppose I could have chosen to draw out a color guide, red is bad green is good but text is more elegant. Plus I've never used the LCD.
    

# Actual Process:
Going through the book, it’ll be easy to split this into two parts


# Tilt Sensor
 The simplest part of this project, I can take the coding used in Project 8: Digital Hourglass.
 *  Declare a switchPin, a constant variable, the pin it’ll start on is 8.
 *  Create two variables
    Int switchState = 0; will cover the switchstate received
    Int prevSwitchState = 0; will allow the former variable to be compared, which should tell the rest of the Arduino to trigger a fortune.
    Void setup(){pinMode(switchPin,INPUT);} should declare that the variable switchPin will be an input.
* Void loop(){
   switchState = digitalRead(switchPin);} reads if the switch has been tilted.
   if(switchState != prevSwitchState){} should run the lcd code one the switchState has been activated.
   prevSwitchState = switchState; the last part of the loop code will remember the statue of the switchState so that the next loop has something to compare the switchState with. 
 # LCD
    The LCD project in chapter 11  is pretty much the project I was thinking about, but with LCD code instead of an array.
 * #include <LiquidCrystal.h>  there is an actual library for the LCD, so gotta slap that in there.
 * LiquidCrystal lcd(12,11,5,4,3,2); the numbers here are just to tell the arduino what pins it'll be using.
 * int reply; this will basically hold the chosen reply.
 
 * void setup(){lcd.begin(16,2);}  this will tell the arduino how large the screen is, 16 across, two lines.
 ** I didn't even consider this, but instead of writing out instructions on the box, having the instructions read accross the LCD to start is solid.
 *** lcd.print("Flick the switch"); so it reads this across the top line
 *** lcd.setCursor(0,1); the arduino is dumb, so apparently you need to set the cursor to the second line manually
 *** lcd.print(" get a fortune"); continues the message.
 
 * void loop(){if(switchState != prevSwitchState)
 * reply = random(6);  ///so when the switchState is changed reply is given a number 0-6 
 * lcd.clear();        /// clears the starting message 
 * lcd.setCursor(0, 0);  ///resets the cursor 
 
 * Here's an example of a random case: 
 * switch(reply){
 * case 5:
 * lcd.print("Burning ship ahead"); 
 * break;
  } 
Seems like the switch() is an array? I'm not quite sure why it's displayed like this.


# Surprises
    I had started the project determined to make it work with limited space, so I didn't even consider using the potentiometer. 30 minutes later of frustrated reading I realized that the screen contrast was waaaaay too high. So the code functioned, the wiring was fine, it just didn't display. Always read why people added components kids.
    
# To the future!
    Getting a wider/longer LCD would be nice, 32 characters split between two rows is pretty inelegant.
    Finding a better box would be solid, also working with longer wiring or better adhesive's is a must, soldering solves the former, resources the latter.
    
    
    
    
    Here's a link to the video: https://youtu.be/3BSpNflJNSc