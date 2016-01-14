#include <math.h>

int ammo=0;
int maxammo=0;
int percentage=0;

void setup() {

  for (int i = 0;i<14;i++){
    pinMode(i, OUTPUT); // pin will be used to for output
  }

    Serial.begin(9600); // same as in your c++ script

  for (int i = 0;i<14;i++){
    digitalWrite(i, LOW);
  }
}

void loop() {

  if (Serial.available() > 0)
  {
    ammo = Serial.parseInt(); // used to read incoming data
    maxammo = 30;
    percentage = ammo * 100 / maxammo; 
    round(percentage);

    switch(percentage)// see what was sent to the board
   { 
    case 100:
    case 99:
    case 98:
    case 97:
    case 96:
    case 95:
    case 94:
    case 93:
    case 92:
    case 91:
      for (int i = 4;i<14;i++){
        digitalWrite(i, HIGH);
      }
    break;
    case 90:
    case 89:
    case 88:
    case 87:
    case 86:
    case 85:
    case 84:
    case 83:
    case 82:
    case 81:
      for (int i = 4;i<13;i++){
        digitalWrite(i, HIGH);
      }
      for (int i = 13;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 80:
    case 79:
    case 78:
    case 77:
    case 76:
    case 75:
    case 74:
    case 73:
    case 72:
    case 71:
      for (int i = 4;i<12;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 12;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 70:
    case 69:
    case 68:
    case 67:
    case 66:
    case 65:
    case 64:
    case 63:
    case 62:
    case 61:
      for (int i = 4;i<11;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 11;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 60:
    case 59:
    case 58:
    case 57:
    case 56:
    case 55:
    case 54:
    case 53:
    case 52:
    case 51:
      for (int i = 4;i<10;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 10;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 50:
    case 49:
    case 48:
    case 47:
    case 46:
    case 45:
    case 44:
    case 43:
    case 42:
    case 41:
      for (int i = 4;i<9;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 9;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
      for (int i = 4;i<8;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 8;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
      for (int i = 4;i<7;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 7;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
      for (int i = 4;i<6;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 6;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      for (int i = 4;i<5;i++){
        digitalWrite(i, HIGH);
      }
            for (int i = 5;i<14;i++){
        digitalWrite(i, LOW);
      }
    break;
    case 0:
          for (int i = 4;i<14;i++){
        digitalWrite(i, LOW);
      }
      break;
    default:
    break;
   }
  }
}