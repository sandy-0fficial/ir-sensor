#include <BleKeyboard.h>

#define IR_SENSOR_PIN 13
#define RELAY_PIN 5     
BleKeyboard bleKeyboard;
unsigned long startTime = 0;
bool handDetected = false;

void setup() {
  Serial.begin(115200);
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int irValue = digitalRead(IR_SENSOR_PIN);

    if (irValue == LOW && !handDetected) {
      handDetected = true;
      digitalWrite(RELAY_PIN, HIGH); 
      delay(500);
      digitalWrite(RELAY_PIN, LOW);
      startTime = millis();
    }

    if (irValue == HIGH && handDetected) {
      unsigned long duration = millis() - startTime;
      handDetected = false;

      Serial.print("Duration: ");
      Serial.println(duration);

      if (duration >= 0 && duration < 1000) {
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        Serial.println("Play/Pause");
      } else if (duration >= 1000 && duration < 3000) {
        bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
        Serial.println("Next");
      } else if (duration >= 3000 && duration <= 6000) {
        bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
        Serial.println("Previous");
      } else if (duration > 7000) {
        Serial.println("Ignored – too long");
      }

      delay(1000); 
    }
  }
}
