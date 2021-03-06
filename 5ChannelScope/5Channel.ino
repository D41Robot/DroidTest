/* CommaDelimitedOutput sketch */
#define ANALOG_IN_Ch1 0
#define ANALOG_IN_Ch2 1
#define ANALOG_IN_Ch3 2
#define ANALOG_IN_Ch4 3
#define ANALOG_IN_Ch5 4

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int val1 = analogRead(ANALOG_IN_Ch1); /* Reads values from analog Pin0 = Channel1 */
  int val2 = analogRead (ANALOG_IN_Ch2); /* Reads values from analog Pin1 = Channel2 */
  int val3 = analogRead (ANALOG_IN_Ch3); /* Reads values from analog Pin2 = Channel3 */
  int val4 = analogRead (ANALOG_IN_Ch4);
  int val5 = analogRead (ANALOG_IN_Ch5);

  Serial.print('H'); /* Unique header to identify start of message */
  Serial.print(",");
  Serial.print(val1,DEC);
  Serial.print(",");
  Serial.print(val2,DEC);
  Serial.print(",");
  Serial.print(val3,DEC);
  Serial.print(",");  
  Serial.print(val4,DEC);
  Serial.print(",");
  Serial.print(val5,DEC);
  Serial.print(","); /* Note that a comma is sent after the last field */
  Serial.println();  /* send a cr/lf */
  delay(50);
}