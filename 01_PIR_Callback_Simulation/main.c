#include<stdio.h>

typedef struct{
    int inputpins;
    int outpins;
}pin_structure;

struct Sensor{
    int (*callback_sensor)(void);
    pin_structure Sensorpin;
};

int objectdetect(void){
    printf("PIR detected a motion!!! Object sensed....");
    return 1;
}

int objectnotdetect(void){
    printf("PIR not detected a motion!!! No Object sensed therefore.....");
    return 0;
}

int main(void){
    printf("Simulating PIR behaviour.......\n");
    printf("Enter 1 to simulate a motion.... else enter 0\n");
    int choice;
    scanf("%d",&choice);
    struct Sensor PIR;
    if(choice){
      PIR.callback_sensor=objectdetect;
    }else{
      PIR.callback_sensor=objectnotdetect;  
    }
    PIR.Sensorpin.inputpins=1;
    PIR.Sensorpin.outpins=1;
    int result=PIR.callback_sensor();
    return 0;
}
