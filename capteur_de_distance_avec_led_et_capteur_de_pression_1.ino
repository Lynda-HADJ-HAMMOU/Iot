// c/ c++


const int pingPin = 7;
int led=13;
int buz=4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long duration, inches, cm;
   pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
 
 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);


  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.println(digitalRead(2));
  
if (inches< 25)
{
  digitalWrite(led, HIGH);
  if (digitalRead(2) == 1) {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToInches(long microseconds) {
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
 
  return microseconds / 29 / 2;
}