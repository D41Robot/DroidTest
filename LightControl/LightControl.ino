/*
 * The Arduino will read in a string from Serial and then
 * update the approperiate digital out state.
 * 
 * The user only needs to type a string as long as the number 
 * of channels being used
 */

int channels[] = {13,12,11,10,9}; //The Digital Pins in use


void setup(){
  Serial.begin(9600);
  Serial.println("Welcome to the interface");
}

void loop() {
  if (Serial.available())
  {
    String currentIn = Serial.readString();
    Serial.println(currentIn);
    //Only go through the characters of interest.
    for (int i=0; i < 5 ; i++){
      //If the selected channel control is 0 turn off
      if(currentIn[i] == '0'){
        pinMode(channels[i], INPUT);
        digitalWrite(channels[i], LOW);
        Serial.println("Turned off line: " + String(channels[i]));
      }
      
      //If the selected channel control is 1 turn on
      else if(currentIn[i] == '1'){
        pinMode(channels[i], OUTPUT);
        digitalWrite(channels[i], HIGH);
        Serial.println("Turned on line: " + String(channels[i]));
      }
      
      //something else was found in the message
      else{
        Serial.println("Transmission had an error!");
      }  
    }
  }
}
