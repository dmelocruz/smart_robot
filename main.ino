#define PWMA 11
#define PWMB 10
#define AIN1 13
#define AIN2 12
#define BIN1 7
#define BIN2 8
#define STBY 4

const int trigPin = 9;
const int echoPin = 6;

// Variables for calculating distance
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Set up pins:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds to send the pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, the time it takes for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if(distance>15){
    digitalWrite(STBY, HIGH);

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 100);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 100);
  }else{
    digitalWrite(STBY, LOW);
  }
  
  delay(1000);
  
}
