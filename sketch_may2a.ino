#include <WiFiNINA.h>

int ledPin = LED_BUILTIN; // Use the built-in LED
int buttonPin = 2;        // Pin for the push button

// Wi-Fi network credentials
const char* ssid = "oplus_co_apdmkd";       // Replace with your network SSID
const char* password = "tohm3279";   // Replace with your network password

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);

  // Set up LED and button pins
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor for the button

  // Attempt to connect to Wi-Fi
  connectToWiFi();
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    // Morse code for "Roshan"
    BlinknameinMorse(".-.");
    BlinknameinMorse("---");
    BlinknameinMorse("...");
    BlinknameinMorse("....");
    BlinknameinMorse(".-");
    BlinknameinMorse("-.");

    // Wait before allowing the button to trigger the sequence again
    delay(5000);
  }
}

void BlinknameinMorse(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      digitalWrite(ledPin, HIGH);
      delay(200); // Dot duration
    } else if (code[i] == '-') {
      digitalWrite(ledPin, HIGH);
      delay(500); // Dash duration
    }
    digitalWrite(ledPin, LOW);
    delay(400); // Short pause between signals
  }
  // Space between letters
  delay(600);
}

void connectToWiFi() {
  // Check for the Wi-Fi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true); // Stop execution here
  }

  // Attempt to connect to Wi-Fi network:
  Serial.print("Connecting to ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, password) != WL_CONNECTED) {
    // Wait 1 second before retrying
    delay(1000);
    Serial.print(".");
  }

  // Connected to Wi-Fi
  Serial.println();
  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
