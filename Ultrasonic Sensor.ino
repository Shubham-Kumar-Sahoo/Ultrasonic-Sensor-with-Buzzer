#define echoPin 6 // Attach Pin D6 of Arduino to Pin Echo of Ultrasonic Sensor
#define trigPin 7 // Attach Pin D3 of Arduino to Pin Trig of Ultrasonic Sensor
#define buzz_signal 8 // Attach Pin D8 of Arduino to Pin Signal of Piezo Buzzer
long duration; // Variable for the duration of sound wave
float distance; // Variable for the distance measurement

void setup() // This part of the code is used to define and set the initial data conditions
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin of Ultrasonic Sensor as OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin of Ultrasonic Sensor as INPUT
    pinMode(buzz_signal, OUTPUT); // Sets the Piezo Buzzer as OUTPUT
    Serial.begin(115200); // Serial Communication is starting with 115200 of baudrate speed. This defines the rate of transmission of data.
}

void loop() // This part of the code will keep on executing until a certain condition is fulfilled
{
    digitalWrite(trigPin, LOW); // Initially the trigPin is set in LOW condition
    delayMicroseconds(2); // After a small gap of 2 microseconds, the code will start to execute again in a loop
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Wait for 10 microseconds
    digitalWrite(trigPin, LOW);
    digitalWrite(buzz_signal, LOW); // When the object is far away from the sensor, the buzzer will not beep. So it is set in LOW condition.
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH); // Total time calculation
    // Calculating the distance
    distance = duration * 0.034 / 2; // (Total time * Speed of sound wave) / 2 (To and fro) 
    Serial.print("Distance: ");
    Serial.print(distance); // Printing the distance of the object from the sensor
    Serial.println(" cm");
    if (distance < 10.0) // Setting 10 cm as limiting value to check the distance of the water from the sensor
    {
        Serial.println("Object is near to the sensor");
        digitalWrite(buzz_signal, HIGH);
        tone(7,220,100);// When the object is near the sensor, the buzzer will beep. So it is set in HIGH condition.
        tone(7,180,100);
    }
    else
    {
        Serial.println("Object is far from the sensor");
        digitalWrite(buzz_signal, LOW); // When the object is far away from the sensor, the buzzer will not beep. So it is set in LOW condition.
    }
    delay(1000); // Wait for 1000 milliseconds
}