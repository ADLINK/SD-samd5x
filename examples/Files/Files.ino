/*
  SD card basic file example

  This example shows how to create and destroy an SD card file.

  created   Nov 2010
  by David A. Mellis
  modified 24 July 2020
  by Tom Igoe
  modified 29 July 2024
  by Joey Haas <joey.haas@adlinktech.com>

  This example code is in the public domain.
*/
#include <SD-samd5x.h>

File myFile;

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
    Serial.println("Note: press reset button on the board and reopen this serial monitor after fixing your issue!");
    while (1);
  }
  Serial.println("initialization done.");

  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  } else {
    Serial.println("example.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();

  // Check to see if the file exists:
  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  } else {
    Serial.println("example.txt doesn't exist.");
  }

  // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove("example.txt");

  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  } else {
    Serial.println("example.txt doesn't exist.");
  }
}

void loop() {
  // nothing happens after setup finishes.
}
