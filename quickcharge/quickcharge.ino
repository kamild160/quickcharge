
const int DPH = 2;
const int DPL = 3;
const int DMH = 4;
const int DML = 5;
bool handshakeDone = false;
void handshake() {
  pinMode(DPH, OUTPUT);
  pinMode(DPL, OUTPUT);
  digitalWrite(DPH, HIGH);
  digitalWrite(DPL, LOW);
  delay(1500);
  pinMode(DMH, OUTPUT);
  pinMode(DML, OUTPUT);
  digitalWrite(DMH, LOW);
  digitalWrite(DML, LOW);
  handshakeDone = true;
}
void setVoltage(unsigned int voltage) {
  if (!handshakeDone) {
    handshake();
  }
  switch (voltage) {
    case 9:
      digitalWrite(DPH, LOW);
      digitalWrite(DPL, HIGH);
      digitalWrite(DMH, HIGH);
      digitalWrite(DML, LOW);
      break;
    case 12:
      digitalWrite(DPH, HIGH);
      digitalWrite(DPL, LOW);
      digitalWrite(DMH, HIGH);
      digitalWrite(DML, LOW);
      break;
    case 5:
    default:
      digitalWrite(DPH, HIGH);
      digitalWrite(DPL, LOW);
      digitalWrite(DMH, LOW);
      digitalWrite(DML, LOW);      
  }
 
}
void setup() {
 
}
 
void loop() {
  setVoltage(12);
  delay(5000);
  setVoltage(9);
  delay(5000);
  setVoltage(5);
  delay(5000);
 
}
