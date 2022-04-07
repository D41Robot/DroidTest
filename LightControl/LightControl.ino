/*
 * The Arduino will read in a string from Serial and then
 * update the approperiate digital out state.
 * 
 */

int channels[] = {0,1,2,3,4}; //The Digital Pins in use
//int prevState[4];
//int currentState[] = {0,0,0,0,0};

void setup(){
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  Serial.begin(9600);

  Serial.println("Welcome to the interface");
}

void loop() {
  if (Serial.available())
  {
    String currentIn = Serial.readString();
    Serial.println(currentIn);
    //Only go through the characters of interest.
    for (int i=0; i < sizeof(channels) -1 ; i++){
      //If the selected channel control is 0 turn off
      if(currentIn[i] == '0'){
        digitalWrite(channels[i], LOW);
        //prevState[i] = currentIn[i];
        Serial.println("Turned off line: " + String(channels[i]));
      }
      //If the selected channel control is 1 turn on
      else if(currentIn[i] == '1'){
        digitalWrite(channels[i], HIGH);
        //prevState[i] = currentIn[i];
        Serial.println("Turned on line: " + String(channels[i]));
      }
      //something else was found in the message
      else{
        Serial.println("Transmission had an error!");
      }
      
    }
  }

}
