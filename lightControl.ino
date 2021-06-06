/**
 * Checks to see if it's time to change lights and changes if it is time to do so
 * @param LEDs An array of LEDs where each element represents a pin in connected to an LED.
 * @param currentLight The currently light LED.
 * @param startTime The time currentLed was set to high.
 * @param interval The number of milliseconds to wait before changing lights.
 * @param ascend True if interating through array from lowest to highest, else false.
 */
void changeLight(const int8_t LEDs[], int8_t& currentLight, unsigned int& startTime, unsigned int interval, bool ascend)
{
  if (millis() > startTime + interval)
  {
    if(ascend)
    {
      digitalWrite(LEDs[currentLight], LOW);
      currentLight++;
      digitalWrite(LEDs[currentLight], HIGH);
    }
    else
    {
      digitalWrite(LEDs[currentLight], LOW);
      currentLight--;
      digitalWrite(LEDs[currentLight], HIGH);
    }

    startTime = millis();
  }
}

/**
 * Sets the direction of the LEDs
 * @param dir True if direction is ascending
 *    (moving from lowest to highest element in array),
 *    else false
 * @param LED The currently light LED.
 */
bool setDirection(bool dir, int LED)
{
   if (dir && LED != 12)
    return true;
   else if (!dir && LED == 0)
    return true;
   else
    return false;
}
