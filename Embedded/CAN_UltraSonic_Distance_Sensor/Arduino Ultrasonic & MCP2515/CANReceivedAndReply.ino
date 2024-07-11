#include <SPI.h>
#include <mcp_can.h>

// Define the CS pin for the MCP2515
const int CS_PIN = 10;
MCP_CAN CAN(CS_PIN);

// Define Pins for UltraSonic Sensor
const int trigPin = 6;
const int echoPin = 5;

// Variable for Ultrasonic Sensor
float duration; 
float distance;

void setup() {
  Serial.begin(9600);
  SPI.begin();

  pinMode(trigPin, OUTPUT); // Output a Signal to Start Transmission
  pinMode(echoPin, INPUT);  // Pin 5 Receives the Echoed Signal Bad
  // Initialize CAN with Buadrate of 500 kbps at 8Mhz, with no Filters 
  if (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) { // No filter since there is 2 Nodes Send/Receive are End-to-End
    Serial.println("CAN initialization successful!");
  } else {
    Serial.println("Error initializing CAN...");
    while (1);  // Halt the program
  }
  // Allow the Arduino Uno to Rx and Tx CAN Messages
  CAN.setMode(MCP_NORMAL);

}

void loop() {
  // Init Variables for CAN Message ID, Data Length, Data in Buffer, and Extended Message True/False
  unsigned long id;
  unsigned char len;
  unsigned char buf[8];
  unsigned char ext;
  // Check if there is any CAN messages in Buffer
  if (CAN_MSGAVAIL == CAN.checkReceive()) {
    CAN.readMsgBuf(&id, &ext, &len, buf);
    // STM32F446RE's CAN Remote Frame Request ID is 0x100
    // Display the Info of Message if Remote Request Received
    if((id & 0x100) == 0x100){    
      Serial.println(" REMOTE REQUEST FRAME");
      //Prints CAN Message ID
      Serial.print("ID: ");
      Serial.print(id, HEX);
      //Prints whether CAN Message is Extended 
      // 1 = Extended
      // 0 = Standard
      if (ext) {
        Serial.print("  Extended ID");
      } else {
        Serial.print("  Standard ID");
      }
      //Print Data Length
      Serial.print("  DLC: ");
      Serial.println(len);
    // CODE For Ultrasonic Sensor 
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); // Delay for 2 microsecond to prepare for trigger HIGH

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Delay for 10 microsecond for 8 ultrasonic brust

    // If No objects, The Pulse time out after 38ms and goes back to low state

    digitalWrite(trigPin, LOW);

    // Clear Variables
    memset(&duration, 0, sizeof(duration));
    memset(&distance, 0, sizeof(distance));
    // Reads the Pulse travel time in microseconds
    duration = pulseIn(echoPin, HIGH);  // Lisen or wait for wave to be reflected back
    distance = duration * 0.034/2; // D = V*T, where 0.034 is cm/microsecond
    // Serializes Float Distance to Long then to Byte(HEX)
    Serial.println(distance);
    long intValue = static_cast<long>(distance * 100.0);
    Serial.println(intValue);
    byte data[sizeof(long)];
    memcpy(data, &intValue, sizeof(long));
    byte sndStat = CAN.sendMsgBuf(0x202, 0, sizeof(long), data);
    //Check if CAN Reply is Send Successfully
    if(sndStat == CAN_OK){
      Serial.println("Message Sent Successfully!");
    } else {
      Serial.println("Error Sending Message...");
    }
    delay(500);
  // If not Remote Request, Display Info 
  } else {
    Serial.println("DATA FRAME");
    Serial.print("ID: ");
    Serial.print(id, HEX);
     if (ext) {
        Serial.print("  Extended ID");
      } else {
        Serial.print("  Standard ID");
      }
      Serial.print("  DLC: ");
      Serial.println(len);
    for (int i = 0; i < len; i++) {
        Serial.print(buf[i], HEX);
        Serial.print("\t");
      }
     
  }  
  delay(100); 
}}