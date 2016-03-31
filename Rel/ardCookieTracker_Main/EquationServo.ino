int getServoPos(float cnc)
{
  int servoPos;
  servoPos = 150/numFullCookies * numCurCookies + 15;
  myServo.write(servoPos); // sets the servo to the right position
  return servoPos; // maybe will be useful later
}

