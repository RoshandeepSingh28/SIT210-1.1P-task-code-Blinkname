int ledPin = LED_BUILTIN; // Use the built-in LED
int buttonPin = 2;        // Pin for the push button

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor for the button
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