const int button1 = 7;
const int button2 = 4;

const int led = 13;

int button1state;
int button2state;


int prevbutton1state = LOW;
int prevbutton2state = LOW;

int ledstate = LOW;

void setup() {
  pinMode(led, OUTPUT); 
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT);
}

void loop() {
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);

  if ((prevbutton1state == LOW) && (button1state == HIGH)){
    ledstate = 1 - ledstate;
    digitalWrite(led, ledstate);
    prevbutton1state = HIGH;
  }
  else if ((prevbutton1state == HIGH) && (button1state == LOW)) {
    prevbutton1state = LOW;
  }

  if ((prevbutton2state == LOW) && (button2state == HIGH)){
    ledstate = 1 - ledstate;
    digitalWrite(led, ledstate);
    prevbutton2state = HIGH;
  }
  else if ((prevbutton2state == HIGH) && (button2state == LOW)) {
    prevbutton2state = LOW;
  }
}
