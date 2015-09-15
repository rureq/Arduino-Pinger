#define TrigPin 3
#define EchoPin 2
int distance;
long duration = 0;
 
void setup()
{
  Serial.begin (9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}
int maxdistance = 0;
 
void loop()
{
  // impuls 10 us wyzwalający pomiar odległości na pinie TRIG
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
 
  // pomiar czasu trwania impulsu na pinie ECHO [us]
  duration = pulseIn(EchoPin, HIGH);
 
  // obliczenie odległości w cm
  distance = duration/58;
 
  if ( distance < 2 || distance > 200 )
    Serial.println("----- Poza zakresem");
  else
  {
    Serial.print("Odeglosc: ");
    Serial.print( distance );
    Serial.println(" cm");
    if ( distance > maxdistance ) maxdistance = distance;
    Serial.print("Masymalna odległosc: ");
    Serial.print( maxdistance );
    Serial.println(" cm");
  }
  delay(50);
}
//Kupa smierdzi
