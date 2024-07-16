String voice;
#define relay1 2 // Connect relay1 to pin 2
#define relay2 3 // Connect relay2 to pin 3
#define relay3 4 // Connect relay1 to pin 2
#define relay4 5 // Connect relay2 to pin 3

void setup()
{
    Serial.begin(9600);      // Set rate for communicating with phone
    pinMode(relay1, OUTPUT); // Set relay1 as an output
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT); // Set relay2 as an output
    pinMode(relay4, OUTPUT);
    digitalWrite(relay1, LOW); // Switch relay1 off
    digitalWrite(relay2, LOW); // Swtich relay2 off
    digitalWrite(relay3, LOW); // Switch relay1 off
    digitalWrite(relay4, LOW); // Swtich relay2 off
}

void loop()
{
    while (Serial.available()) // Check if there are available bytes to read
    {
        delay(10);              // Delay to make it stable
        char c = Serial.read(); // Conduct a serial read
        if (c == '#')
        {
            break; // Stop the loop once # is detected after a word
        }
        voice += c; // Means voice = voice + c
    }
    if (voice.length() > 0)
    {
        Serial.println(voice);
        if (voice == "*switchon")
        {
            switchon();
        }
        else if (voice == "*switchoff")
        {
            switchoff();
        }
        else if (voice == "*bulb1on")
        {
            digitalWrite(relay1, LOW);
        }
        else if (voice == "*bulb1off")
        {
            digitalWrite(relay1, HIGH);
        }
        else if (voice == "*bulb2on")
        {
            digitalWrite(relay2, LOW);
        }
        else if (voice == "*bulb2off")
        {
            digitalWrite(relay2, HIGH);
        }
        else if (voice == "*fan1on")
        {
            digitalWrite(relay3, LOW);
        }
        else if (voice == "*fan1off")
        {
            digitalWrite(relay3, HIGH);
        }
        else if (voice == "*fan2on")
        {
            digitalWrite(relay4, LOW);
        }
        else if (voice == "*fan2off")
        {
            digitalWrite(relay4, HIGH);
        }
        voice = "";
    }
    Serial.print(voice);
}
void switchon() // Function for turning on relays
{
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
}
void switchoff() // Function for turning on relays
{
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
}