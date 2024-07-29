/*
  Non-blocking Write

  This example demonstrates how to perform non-blocking writes
  to a file on a SD card. The file will contain the current millis()
  value every 10ms. If the SD card is busy, the data will be dataBuffered
  in order to not block the sketch.

  If data is successfully written, the built in LED will flash. After a few
  seconds, check the card for a file called datalog.txt

  NOTE: myFile.availableForWrite() will automatically sync the
        file contents as needed. You may lose some unsynced data
        still if myFile.sync() or myFile.close() is not called.

  modified 24 July 2020
  by Tom Igoe
  modified 29 July 2024
  by Joey Haas <joey.haas@adlinktech.com>

  This example code is in the public domain.
*/
#include <SD-samd5x.h>
#define LED_BUILTIN 47

// file name to use for writing
const char filename[] = "datalog.txt";

// File object to represent file
File myFile;
// string to buffer output
String dataBuffer;
// last time data was written to card:
unsigned long lastMillis = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  // wait for Serial Monitor to connect. Needed for native USB port boards only:
  while (!Serial);
  // reserve 1 kB for String used as a dataBuffer
  dataBuffer.reserve(1024);

  // set LED pin to output, used to blink when writing
  pinMode(LED_BUILTIN, OUTPUT);

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

  // If you want to start from an empty file,
  // uncomment the next line:
  //  SD.remove(filename);
  // try to open the file for writing

  myFile = SD.open(filename, FILE_WRITE);
  if (!myFile) {
    Serial.print("error opening ");
    Serial.println(filename);
    while (true);
  }

  // add some new lines to start
  myFile.println();
  myFile.println("Hello World!");
  Serial.println("Starting to write to file...");
}

void loop() {
  // check if it's been over 10 ms since the last line added
  unsigned long now = millis();
  if ((now - lastMillis) >= 10) {
    // add a new line to the dataBuffer
    dataBuffer += "Hello ";
    dataBuffer += now;
    dataBuffer += "\r\n";
    // print the buffer length. This will change depending on when
    // data is actually written to the SD card file:
    Serial.print("Unsaved data buffer length (in bytes): ");
    Serial.println(dataBuffer.length());
    // note the time that the last line was added to the string
    lastMillis = now;
  }

  // check if the SD card is available to write data without blocking
  // and if the dataBuffered data is enough for the full chunk size
  unsigned int chunkSize = myFile.availableForWrite();
  if (chunkSize && dataBuffer.length() >= chunkSize) {
    // write to file and blink LED
    digitalWrite(LED_BUILTIN, HIGH);
    myFile.write(dataBuffer.c_str(), chunkSize);
    digitalWrite(LED_BUILTIN, LOW);
    // remove written data from dataBuffer
    dataBuffer.remove(0, chunkSize);
  }
}
