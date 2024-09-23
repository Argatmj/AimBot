#include <Servo.h>

Servo servoX;
Servo servoY;

int posX = 0; 
int posY = 0; 

int currentX = 90; 
int currentY = 90; 

const int bufferSize = 32; 
char inputBuffer[bufferSize]; 

float scalingFactor = 1;
void setup() {
    Serial.begin(9600); 
    servoX.attach(9);   
    servoY.attach(10);  

    servoX.write(currentX);
    servoY.write(currentY);
}

void loop() {
    if (Serial.available()) {

        int bytesRead = Serial.readBytesUntil('\n', inputBuffer, bufferSize -1);
        inputBuffer[bytesRead] = '\0'; 

        char* commaPosition = strchr(inputBuffer, ','); 
        if (commaPosition != NULL) {
            *commaPosition = '\0'; 

            posX = atoi(inputBuffer);           
            posY = atoi(commaPosition + 1);      
            int targetX = map(posX, 0, 640, 125, 50);  
            int targetY = map(posY, 0, 480, 60, 110); 
 
            currentX = currentX + (targetX - currentX) * scalingFactor;
            currentY = currentY + (targetY - currentY) * scalingFactor;

            currentX = constrain(currentX, 0, 180);
            currentY = constrain(currentY, 0, 180);

            servoX.write(currentX);
            servoY.write(currentY);
        }
    }
}
