const int mosfetA = 2;
const int mosfetB = 3;
const int directionPin = 4;
const int onOffSwitch = 5;
const int potPin = A0;
const int enablePin = 9;

int switchState = 0; 
int prevSwitchState = 0;
int directionSwitchState = 0;
int prevDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1; // 1: Clockwise, 0: CounterClockWise
void setup() {
  pinMode(mosfetA, OUTPUT);
  pinMode(mosfetB, OUTPUT);
  pinMode(directionPin, INPUT);
  pinMode(onOffSwitch, INPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
  //digitalWrite(enablePin, HIGH);
  digitalWrite(mosfetA, LOW);
  digitalWrite(mosfetB, HIGH);
}

void loop() {
  switchState = digitalRead(onOffSwitch); // Read the On/Off Status of the Motors
  delay(1);
  directionSwitchState = digitalRead(directionPin); // Read the Direction of the Motor  
  motorSpeed = (analogRead(potPin)/4) ;

  if(switchState != prevSwitchState){ // Trigger when button connected to Pin 5 is pressed
    if(switchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }
  if(directionSwitchState != prevDirectionSwitchState){ // Trigger when button connected to Pin 4 is pressed
    if(directionSwitchState == HIGH){
      motorDirection = !motorDirection; // Changes motorDirection upon button pressed
    }
  }

  if(motorDirection == 1){  // Reverses Polarity when motorDirection is changed
    digitalWrite(mosfetA, HIGH);
    digitalWrite(mosfetB, LOW);
  }
  else{
    digitalWrite(mosfetA, LOW);
    digitalWrite(mosfetB, HIGH);
  }

  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);

  }
  else{
    analogWrite(enablePin, 0);
  }
  prevDirectionSwitchState = directionSwitchState;
  prevSwitchState = switchState;

  Serial.print("OnOffSwitch: ");
  Serial.println(digitalRead(onOffSwitch));
  Serial.print("Direction Pin: ");
  if(Serial.println(digitalRead(directionPin)) == 0){
    Serial.println("CounterClockWise");
  }
  else{
    Serial.println("ClockWise");
  }
  Serial.print("Pot Value : ");
  Serial.println(motorSpeed);

  Serial.print("Enable ");
  Serial.println(digitalRead(enablePin));
  Serial.print("Mosfet A: ");
  Serial.println(digitalRead(mosfetA));
  Serial.print("Mosfet B: ");
  Serial.println(digitalRead(mosfetB));
  //delay(10);




}
