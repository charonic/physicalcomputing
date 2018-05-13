

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


String inputString = "";
boolean stringComplete = false;



int mancalaGame[] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0}; /*8-13 =p2*/
int player1goal = 0;
int player2goal = 14;

int player1score = mancalaGame[player1goal];
int player2score = mancalaGame[player2goal];

int arraySelector;

int const potPin = A0;
int potVal;
int selector;

const int confirmButton = 8;
int buttonState = 0;
int switchRead = 0;
int counter = 0;

bool pressing = false;
bool gameOver = false;
bool moveBead = false;

int mancounter = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(confirmButton, INPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  //  int arraySelector = inputString.toInt();
  //   lcd.print(mancalaGame[arraySelector]);
  //  lcd.cursor();
  //
  potVal = analogRead(potPin);
  //  /* Serial.print("potVal: ");
  //    Serial.print(potVal);*/
  selector = map(analogRead(A0), 0, 1023, 1, 13);
  //  lcd.setCursor(selector, 0);
  //

  // for (int i = 0; i < 16; i++) {
  if (mancounter == 0) {
    lcd.setCursor(0, 0);
  }

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
  if (mancounter > 16) {
    mancounter = 0;
  }
  /*// Check if Game has ended
    if (mancalaGame[1] == 0 && mancalaGame[2] == 0 && mancalaGame[3] == 0 && mancalaGame[4] == 0 && mancalaGame[5] == 0 && mancalaGame[6] == 0) {
    gameOver = true;
    } else if (mancalaGame[7] == 0 && mancalaGame[8] == 0 && mancalaGame[9] == 0 && mancalaGame[10] == 0 && mancalaGame[11] == 0 && mancalaGame[12] == 0) {
    gameOver = true;
    } else {
    gameOver = false;
    }*/



  switchRead = digitalRead(confirmButton);
  if (switchRead == 1) {

    pressing = true;


  }
  if (switchRead == 0 && pressing == true) {
    pressing = false;
    if (gameOver != true); {
      //Read what current hole is. Seemingly Done
      //Move the Beads, when pressed on the current hole, beads. Seemingly Done



    }

    int currentHole = mancalaGame[selector];
    // A: Empty from the current hole
    mancalaGame[selector] = 0;
    Serial.println(currentHole);


    // B: Add to the following holes//

    for (int i = 0; i < currentHole; i++) {

      int curPosition =  selector + i + 1;
      mancalaGame[curPosition] =  mancalaGame[curPosition] + 1;


      // C: Skip 7
      if (selector == 7 );
      //      lcd.clear();
      //    lcd.print(mancalaGame[mancounter]);
      //  lcd.setCursor(1, 2);
      //lcd.print("Sorry this one doesn't work!");
      curPosition = 8;

     // mancalaGame[curPosition] = manacalaGame[curPosition] + 1;




    }




  }




counter++;

}



void whoWon() { /*function definition not allowed before {*/

  if (mancalaGame[1] == 0 && mancalaGame[2] == 0 && mancalaGame[3] == 0 && mancalaGame[4] == 0 && mancalaGame[5] == 0 && mancalaGame[6] == 0) {
    gameOver = true;
  } else if (mancalaGame[7] == 0 && mancalaGame[8] == 0 && mancalaGame[9] == 0 && mancalaGame[10] == 0 && mancalaGame[11] == 0 && mancalaGame[12] == 0) {
    gameOver = true;
    if (gameOver = true && player1score > player2score) {
      lcd.clear();
      lcd.print("Player 1 wins!");

    } else {
      if (gameOver = true && player2score > player1score) {
        lcd.clear();
        lcd.print("Player 2 Wins!");
      }
    }
  }
}











































/*loop closed*/


