
#include <Servo.h>

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
Servo clawServo;

// Current positions
int basePos = 90;
int shoulderPos = 90;
int elbowPos = 90;
int wristPos = 90;
int clawPos = 90;

// Target positions
int baseTarget = 90;
int shoulderTarget = 90;
int elbowTarget = 90;
int wristTarget = 90;
int clawTarget = 90;

// Movement speeds
// Higher number = slower
int baseDelay = 20;
int shoulderDelay = 30;
int elbowDelay = 20;
int wristDelay = 20;
int clawDelay = 20;

// Timers
unsigned long baseTimer = 0;
unsigned long shoulderTimer = 0;
unsigned long elbowTimer = 0;
unsigned long wristTimer = 0;
unsigned long clawTimer = 0;

void setup() {

  baseServo.attach(9);
  shoulderServo.attach(10);
  elbowServo.attach(11);
  wristServo.attach(12);
  clawServo.attach(13);

  baseServo.write(basePos);
  shoulderServo.write(shoulderPos);
  elbowServo.write(elbowPos);
  wristServo.write(wristPos);
  clawServo.write(clawPos);

  Serial.begin(9600);

  Serial.println("5 Servo Robotic Arm");
  Serial.println("-------------------");
  Serial.println("B90 = Base");
  Serial.println("S90 = Shoulder");
  Serial.println("E90 = Elbow");
  Serial.println("W90 = Wrist");
  Serial.println("C90 = Claw");
  Serial.println();
}

void loop() {

  unsigned long currentTime = millis();

  // -------------------------
  // READ SERIAL COMMAND
  // -------------------------

  if (Serial.available() > 0) {

    char servo = Serial.read();
    int angle = Serial.parseInt();

    angle = constrain(angle, 0, 180);

    if (servo == 'B' || servo == 'b') {
      baseTarget = angle;

      Serial.print("Base target: ");
      Serial.println(baseTarget);
    }

    else if (servo == 'S' || servo == 's') {
      shoulderTarget = angle;

      Serial.print("Shoulder target: ");
      Serial.println(shoulderTarget);
    }

    else if (servo == 'E' || servo == 'e') {
      elbowTarget = angle;

      Serial.print("Elbow target: ");
      Serial.println(elbowTarget);
    }

    else if (servo == 'W' || servo == 'w') {
      wristTarget = angle;

      Serial.print("Wrist target: ");
      Serial.println(wristTarget);
    }

    else if (servo == 'C' || servo == 'c') {
      clawTarget = angle;

      Serial.print("Claw target: ");
      Serial.println(clawTarget);
    }

    while (Serial.available() > 0) {
      Serial.read();
    }
  }


  // -------------------------
  // BASE
  // -------------------------

  if (basePos != baseTarget &&
      currentTime - baseTimer >= baseDelay) {

    baseTimer = currentTime;

    if (basePos < baseTarget)
      basePos++;
    else
      basePos--;

    baseServo.write(basePos);
  }


  // -------------------------
  // SHOULDER
  // -------------------------

  if (shoulderPos != shoulderTarget &&
      currentTime - shoulderTimer >= shoulderDelay) {

    shoulderTimer = currentTime;

    if (shoulderPos < shoulderTarget)
      shoulderPos++;
    else
      shoulderPos--;

    shoulderServo.write(shoulderPos);
  }


  // -------------------------
  // ELBOW
  // -------------------------

  if (elbowPos != elbowTarget &&
      currentTime - elbowTimer >= elbowDelay) {

    elbowTimer = currentTime;

    if (elbowPos < elbowTarget)
      elbowPos++;
    else
      elbowPos--;

    elbowServo.write(elbowPos);
  }


  // -------------------------
  // WRIST
  // -------------------------

  if (wristPos != wristTarget &&
      currentTime - wristTimer >= wristDelay) {

    wristTimer = currentTime;

    if (wristPos < wristTarget)
      wristPos++;
    else
      wristPos--;

    wristServo.write(wristPos);
  }


  // -------------------------
  // CLAW
  // -------------------------

  if (clawPos != clawTarget &&
      currentTime - clawTimer >= clawDelay) {

    clawTimer = currentTime;

    if (clawPos < clawTarget)
      clawPos++;
    else
      clawPos--;

    clawServo.write(clawPos);
  }
}
