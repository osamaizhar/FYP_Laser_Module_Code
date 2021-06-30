/*
 Created by Rui Santos
 
 All the resources for this project:
 http://randomnerdtutorials.com/
 
 Based on some Arduino code examples 
*/

// include the library code
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int potPin = A1;       // Analog pin 0 for the LED brightness potentiometer
//int ledPin = 6;        // LED Digital Pin with PWM
int potValue = 0;      // variable to store the value coming from the potentiometer
int brightness = 0;    // converts the potValue into a brightness 
int pBari = 0;         // progress bar
int i = 0;             // foor loop
int count = 0;
int detect = A0;
//int buzzer  = 8;
int ledPin = 8;
int button = 6;
int object1 ;
int object2 ;
int object3 ;
int object4 ;

//progress bar character for brightness
byte pBar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void setup() {
  // setup our led as an OUTPUT
  pinMode(ledPin, OUTPUT); 
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD
  lcd.print("Start Counter");
  //Create the progress bar character
  lcd.createChar(0, pBar);
  pinMode(button ,INPUT);
//pinMode(ledPin,OUTPUT);
//pinMode(buzzer,OUTPUT);
Serial.begin(9600);
Serial.println("Start your counting");

}

void loop() {
  // clears the LCD screen
  lcd.clear();
  // Print a message to the LCD
  //lcd.print(" Start Counter");
  //delay(750);
  //lcd.clear();
  //set the cursor to line number 2
  lcd.setCursor(0,1);
  // read the value from the potentiometer
  potValue = analogRead(potPin);        
  // turns the potValue into a brightness for the LED
  brightness=map(potValue, 0, 1024, 0, 255); 
  //lights up the LED according to the bightness
  analogWrite(ledPin, brightness); 
  // turns the brighness into a percentage for the bar 
  pBari=map(brightness, 0, 255, 0, 17);
  //prints the progress bar
 // for (i=0; i < pBari; i++)
  //{
   // lcd.setCursor(i, 1);   
    //lcd.write(byte(0));  
  //}
  // delays 750 ms
  delay(750);
  back:
    int object = analogRead(detect);
    int b=digitalRead(button);
    object1 = object;
    object2 = object1;
    int back;


   if ( (object2>100) && (object3>100) && (object4>100)){
    //count = 00000;
    
    Serial.println("Object static");
    lcd.print("Object static");
    lcd.print("count:");
    lcd.print(count);
    delay(750);
    lcd.clear();
    Serial.print("Current Counter:" );
    Serial.println(count);
    //delay(1000);
    goto back;
    
   }

    if (object >= 100){
      objectisthere();
    }
    if (count == 10){
      count = 0;
      Serial.println("-------------------");
      Serial.println("");
      Serial.println("Start the new counting");
      Serial.print("Counter: ");
      Serial.println(count);
    }
    object3 = object2;
    object4 = object3;
    //delay(100);
        
}
void objectisthere()
{
  digitalWrite(ledPin,HIGH);
  //tone(buzzer,5600,300);
  count =count + 1;
  Serial.print("Counter:");
  Serial.println(count);
  delay(400);
  digitalWrite(ledPin,LOW);
  
}
