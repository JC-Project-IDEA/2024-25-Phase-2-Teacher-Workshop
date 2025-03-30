import processing.serial.*;
import processing.sound.*;

Serial myPort;  // Create object from Serial class
SoundFile[] sounds = new SoundFile[6];
SoundFile bgm;  // Added BGM SoundFile
boolean[] isPlaying = new boolean[6];

void setup() {
  size(600, 400);
  
  // List all the available serial ports`
  printArray(Serial.list());
  
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 115200); // Change index as needed
  myPort.bufferUntil('\n');
  
  // Load sound files
  sounds[0] = new SoundFile(this, "sound0.mp3");
  sounds[1] = new SoundFile(this, "sound1.mp3");
  sounds[2] = new SoundFile(this, "sound2.mp3");
  sounds[3] = new SoundFile(this, "sound3.mp3");
  sounds[4] = new SoundFile(this, "sound4.mp3");
  sounds[5] = new SoundFile(this, "sound5.mp3");
  
  // Load and play background music
  bgm = new SoundFile(this, "bgm.mp3");
  bgm.loop();
}

void draw() {
  background(0);
  
  // Display which sounds are playing
  for (int i = 0; i < 6; i++) {
    if (isPlaying[i]) {
      fill(0, 255, 0);
    } else {
      fill(255, 0, 0);
    }
    ellipse(100 + i*80, 200, 50, 50);
    fill(255);
    text("Sound " + i, 80 + i*80, 250);
  }
}

void serialEvent(Serial myPort) {
  // Get the string from serial port
  String inString = myPort.readStringUntil('\n');
  
  if (inString != null) {
    // Trim whitespace
    inString = trim(inString);
    
    // Split the string on comma
    String[] values = split(inString, ',');
    
    if (values.length == 2) {
      int sensorIndex = int(values[0]);
      int activationStatus = int(values[1]);
      
      // Valid sensor index
      if (sensorIndex >= 0 && sensorIndex < 6) {
        if (activationStatus == 1 && !isPlaying[sensorIndex]) {
          // Sensor activated, start playing sound
          sounds[sensorIndex].loop();
          isPlaying[sensorIndex] = true;
        } else if (activationStatus == 0 && isPlaying[sensorIndex]) {
          // Sensor deactivated, stop playing sound
          sounds[sensorIndex].stop();
          isPlaying[sensorIndex] = false;
        }
      }
    }
  }
}
