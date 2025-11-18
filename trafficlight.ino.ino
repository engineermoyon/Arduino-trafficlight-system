// variables needed for the traffic light system
int REDLED = 11;
int BLUELED = 12;
int GREENLED = 13; 
int PUSHBUTTON = 2; 

// timing variables, millisecs
unsigned long previousMillis= 0;
int State = 0;
const long redTimer = 5000;   // 5 secs
const long blueTimer = 5000;  
const long greenTimer = 5000; 

// crossing variables for pedestrian
bool cannotCross = false;
bool canCross = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(PUSHBUTTON, INPUT); 
  
  Serial.begin(9600);
  Serial.println("Traffic Light System Begun"); 
}

void loop() {

  unsigned long currentMillis = millis(); 
  // check for button press
  if (digitalRead(PUSHBUTTON) == HIGH && !cannotCross && !canCross) {
    cannotCross = true; 
    Serial.println("Pedestrian pressed the button to want to cross"); 
  }
  
  switch(State){
    case 0:   // what if red must be on for a while?
      digitalWrite(REDLED, HIGH); // RED LED IS ON, ONLY IT
      digitalWrite(BLUELED, LOW); // BLUE OFF
      digitalWrite(GREENLED, LOW); // GREEN OFF

      if (currentMillis - previousMillis >= redTimer) {
        previousMillis = currentMillis;
        State = 1; // transition to the blue led
        Serial.println("RED -> BLUE");
      }
      break;

    case 1: // for the blue led 
       digitalWrite(REDLED, LOW); // RED OFF 
       digitalWrite(BLUELED, HIGH); // BLUE ON
       digitalWrite(GREENLED, LOW); // GREEN OFF

      if (currentMillis - previousMillis >= blueTimer) {
        previousMillis = currentMillis;
        State = 2; // transition to the green led
        Serial.println("BLUE -> GREEN");
      }
      break; 

    case 2: // for the green led 
       digitalWrite(REDLED, LOW); // RED OFF 
       digitalWrite(BLUELED, LOW); // BLUE OFF
       digitalWrite(GREENLED, HIGH); // GREEN ON

      if (currentMillis - previousMillis >= greenTimer) {
        if (cannotCross) {
          allowCrossing();
        }
        previousMillis = currentMillis;
        State = 0; // transition back to red led
        Serial.println("GREEN -> RED");
      }
      break; 
 
  }
}
 

void allowCrossing() {
  Serial.println(" CROSSING CAN HAPPEN- Pedestrian can cross ");
  canCross = true;
  cannotCross = false; 
  
  digitalWrite(REDLED, HIGH); // RED LED IS ON FOR LONGER TO ALLOW CROSSING
  digitalWrite(BLUELED, LOW); // BLUE OFF
  digitalWrite(GREENLED, LOW); // GREEN OFF
  delay(10000); // pedestrian can cross after 10 secs

  canCross = false; 
  Serial.println ("Done crossing the road"); 
}

