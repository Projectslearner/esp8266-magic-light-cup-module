/*
    Project name : ESP8266 Magic light cup module
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-magic-light-cup-module
*/

const int magicLightCupPin = D1; // Digital pin connected to the Magic Light Cup module

void setup() {
  pinMode(magicLightCupPin, INPUT); // Set the pin as input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the state of the Magic Light Cup module
  int sensorValue = digitalRead(magicLightCupPin);

  // Print the state to the Serial Monitor
  Serial.print("Magic Light Cup State: ");
  Serial.println(sensorValue);

  // Check if light is detected and print the result
  if (detectLight(sensorValue)) {
    Serial.println("Light Detected");
  } else {
    Serial.println("No Light Detected");
  }

  delay(1000); // Add a small delay to avoid spamming the Serial Monitor
}

bool detectLight(int value) {
  // Define the threshold value for light detection
  const int threshold = 500;

  // Check if the sensor value is above the threshold
  return value > threshold;
}
