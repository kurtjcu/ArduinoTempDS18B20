
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// using the onboard led
int led = 13;
float temp = 0;

void setup(void) 
{ 
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);    
  // start serial port 
  Serial.begin(9600); 
  Serial.println("Dallas Temperature IC Control Library Demo"); 
  // Start up the library 
  sensors.begin(); 
} 

void loop(void) 
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus 

  Serial.print(" Requesting temperatures..."); 
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  Serial.println("DONE"); 

  temp = sensors.getTempCByIndex(0); // Why "byIndex"?  
    // You can have more than one DS18B20 on the same bus.  
    // 0 refers to the first IC on the wire 

  Serial.print("Temperature is: "); 
  Serial.println(temp);

  if(temp > 25 && !digitalRead(led) ){
    Serial.println("Turning on LED");
    digitalWrite(led, true);
  } else if(temp <= 25 && digitalRead(led)) {
    Serial.println("Turning off LED");
    digitalWrite(led, false);
  }

  delay(1000); 
} 
