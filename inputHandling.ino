/**
 * Checks to see if the button is pressed an reacts accordingly.
 * @param button The pin number for the button the user interacts with.
 * @param currentLed The currently light LED.
 * @param score The current number of points earned by the player.
 * @param interval The number of milliseconds to wait before changing lights.
 * @param highScore The highest score recorded.
 */
void checkButton(int button, int8_t& currentLed, unsigned int& score, unsigned int& interval, unsigned int& highScore)
{
  if (digitalRead(button) == LOW)
  {
     checkLed(currentLed, score, interval, highScore);
  }
}

/**
 * Checks the current LED to see if it matches the center LED. If it does, the score is
 * updated, if not the score is compared to the high score which is then set to be equal
 * to score if score is greater. Afterward, there is a 1 second delay afterwhich the current
 * LED is set to low and then set to 0, then set to high.
 * @param currentLed The currently light LED.
 * @param score The number of points earned by the user.
 * @param itnerval The number of seconds to wait before switching LEDs.
 * @param The highest score recorded.
 */
void checkLed(int8_t& currentLed, unsigned int& score, unsigned int& interval, unsigned int& highScore)
{
  if (currentLed == 6)
  {
    score++;
    lcd.setCursor(7,0);
    lcd.print(score);
    interval *= .90;
  }
  else
  {
    lcd.setCursor(7,0);
    lcd.print("0        ");
    interval = BASE_INTERVAL;
    
    if (score > highScore)
    {
      highScore = score;
      lcd.setCursor(10,1);
      lcd.print(highScore);
    }
    
    score = 0;
  }

  delay(1000);
  digitalWrite(currentLed, LOW);
  currentLed = 0;
  digitalWrite(currentLed, HIGH);
}
