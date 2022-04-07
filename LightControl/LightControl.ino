/*
 * The Arduino will read in a string from Serial and then
 * update the approperiate digital out state.
 * 
 */

int channels[] = {0,1,2,3,4};
int prevState[4];
int currentState[] = {0,0,0,0,0};

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
    String currentState = Serial.readString();
    Serial.println(currentState);
    for (int i=0; i < sizeof(channels) -1 ; i++){
      if(currentState[i] == '0'){
        digitalWrite(channels[i], LOW);
        prevState[i] = currentState[i];
        Serial.println("Turned off line: " + String(channels[i]));
      }
      else if(currentState[i] == '1'){
        digitalWrite(channels[i], HIGH);
        prevState[i] = currentState[i];
        Serial.println("Turned on line: " + String(channels[i]));
      }
      else{
        Serial.println("Transmission had an error! currentState: " + String(currentState[i]) + " PrevState: " + String(prevState[i]));
      }
      
    }
  }

}
