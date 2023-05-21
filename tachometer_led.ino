/*
* Samuel V.S
* Date: 10/04/2023
*/
int ledcount=11;
unsigned long int sig;
int ledpins[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


void setup() 
{
  
  pinMode(11,INPUT);
  for(int i = 0; i < ledcount; i++)
  {
    pinMode(ledpins[i], OUTPUT);
  }
  for(int i = 0; i < ledcount; i++)
  {
    digitalWrite(ledpins[i], HIGH);
    delay(80);
    
  }
    for(int i = ledcount; i > 0; i--)
  {
    digitalWrite(ledpins[i], HIGH);
    delay(33);
  }

}

void loop() 
{
  sig = pulseIn(11, HIGH);
  
  int ledlevel = map(sig, 5000, 60000, 0, ledcount);
  
  for(int i = 0; i < ledcount; i++)
  {
    if(i < ledlevel)
    {
      digitalWrite(ledpins[i], HIGH);
    }
    else 
    {
      digitalWrite(ledpins[i], LOW);
    }
   }
   delay(1);
}
/*
// Define the pins for Charlieplexing
int pins[] = {3, 4, 5, 6};

// Define the LED combinations for each Charlieplexing pin
int ledCombos[][2] = {
  {0, 1},
  {0, 2},
  {0, 3},
  {1, 2},
  {1, 3},
  {2, 3}
};

int ledCount = 12;
unsigned long int sig;

void setup() 
{
  for (int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
}

void loop() 
{
  sig = pulseIn(2, HIGH); // Read input signal from pin0

  int ledLevel = map(sig, 5000, 60000, 0, ledCount);

  // Turn on/off LEDs using Charlieplexing
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    if (thisLed < ledLevel) {
      digitalWrite(pins[ledCombos[thisLed][0]], LOW);
      digitalWrite(pins[ledCombos[thisLed][1]], HIGH);
    } else {
      digitalWrite(pins[ledCombos[thisLed][0]], LOW);
      digitalWrite(pins[ledCombos[thisLed][1]], LOW);
    }
  }
}
/*
LED1: Connect anode (positive leg) to pin 3, and cathode (negative leg) to pin 4
LED2: Connect anode to pin 3, and cathode to pin 5
LED3: Connect anode to pin 3, and cathode to pin 6
LED4: Connect anode to pin 4, and cathode to pin 5
LED5: Connect anode to pin 4, and cathode to pin 6
LED6: Connect anode to pin 5, and cathode to pin 6
LED7: Connect anode to pin 6, and cathode to pin 3
LED8: Connect anode to pin 6, and cathode to pin 4
LED9: Connect anode to pin 6, and cathode to pin 5
LED10: Connect anode to pin 5, and cathode to pin 3
LED11: Connect anode to pin 5, and cathode to pin 4
LED12: Connect anode to pin 4, and cathode to pin 3
*/
