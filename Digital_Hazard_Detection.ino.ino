// ESP32 Digital Hazard Detection System
// Components: MQ-2 Gas Sensor, Flame Sensor, Buzzer, LED, Fan

#define GAS_PIN 34        // MQ-2 analog pin
#define FLAME_PIN 32      // Flame sensor digital pin
#define BUZZER_PIN 15     // Buzzer pin
#define LED_PIN 2         // LED pin (built-in ESP32)
#define FAN_PIN 14        // Fan pin

#define GAS_THRESHOLD 1000 // Change based on your environment

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(GAS_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);

  // Turn OFF all devices initially
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(FAN_PIN, LOW);

  Serial.println("=== Digital Hazard Detection System Started ===");
}

void loop() {

  // Read sensor values
  int gasValue = analogRead(GAS_PIN);
  int flameValue = digitalRead(FLAME_PIN);  // LOW = Fire detected

  bool gasDetected = (gasValue > GAS_THRESHOLD);
  bool flameDetected = (flameValue == LOW);

  // Hazard detection
  bool hazardDetected = gasDetected || flameDetected;

  // Turn ON only when hazard exists
  if (hazardDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(FAN_PIN, LOW);
  }

  // Serial Output
  Serial.print("Gas: ");
  Serial.print(gasValue);

  Serial.print(" | Flame: ");
  Serial.print(flameDetected ? "FIRE" : "NO FIRE");

  Serial.print(" | Alarm: ");
  Serial.println(hazardDetected ? "ON" : "OFF");

  delay(1000);
}