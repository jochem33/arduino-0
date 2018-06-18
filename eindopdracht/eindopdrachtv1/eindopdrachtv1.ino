//Setting up variables
const int RGB_PIN[3] = {9,10,11}; 

const int RGB_CH_PIN[3] = {6,5,3};

const int POD_PIN[3] = {A5, A4, A3};

int POD_CH[3] = {0, 0, 0};

int POD_MPD[3] = {0, 0, 0};

int randLedColor[3] = {0, 0, 0};

bool goodList[3] = {false, false, false};

bool gameWon[3] = {true, true, true};

const int treshhold = 20;

void blink(int delaytime, int blinks){ //this function blinks the green led blinks times with a delay of delaytime
  for(int i; i < blinks; i++){
    WriteRGB_CH_PIN(0, 0, 0);
    delay(delaytime);
    WriteRGB_CH_PIN(0, 255, 0);
    delay(delaytime);
  }
}

void CheckForWin(){ //this function checks if the colors match and blinks one led if they match
  if (goodList[0] == gameWon[0] && goodList[1] == gameWon[1] && goodList[2] == gameWon[2]){

      blink(150, 6);

      for (int i; i < 3; i++){
        randLedColor[i] = {int(random(0, 256))};
      }
  }
}

void Map_CH_to_MPD(){ //maps the value of the potmeter to the value of the led
  for(int i; i < 3; i++){
      POD_MPD[i] = map(POD_CH[i], 0, 1023, 0, 255);
  }
}

void PrintGoodList(){ //this function prints if each led is the good color, we do did for debuging, it is not necesary.
    Serial.print(goodList[0]);
    Serial.print(",");
    Serial.print(goodList[1]);
    Serial.print(",");
    Serial.print(goodList[2]);
    Serial.print("\n");
  
}

void CheckTreshhold(){ //checks if the ledvalue is in the treshhold of the example led value
  for(int i; i < 3; i++){
      if (POD_MPD[i] > randLedColor[i] - treshhold && POD_MPD[i] < randLedColor[i] + treshhold){
        goodList[i] = true;  
      }
      else{
        goodList[i] = false;  
      }
  }
}

void WriteRGB_PIN(int R, int G, int B){ //writes the example led value to the example led
  analogWrite(RGB_PIN[0], R);
  analogWrite(RGB_PIN[1], G);
  analogWrite(RGB_PIN[2], B);
}


void WriteRGB_CH_PIN(int R, int G, int B){ // writes the led value to the led
  analogWrite(RGB_CH_PIN[0], R);
  analogWrite(RGB_CH_PIN[1], G);
  analogWrite(RGB_CH_PIN[2], B);
}

void ReadPOD_PIN(){ // writes the value of the podpin to an array
  for(int i; i < 3; i++){
    POD_CH[i] = analogRead(POD_PIN[i]);
  }
}

void setup() {
  Serial.begin(9600); 

  randomSeed(analogRead(0));

  for (int i; i < 3; i++){
    randLedColor[i] = {int(random(0, 256))};
  }
  
  for(int i; i < 3; i++){
    pinMode(RGB_PIN[i], OUTPUT);
    pinMode(RGB_CH_PIN[i], OUTPUT);
    pinMode(POD_PIN[i], INPUT);
  }
  
}

void loop(){
    
    ReadPOD_PIN();
    
    Map_CH_to_MPD();

    CheckTreshhold();

    PrintGoodList();
    
    CheckForWin();
  
    WriteRGB_PIN(POD_MPD[0], POD_MPD[1], POD_MPD[2]); 
  
    WriteRGB_CH_PIN(randLedColor[0], randLedColor[1], randLedColor[2]); 
}
