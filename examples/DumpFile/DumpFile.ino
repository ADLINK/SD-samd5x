/*
  SD card file dump

  This example shows how to read a file from the SD card using the
  SD-samd5x library and send it over the serial port.

  created  22 December 2010
  by Limor Fried
  modified 9 Apr 2012
  by Tom Igoe
  modified 29 July 2024
  by Joey Haas <joey.haas@adlinktech.com>

  This example code is in the public domain.
*/
#include <SD-samd5x.h>

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  // wait for Serial Monitor to connect. Needed for native USB port boards only:
  while (!Serial);

  Serial.print("Initializing SD card...");

  if (!SD.begin()) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("1. is a card inserted?");
    Serial.println("2. is your wiring correct?");
    Serial.println("Note: press reset button on the board and reopen this Serial Monitor after fixing your issue!");
    while (true);
  }

  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void loop() {
}
