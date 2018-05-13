# Mancala
Final Documentation 

# What is the Title of your Project:
Dropbead, short and simple and it hearkens to a very commonly played variant of Mancala in the U.S..


![boxedup](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/boxedup.JPG)

# Overview
This project revolves around building a Mancala (subtype Kalah) game using Arduino. If the base system can run, then steps can be taken to eventually make this project more acessible. It is the intent of the project in the long term to imitate the feel of Mancala with appropriate sounds, but the current focus is getting the base game flow down.



# Why did you want to make this project?
A cheeky answer is that my dreams are bigger than my hands can hold. The real answer is that when prompted this was the very first thing to pop into my head. Why Mancala over literally anything including refining my Midterm for an easier time? There's no answer, Dropbead can actually be changed to offer ease of access to some folks in the future.

# Form factor/ideal size?
Ideally it would be relatively small, currently I'm thinking about as long as a PS Vita, but alas it's boxy and clunky as it's attached to a breadboard.
![skeleton](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/buttonworks.JPG)
 ## Input
    There are two, the potentiometer and the button. The former will dictate the cursor in the LCD, the latter will fire off the code that moves the beads.
    In a game, a player will be watching an LCD, and will decide which hole they'll move the beads through. Once they decided they'll use the potentiometer to move from hole to hole, once they've reached the desired hole, they'll press the button. The button will fire code that will move the "beads" from hole to hole, automating the process.
### Components:
Potentiometer: Done on the advice of a teacher, the potentiometer will dictate which hole you'll move your "beads" from. Two were needed for this project.
Button : This is more of a future placeholder, in the future, a Dropbead can be modified to compensate for the level of disability its user may or may not have. 

## OutPut
The only output is the LCD, or liquid crystal display. OF the pieces and bits inside the arduino starter kit, only the LCD was capable of displaying anything close to a Mancala board, though in writing this I wonder if I could have used a sound based series of out puts to create a Mancala playable with only sounds and the previous inputs.

## Parts
Potentiometer
Wiring
Resistor
220 ohm resistor
10k ohm resistor
LCD monitor
Button
 

# Research 
## Mancala
This board game has been around for quite some time and has many different variations depending on region. The version being used in this project is Kalah, two rank Mancal.

### The Game
A Kalah board is comprised of six consecutive holes and a store for one side and six consecutive holes and a store for the other.
                                        S1  0 0 0 0 0 0 S2
                                        S1  0 0 0 0 0 0 S2 
Each hole will be filled with 4 beans/beads. A player will strategically move the beans from hole to hole in a counter-clockwise manner, depositing one bean in each hole until they run out. Depositing beans in their own Store gains points, should the player run into the opponent's store, they skip it.

The game itself ends when all six holes on one side of the board are empty. If a player still has beans on their side of the board they score those beans.
The person with the most points in their own store wins.


Instead of buttons, use a potentiometer for selection, truthfully it was suggested, but also there isn't enough space on the standard arduino breadboard to host 12 buttons.


#### Coding  
##### Pre void setup:


![Presetup](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/Presetup.PNG)
First, gonna slap in the LCD Library with #include <LiquidCrystal.h>, then you have to tell it what pins you're going to use to interact with the LCD, for this we'll use the following: LiquidCrystal lcd(12,11,5,4,3,2);. 
 * LCD 12: Pin 4
 * LCD 11: Pin ~5
 * LCD 5: Ground
 * LCD 4: Pin 12
 * LCD 3: Potentiometer
 * LCD 2: Power

mancalaGame[] is an array that'll hold the elements of the gameboard. 
player1goal/player2goal: Sets the goals, or S1/ S2 in the above diagram while the player1score/player2score sets the goal.

int const potPin = A0:is to set up the potentiometer that will control the cursor in the lcd.
int potVal: sets up the values of the potentiometer, use primarily to test the potentiometer in Serial.
int selector: this was chosen to map the values of the potentiometer to the constraints of the mancalaGame.

const int confirmButton: sets the pin of the button that will be the confirm button.
int buttonState: setting this to 0 will prevent the button from firing off immediately.
int switchRead: set up so that the button will fire once when pressed and only once in tandem with a digitalRead and a boolean.

bool pressing: the previously mentioned boolean
bool gameOver: if the game is over this will be set to false.

int mancounter:used primarily in the mancalaGame, it defines the current "hole" used in the game state.

##### void setup(){}
![setupcode](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/setup.PNG)

lcd.begin(16,1); tell the LCD that it'll be firing off on 16 columns for 1 rows.

pinMode(confirmButton, INPUT); confirmbutton is confirmed as an input that will setup a button.
pinMode(12, OUTPUT); pin 12 will be confirmed as an output, in this case it's the LCD.





##### void loop(){}
![gameboardcode](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/gameboard.PNG)
   potVal = analogRead(potPin); - used primarily in the Serial, it allowed to check if the potentiometer itself worked.
  selector = map(analogRead(A0), 0, 1023, 1, 13); - mapped the potentiometer to values 1-13, which in this case would be the mancalagame board, array elements 0 and 14 are gated to prevent the player from accidently selecting them and emptying them into holes. 



 if (selector == mancounter) {       
    lcd.print("_");
  } else if (mancounter < 7) {
    lcd.print(mancalaGame[mancounter]);
  } else if (mancounter == 7) {
    lcd.print(" ");
  } else if (mancounter > 7  && mancounter < 15) {
    lcd.print(mancalaGame[mancounter - 1]);
  } else {
    lcd.print(" ");
  }

  mancounter++;
  if (mancounter > 15) {
    mancounter = 1;
  }

The first line sets an active, blinking cursor that tells the user where they're at the moment.
The second line writes out the first 7 elements of the game board by printing it out from array elements 0-6 on the lcd.
the third line places a space between the two "sides" of the board by sperating them with a space on element 7.
The fourth line fills out the board from elements 8-14, but treats the each element as one less than it.
Mancounter++ increments the counter so the lcd will print in series.
the last line sets the counter back to the start, if the counter is incremented beyond 15 (the scope of the array), it'll reset to 0.


![buttoncode](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/buttonfiring.PNG)
switchRead = digitalRead(confirmButton);
  if (switchRead == 1) {

    pressing = true;


  }
Switchread is normally 0, but when pressed and digitally read it'll flip to 1 which makes the pressing state true, this will fire the next line.

if (switchRead == 0 && pressing == true) {                             this checks if the button is no longer pressed and the pressing state is true
    pressing = false;                                                  this sets pressing to false again, allowing the button to fire off again 
    if (gameOver != true); {int currentHole = mancalaGame[selector];   checks to see if the game is over, if it isn't then it fires the code, the first of which is used to check the value in Serial.
      // A: Empty from the current hole
      mancalaGame[selector] = 0;  this empties the hole, mimicking beads being picked up and moved.
      Serial.println(currentHole);

      // B: Add to the following holes//
for (int i = 0; i < currentHole; i++) {    
 int curPosition =  selector + i + 1;
 mancalaGame[curPosition] =  mancalaGame[curPosition] + 1;
     Compiled together this will allow the gamestate to advance by adding 1 to each subsequent hole depending on the amount of "Beads" in the chosen hole.
     
     
     // C: Skip 7
if (selector == 7 );
curPosition = 8;
// mancalaGame[curPosition] = manacalaGame[curPosition] + 1;
     
This is the part of the code that didn't even trigger properly, as the code it is now, the player 2 gameboard is out of sync, the game works off array element 7 despite it not being something it shouldn't interact with. Trying to set 7 to element 8 doesn't actually work with the code written above.
     
     }

    }

    counter++; mainly for checking if the button has successfully been released.

  }
}



![whowon?](https://github.com/charonic/physicalcomputing/blob/master/Final/Images/whowon.PNG)
void whoWon() { /*function definition not allowed before {*/

  if (mancalaGame[1] == 0 && mancalaGame[2] == 0 && mancalaGame[3] == 0 && mancalaGame[4] == 0 && mancalaGame[5] == 0 && mancalaGame[6] == 0) {
    gameOver = true;
  } else if (mancalaGame[7] == 0 && mancalaGame[8] == 0 && mancalaGame[9] == 0 && mancalaGame[10] == 0 && mancalaGame[11] == 0 && mancalaGame[12] == 0) {
    gameOver = true;

Checks to see if a game state has entered the finished state as defined by Kalah rules, if any side of the board is completely empty the game will end.
    
    
    if (gameOver = true && player1score > player2score) {
      lcd.clear();
      lcd.print("Player 1 wins!");

    } else {
      if (gameOver = true && player2score > player1score) {
        lcd.clear();
        lcd.print("Player 2 Wins!");

Once the game has ended, it checks player scores and prints out a winner message.

 
Here's a link to see how it functions currently: [KalahLink](https://youtu.be/QYiy4KO1WuQ)

# High Priority fixes
## Fixing the 7 element in the array
Player 2's board state actually starts in element 7, the code to add "works" otherwise, leading to each button press to activate the hole in front of the one chosen.
### Bead caryover.
Player 1's beads won't enter their goal with how the game is currently set up.

#### Game End
When a player board state is set to all 0, the lcd simply reprints the original board state.




### Changes for the Future

##### Rule 1: Free Turn
If you drop the last of your beans within your own store, you receive an Extra Turn, adding this so that it reflects the same type of Mancala I played would be nice.


##### Rule 2: Capture
Should the last piece you drop land in an empty hole on your side, you capture any pieces in the opponents hole directly opposite to it.
adding this so that it reflects the same type of Mancala I played would be nice.

##### Turn System
Right now the system relies on good faith, making an actual turn order system will make it more official.




