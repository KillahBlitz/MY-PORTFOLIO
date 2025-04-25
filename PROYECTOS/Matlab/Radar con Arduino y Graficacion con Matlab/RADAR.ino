// librerias utilizadas
#include <SoftwareSerial.h>
#include <Stepper.h>

// variables
const int trigPin = 8;
const int echoPin = 7;
long duracion;
int distancia;
int roundAngulo;
int Angulo;
int ContPasos = 0;

// puertos virtuales 
SoftwareSerial radar(10, 11);
Stepper motor(2048, 3, 5, 4, 6);

void setup() {
  // configuracion de pines 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
// inicia comunicacion serial
 Serial.begin(9600);
 radar.begin(9600);
}

void loop() {
  motor.setSpeed(2); // velocidad del motor
  motor.step(2);  // angulo en pasos de los que va a moverse 
  distancia = calcularDistancia(); // llamo a la funcion donde se calcula la distancia de los objetos 
  Angulo = ContPasos*0.883218842; // covierte pasos a un angulo real 
  roundAngulo = (int)Angulo; // convertir el angulo a entero 
  Serial.print(Angulo);
  Serial.print(" , ");
  Serial.print(distancia);
  Serial.println(".");

  radar.print(Angulo);
  radar.print(" , ");
  radar.print(distancia);
  radar.println(". ");
  ContPasos++; // incremeneta los pasos 
  if (ContPasos==408) {ContPasos =0;} // reinicia el conteo despues de que halla hecho los 408 pasos = 1 vuelta

  
}
  int calcularDistancia(){

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // manda una onda cada 10 milisegundos 
    digitalWrite(trigPin, LOW);
    duracion = pulseIn(echoPin, HIGH); // mide cuanto tiempo tarda en llegar la onda
    distancia = duracion*0.034/2; 
    
    return distancia;
  }