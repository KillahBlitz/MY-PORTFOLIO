#include <SoftwareSerial.h>
#include <Stepper.h>

const int trigPin = 8;
const int echoPin = 7;
long duracion;
int distancia;
int roundAngle;
int Angle;

SoftwareSerial radar(10, 11);
Stepper motor(2048, 3, 5, 4, 6);

int stepCont = 0;

void setup() {
// nothing to do
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
 radar.begin(9600);
}

void loop() {
  motor.setSpeed(1);
  motor.step(2);
  distancia = calcularDistancia();
  Angle = stepCont*0.883218842;
  roundAngle = (int)Angle;
  Serial.print(Angle);
  Serial.print(" , ");
  Serial.print(distancia);
  Serial.println(" . ");

  radar.print(Angle);
  radar.print(" , ");
  radar.print(distancia);
  radar.println(" . ");
  stepCont++;
  if (stepCont==408) {stepCont =0;}

  
}
  int calcularDistancia(){

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duracion = pulseIn(echoPin, HIGH);
    distancia = duracion*0.034/2;
    
    return distancia;
  }