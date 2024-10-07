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
    if (Serial.available() > 0) 
    { 
      String name = Serial.readString(); // Read the entire input as a string
      Converttomorsecode(name);
      delay(5000); // Wait before allowing another button press
    }
  }
}


void Converttomorsecode(String name) {
  for (int i = 0; i < name.length(); i++) 
  {
    char letter = toupper(name[i]); // Convert to uppercase for consistency

    switch (letter) {
      case 'A': 
      BlinknameinMorse(".-"); 
      break;
      case 'B': 
      BlinknameinMorse("-..."); 
      break;
      case 'C': 
      BlinknameinMorse("-.-."); 
      break;
      case 'D': 
      BlinknameinMorse("-.."); 
      break;
      case 'E': 
      BlinknameinMorse("."); 
      break;
      case 'F': 
      BlinknameinMorse("..-."); 
      break;
      case 'G': 
      BlinknameinMorse("--."); 
      break;
      case 'H': 
      BlinknameinMorse("...."); 
      break;
      case 'I': 
      BlinknameinMorse(".."); 
      break;
      case 'J': 
      BlinknameinMorse(".---"); 
      break;
      case 'K': 
      BlinknameinMorse("-.-"); 
      break;
      case 'L': 
      BlinknameinMorse(".-.."); 
      break;
      case 'M': 
      BlinknameinMorse("--"); 
      break;
      case 'N': 
      BlinknameinMorse("-."); 
      break;
      case 'O':
       BlinknameinMorse("---"); 
      break;
      case 'P': 
      BlinknameinMorse(".--."); 
      break;
      case 'Q': 
      BlinknameinMorse("--.-"); 
      break;
      case 'R': 
      BlinknameinMorse(".-."); 
      break;
      case 'S': 
      BlinknameinMorse("..."); 
      break;
      case 'T': 
      BlinknameinMorse("-"); 
      break;
      case 'U': 
      BlinknameinMorse("..-"); 
      break;
      case 'V': 
      BlinknameinMorse("...-"); 
      break;
      case 'W': 
      BlinknameinMorse(".--"); 
      break;
      case 'X': 
      BlinknameinMorse("-..-"); 
      break;
      case 'Y': 
      BlinknameinMorse("-.--"); 
      break;
      case 'Z': 
      BlinknameinMorse("--..");
      break;
      default: 
      break;
    }
  }
}

void BlinknameinMorse(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      digitalWrite(ledPin, HIGH);
      delay(200); // Dot duration
    } else if (code[i] == '-') {
      digitalWrite(ledPin, HIGH);
      delay(600); // Dash duration
    }
    digitalWrite(ledPin, LOW);
    delay(200); // Short pause between signals
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
