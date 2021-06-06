/*********************************************
 * Program: LED Light Game
 * Programmer Adam Guidarini
 * Date: 2021-6-6 
 * 
 * Objective: Press the button while the LED
 * in the center is light
 * 
 * Validated on a Raspberry Pi Pico.
 *********************************************/

#include<LiquidCrystal.h>
#include<stdint.h>

#define BUTTON 13
#define BASE_INTERVAL 500

LiquidCrystal lcd(16, 17,  18, 19, 20, 21);

// Set pin for button and array of pins for LEDs
const int8_t LED_PINS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int8_t currentLED = 0;

unsigned int interval = BASE_INTERVAL;
unsigned int timeLastStart = 0;
int timeMoveToNext = 0;

unsigned int score = 0;
unsigned int highScore = 0;

bool ascend = true;

/**
 * Initializes LCD display, outputs for LEDs, and input for button.
 */
void setup() 
{
  Serial.begin(9600);
  
  for(int i = 1; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(BUTTON, INPUT_PULLUP);
  digitalWrite(LED_PINS[0], HIGH);
  
  lcd.begin(16,2);
  
  lcd.print("Score: ");
  lcd.print(score);
  lcd.setCursor(0,1);
  lcd.print("Hi Score: ");
  lcd.print(highScore);

  timeLastStart = millis();
}

/**
 * Checks whether or not to change the direction of lights,
 * checks if a light needs to be changed or not, then checks
 * whether or not the button is pressed.
 */
void loop() 
{
  ascend = setDirection(ascend, currentLED);
  changeLight(LED_PINS, currentLED, timeLastStart, interval, ascend);
  checkButton(BUTTON, currentLED, score, interval, highScore);
}
