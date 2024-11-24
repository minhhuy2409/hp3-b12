const int led1 = 7;
const int led2 = 8;
const int led3 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int mode = Serial.parseInt(); // Đọc chế độ từ Serial
    
    if (mode == 1) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    } else if (mode == 2) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(500);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(500);
    } else if (mode == 3) {
      digitalWrite(led1, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(200);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(200);
      digitalWrite(led3, LOW);
    }
  }
}