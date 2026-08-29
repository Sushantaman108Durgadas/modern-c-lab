int Sevensegmentspin[8] = {
  2, 3, 4, 5, 6, 7, 8, 9
};

struct Segment {
  int pin;
  int Sevensegmentspin[8]; 
};

Segment segment[4];

int Numbergen[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0}
};

int digit = 0;

void setup() {
  
  for(int i=0;i<4;i++){
    segment[i].pin=i+10;
    for(int j=0;j<8;j++){
      segment[i].Sevensegmentspin[j]=Sevensegmentspin[j];
    }
  }

  for (int j = 0; j < 4; j++) {

    pinMode(segment[j].pin, OUTPUT);

    for (int i = 0; i < 8; i++) {
      pinMode(segment[j].Sevensegmentspin[i], OUTPUT);
    }
  }
}

void loop() {

  for (int i = 0; i < 4; i++) {

    digitalWrite(segment[i].pin, HIGH);

    for (int j = 0; j < 8; j++) {
      digitalWrite(
        segment[i].Sevensegmentspin[j],
        Numbergen[digit][j]
      );
    }

    delay(50);

    digitalWrite(segment[i].pin, LOW);

    for (int j = 0; j < 8; j++) {
      digitalWrite(
        segment[i].Sevensegmentspin[j],
        LOW
      );
    }
  }

  delay(500);

  digit++;

  if (digit > 9) {
    digit = 0;
  }
}
