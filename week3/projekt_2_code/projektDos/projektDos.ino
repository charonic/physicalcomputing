const int ledPin = 2;
const int ledPin1 = 3;
const int switchPin= 4;
//space is allocated in the arduino and saving 2/3 here


//#define ledP0 2
// whenever the code sees ledP0, it's replaced with 2

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
// opens up the serial port, a highway?, 9600 here refers to bits per second
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int switchPinRead = digitalRead(4);
 Serial.print("Switch 0 Value:");
 Serial.println(switchPinRead);

digitalWrite(2,switchPinRead);
digitalWrite(3,switchPinRead);

 
  
}
