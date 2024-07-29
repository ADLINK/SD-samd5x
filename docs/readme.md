# SD library

The SD-samd5x library allows for reading from and writing to SD cards connected to the SDHC (Secure Digital Host Controller) peripheral on samd5x-series chips. It is an extension of the [SD library for Arduino](https://github.com/arduino-libraries/SD), which is built on [sdfatlib](http://code.google.com/p/sdfatlib/) by William Greiman. The library supports FAT16 and FAT32 file systems on standard SD cards and SDHC cards. It uses short 8.3 names for files. The file names passed to the SD library functions can include paths separated by forward-slashes, /, e.g. "directory/filename.txt". Because the working directory is always the root of the SD card, a name refers to the same file whether or not it includes a leading slash (e.g. "/file.txt" is equivalent to "file.txt"). As of version 1.0, the library supports opening multiple files.

The communication between the microcontroller and the SD card uses the SD protocol.

To use this library:

```
#include <SD-samd5x.h>
```

[Notes on using the Library and various shields](https://www.arduino.cc/en/Reference/SDCardNotes).

## Examples

* [Card Info](https://www.arduino.cc/en/Tutorial/LibraryExamples/CardInfo): Get info about your SD card.
* [Datalogger](https://www.arduino.cc/en/Tutorial/LibraryExamples/Datalogger): Log data from three analog sensors to an SD card.
* [Dump File](https://www.arduino.cc/en/Tutorial/LibraryExamples/DumpFile): Read a file from the SD card.
* [Files](https://www.arduino.cc/en/Tutorial/LibraryExamples/Files): Create and destroy an SD card file.
* [List Files](https://www.arduino.cc/en/Tutorial/LibraryExamples/Listfiles): Print out the files in a directory on a SD card.
* [Read Write](https://www.arduino.cc/en/Tutorial/LibraryExamples/ReadWrite): Read and write data to and from an SD card.
