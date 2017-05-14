//Överst definieras (skrivs) variabler som är av typen heltal.
//Bibliotek importeras också här någonstans.
int heltal = 11;
int tio = 10;

#include <Servo.h> //inkludera Servo biblioteket i denna sketch.
Servo myServo; //Samma som ovan förutom att myServo är av typen Servo istället för int (heltal).

//I setup() förbereds Arduinons pins till att göra olika saker.
//I vårt fall sätta dem till OUTPUT och bestämma vilken pin som är servo. 
//Koden körs en gång.
void setup() {
pinMode(heltal, OUTPUT);
pinMode(tio, OUTPUT);

myServo.attach(6);

//Starta monitorn, monitorn öppnas genom att trycka in Ctrl, Shift och m på tangentbordet samtidigt.
//Kan också kommas åt ifrån verktyg/tools menyn.
Serial.begin(9600);
}

//Kod i loopen körs oändligt antal gånger om och om igen.
void loop() {
houston(heltal, 1000);

//for-loop exempel:
for(int i = 0; i < 180; i += 1){
  myServo.write(i); //Ställ in servomotorn på graden i
  Serial.println(i); //skriv ut värdet av "i" i monitorn.
  delay(500);
}

//while-loop exempel:
int m = 0;
while(m < 180) { //Så länge villkoret i parentesen är uppfyllt så kommer loopen att köras.
  myServo.write(m);
  Serial.print("Värdet av m: ");
  Serial.println(m);
  m += 1;
}

//Annan while-loop:
while(true){
  //Allting här inne kommer köras oändligt antal gånger då true inte någonsin kommer ändras till false..
}

Serial.println("Denna kod kommer inte nås");
}

//Utanför loopen definieras funktioner (också kallade för metoder).
//Metoden houston har här två inparametrar, pin och tid som är av typen heltal.
void houston(int pin, int tid) {
  digitalWrite(pin, 1);
  delay(tid);
  digitalWrite(pin, 0);
  delay(tid);
}

