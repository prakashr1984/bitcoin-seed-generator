#include <M5StickC.h>
#include "Mnemonic.h"

MnemonicGenerator generator;
String generatedMnemonic;
bool generated = false;

void setup() {
  
  Serial.begin(115200);
  Serial.println("OK! Starting");
  
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_GREEN);  // Adding a background colour erases previous text automatically

  M5.Lcd.setCursor(10, 30);  
  M5.Lcd.setTextSize(2);
  M5.Lcd.drawCentreString("Shake Me!", 80, 20, 1);
  delay(1000);
}

void loop() {

    float progress = generator.GetProgress();
    if(progress < 1) 
    {
      float accX=0,accY=0,accZ=0;
      float gX=0,gY=0,gZ=0;
      float temp=0;
      while(1) 
      {
        M5.IMU.getAccelData(&accX,&accY,&accZ);
        if (accX > 1.5 ||  accY > 1.5 || accZ > 1.5)
          break;
      }
      M5.IMU.getGyroData(&gX,&gY,&gZ);
      M5.IMU.getTempData(&temp);
      generator.Add(accX);
      generator.Add(accY);
      generator.Add(accZ);
      generator.Add(gX);
      generator.Add(gY);
      generator.Add(gZ);
      generator.Add(temp);

      progress = generator.GetProgress();
      char sProgress[16];
      snprintf(sProgress, 16, "%g%%", progress*100);
      M5.Lcd.fillRect(0, 0, 160, 160, BLACK);
      M5.Lcd.drawCentreString(sProgress, 80, 20, 1);
    }
    else 
    {
      generatedMnemonic = generator.Generate(12);
      generated = true;
      delay(1000);
      M5.Lcd.setTextSize(1);
    }

    if(generated) 
    {
      
      M5.Lcd.fillRect(0, 0, 160, 160, BLACK);
      M5.Lcd.setCursor(0, 0);
      M5.Lcd.printf(generatedMnemonic.c_str());
    }
}
