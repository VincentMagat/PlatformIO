#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <wire.h>
#include <Adafruit_CAP1188.h>
#define CAP1188_MISO 33;
#define CAP1188_SCK 25;
#define CAP1188_MOSI 32;
#define CAP1188_CS 26;
#define CAP1188_RESET 39;
TFT_eSPI tft = TFT_eSPI();
Adafruit_CAP1188 cap = Adafruit_CAP1188(25, 33, 32, 26, 39);



void setup() {
  // put your setup code here, to run once:
  /**tft.init();
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  int i = 0;
  while (i <= 10)
  {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(50,50);
    tft.fillRect(60, 60, 100, 30, TFT_BLACK);
    tft.drawNumber(i, 60,60, 1);
    i++;**/
   /** delay(1000);
  }
  tft.fillRect(60, 60, 100, 30, TFT_BLACK);**/

  tft.init();
  tft.fillScreen(TFT_BLACK); 
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Testing", 60, 60, 1);
  delay(1000);
  tft.fillRect(60, 60, 100, 30, TFT_BLACK);
  
  if (!cap.begin()) {
    tft.setTextSize(1);
    tft.drawString("CAP1188 not found!", 10, 60, 1);
    while (1);
  }
  tft.fillRect(60, 60, 100, 30, TFT_BLACK);
  tft.setTextSize(1);
  tft.drawString("CAP1188 found!", 20, 60, 1);
  
}
  

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t touched = cap.touched();
  uint8_t sensors = 0; // will keep track of the number of sensors touched

  for (uint8_t i=0; i<8; i++) {
    if (touched & (1 << i)) {               //this loop is for when the any of the cap has been touched will increment sensors variable
      sensors++;                            //the data inputed in that variable will be then be used for our display.
    }
  }

  tft.fillRect(60, 110, 100, 30, TFT_BLACK);
  tft.setTextSize(3);
  tft.drawNumber(sensors, 60,110, 1);

  delay(50);

  
}