#include <DigiMouse.h>
unsigned int endrand1 = 20000;
unsigned int endrand2 = 70000;
unsigned int LowerCycleTime = 1000;
unsigned int UpperCycleTime = 9000;
void setup() {
  randomSeed(analogRead(0)); // Random Seed off background noise on analog pin
  pinMode(1, OUTPUT);
  DigiMouse.begin(); // start
}

void loop() {
  unsigned int xrand1 = 1;
  unsigned int xrand2 = 10;
  
  for(int x = 0; x<=random(xrand1,xrand2); x++){
    // Moves mouse in a square pattern with larger steps
    unsigned int randdelay1 = 6;
    unsigned int randdelay2 = 50;
    for(int a = 1; a<=10; a++){
      digitalWrite(1, HIGH);
      DigiMouse.moveY(a); // Move up by 'stepSize' pixels
      DigiMouse.delay(random(randdelay1,randdelay2)); // Shortened delay for faster movement
      digitalWrite(1, LOW);
      DigiMouse.delay(25);
    }
    delay(200);
    for(int b = 1; b<=10; b++){
      digitalWrite(1, HIGH);
      DigiMouse.moveX(b); // Move right by 'stepSize' pixels
      DigiMouse.delay(random(randdelay1,randdelay2)); // Shortened delay for faster movement
      digitalWrite(1, LOW);
      DigiMouse.delay(25);
    }
    delay(200);
    for(int c = 1; c<=10; c++){
      digitalWrite(1, HIGH);
      DigiMouse.moveY(-c); // Move down by 'stepSize' pixels
      DigiMouse.delay(random(randdelay1,randdelay2)); // Shortened delay for faster movement
      digitalWrite(1, LOW);
      DigiMouse.delay(25);
    }
    delay(200);
    for(int d = 1; d<=10; d++){
      digitalWrite(1, HIGH);
      DigiMouse.moveX(-d); // Move left by 'stepSize' pixels
      DigiMouse.delay(random(randdelay1,randdelay2)); // Shortened delay for faster movement
      digitalWrite(1, LOW);
      DigiMouse.delay(25);
    }
    delay(random(LowerCycleTime, UpperCycleTime));
  }
  delay(random(endrand1, endrand2));
}
