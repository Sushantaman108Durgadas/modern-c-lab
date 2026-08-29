int Sevensegmentspin[8] = {
  2, 3, 4, 5, 6, 7, 8, 9
};

struct Segment {
  int pin;
  int Sevensegmentspin[8];
  int (*call_back)(int); 
};

int set_select_pin(int i){
  return i+10;
}

int set_sevensegmentpin(int j){
  return Sevensegmentspin[j];
}

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
    segment[i].call_back=set_select_pin;
    segment[i].pin=segment[i].call_back(i);
    segment[i].call_back=set_sevensegmentpin;
    for(int j=0;j<8;j++){
      segment[i].Sevensegmentspin[j]=segment[i].call_back(j);
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

  delay(1000);

  digit++;

  if (digit > 9) {
    digit = 0;
  }
}
