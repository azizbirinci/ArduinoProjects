#include <Servo.h>
Servo servoNesnesi;

#define motor 5

#define led_kirmizi1 8
#define led_kirmizi2 9
#define led_kirmizi3 10

#define led_yesil1 11
#define led_yesil2 12
#define led_yesil3 13

const int trig =2;
const int echo= 3;

int sure=0;
int mesafe=0;

void setup() {

  servoNesnesi.attach(5);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(led_kirmizi1, OUTPUT);
  pinMode(led_kirmizi2, OUTPUT);
  pinMode(led_kirmizi3, OUTPUT);
  
  pinMode(led_yesil1, OUTPUT);
  pinMode(led_yesil2, OUTPUT);
  pinMode(led_yesil3, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  
  int isik1 = analogRead(A0);
  int isik2 = analogRead(A1);
  int isik3 = analogRead(A2);

  Serial.print("P1 : ");
  Serial.println(isik1);
  Serial.print("P2 : ");
  Serial.println(isik2);
  Serial.print("P3 : ");
  Serial.println(isik3);
  delay(250);

  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure/2) / 29.1;
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  delay(250);

  if(mesafe < 10)
  {
    servoNesnesi.write(90);
  }
  else if(mesafe > 10)
  {
    servoNesnesi.write(0); 
  }

  if(isik1 >= 500 && isik2 >= 500 && isik3 >= 500)
  {
    digitalWrite(led_kirmizi1, LOW);
    digitalWrite(led_kirmizi2, LOW);
    digitalWrite(led_kirmizi3, LOW);

    digitalWrite(led_yesil1, HIGH);
    digitalWrite(led_yesil2, HIGH);
    digitalWrite(led_yesil3, HIGH);
  }

  else if(isik1 >= 500 && isik2 >= 500 && isik3 < 500)
  {
    digitalWrite(led_kirmizi1, LOW);
    digitalWrite(led_kirmizi2, LOW);
    digitalWrite(led_kirmizi3, HIGH);

    digitalWrite(led_yesil1, HIGH);
    digitalWrite(led_yesil2, HIGH);
    digitalWrite(led_yesil3, LOW);
  }
  else if(isik1 >= 500 && isik2 < 500 && isik3 >= 500)
  {
    digitalWrite(led_kirmizi1, LOW);
    digitalWrite(led_kirmizi2, HIGH);
    digitalWrite(led_kirmizi3, LOW);

    digitalWrite(led_yesil1, HIGH);
    digitalWrite(led_yesil2, LOW);
    digitalWrite(led_yesil3, HIGH);
  }
  else if(isik1 >= 500 && isik2 < 500 && isik3 < 500)
  {
    digitalWrite(led_kirmizi1, LOW);
    digitalWrite(led_kirmizi2, HIGH);
    digitalWrite(led_kirmizi3, HIGH);

    digitalWrite(led_yesil1, HIGH);
    digitalWrite(led_yesil2, LOW);
    digitalWrite(led_yesil3, LOW);
  }
  
  else if(isik1 < 500 && isik2 >= 500 && isik3 >= 500)
  {
    digitalWrite(led_kirmizi1, HIGH);
    digitalWrite(led_kirmizi2, LOW);
    digitalWrite(led_kirmizi3, LOW);

    digitalWrite(led_yesil1, LOW);
    digitalWrite(led_yesil2, HIGH);
    digitalWrite(led_yesil3, HIGH);
  }
  else if(isik1 < 500 && isik2 >= 500 && isik3 < 500)
  {
    digitalWrite(led_kirmizi1, HIGH);
    digitalWrite(led_kirmizi2, LOW);
    digitalWrite(led_kirmizi3, HIGH);

    digitalWrite(led_yesil1, LOW);
    digitalWrite(led_yesil2, HIGH);
    digitalWrite(led_yesil3, LOW);
  }
  else if(isik1 < 500 && isik2 < 500 && isik3 >= 500)
  {
    digitalWrite(led_kirmizi1, HIGH);
    digitalWrite(led_kirmizi2, HIGH);
    digitalWrite(led_kirmizi3, LOW);

    digitalWrite(led_yesil1, LOW);
    digitalWrite(led_yesil2, LOW);
    digitalWrite(led_yesil3, HIGH);
  }
  
  else if(isik1 < 500 && isik2 < 500 && isik3 < 500)
  {
    digitalWrite(led_kirmizi1, HIGH);
    digitalWrite(led_kirmizi2, HIGH);
    digitalWrite(led_kirmizi3, HIGH);

    digitalWrite(led_yesil1, LOW);
    digitalWrite(led_yesil2, LOW);
    digitalWrite(led_yesil3, LOW);

    servoNesnesi.write(0);
  }  
}
