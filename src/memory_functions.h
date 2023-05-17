#ifndef MEMORY_FUNCTIONS
#define MEMORY_FUNCTIONS

#include <EEPROM.h>
#include <SD.h> 

#include "FS.h"                // SD Card ESP32
#include "SD_MMC.h"            // SD Card ESP32

#include <SPIFFS.h>
#include <FS.h>

#define EEPROM_SIZE 1

bool   SD_present = false; //Controls if the SD card is present or not

void resetEEPROM(){
    EEPROM.begin(EEPROM_SIZE);
    EEPROM.write(0, 0);
    EEPROM.commit();
}

int getNumEEPROM(){
    
    EEPROM.begin(EEPROM_SIZE);
    int num = EEPROM.read(0);
    EEPROM.write(0, num + 1);
    EEPROM.commit();
    EEPROM.end();
    return num;
}

void initialiseSPIFFS(){
     if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    ESP.restart();
  }
  else {
    delay(500);
    Serial.println("SPIFFS mounted successfully");
  }
}

void initialiseSD(){
    if(SD_MMC.begin()){
    SD_present = true;
    Serial.println("SD mounted successfully");
  }
  else{
    Serial.println("SD Card Mount Failed");
    //return;
  }
}







#endif