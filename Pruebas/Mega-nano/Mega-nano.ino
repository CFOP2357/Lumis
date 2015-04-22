int x1, x2, x3;
void setup() {
  Serial.begin(9600);
  pinMode(53, INPUT);
  pinMode(51, INPUT);
  pinMode(49, INPUT);
}

void loop() {
  x1=digitalRead(53);
  x2=digitalRead(51);
  x3=digitalRead(49);
  
  Serial.print(x1);
  Serial.print(" - ");
  Serial.print(x2);
  Serial.print(" - ");
  Serial.print(x3);
  Serial.println();
}
