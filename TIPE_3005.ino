//Libraries
#include "LiquidCrystal.h"
#include <FastLED.h>//https://github.com/FastLED/FastLED

//Constants
#define NUM_STRIPS 1

#define NUM_LEDS 48
#define BRIGHTNESS 10
#define LED_TYPE WS2812B
#define COLOR_ORDER BRG//RGB
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 1
#define FRAMES_PER_SECOND 60
#define COOLING 55
#define SPARKING 120
#define diametre 0.58
#define pi 3.14159265359


const int capteur = 2;
const int Bgauche = 11;
const int Bdroite = 10;



boolean ini = true;
long debut;
int compteur = 0;
double vit;
double Vmoy;
int minutes ;
String vitesse = "0";
long dernierInstant;
const int stripPin = 9;
//Objects
CRGB leds[NUM_LEDS];

LiquidCrystal LCD(8, 3, 7, 6, 5, 4);

byte customChar[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

// SETUP #######################################################################################################
void setup() {


pinMode(capteur, INPUT);
pinMode(Bdroite, INPUT);
pinMode(Bgauche, INPUT);


LCD.begin(16, 2); // définit le type d'écran lcd 16 x 2
LCD.createChar(0, customChar);
LCD.setCursor(3, 0);
LCD.print("#INIT#");
LCD.setCursor(6, 1);
LCD.print("Bonjour !");

//Init led strips
FastLED.addLeds<LED_TYPE, stripPin, COLOR_ORDER>(leds, NUM_LEDS);
FastLED.setBrightness( BRIGHTNESS );

//attachInterrupt(digitalPinToInterrupt(2), incremente, RISING);
delay(500);
LCD.clear();

while(digitalRead(capteur)==0){
}
while(digitalRead(capteur)==1){
}
debut = millis();
dernierInstant = millis()*0.001;

}

//Fonctions cligotants ########################################################################################
void ledScenario1() { /* function ledScenario */
  ////LEDS Strip scenario
   for (int k = 0; k<3;k++){
    LCD.clear();
  for (int i = 24; i < 48; i++) {
    //leds[i] = CRGB::Goldenrod;
    leds[i].setRGB(255, 0, 127);
    leds[i + 3].setRGB(255, 0, 127);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
    if(i>=32){
      LCD.setCursor(i-32, 0);
      LCD.write((byte)0);
      LCD.setCursor(i-32, 1);
      LCD.write((byte)0);
    }
    delay(10);
  }
  }
  debut = debut + 4500;
  FastLED.clear();
  FastLED.show();
}

void ledScenario2() { /* function ledScenario */
  ////LEDS Strip scenario
  for (int k = 0; k<3;k++){
    LCD.clear();
  for (int i = 23; i >= 0; i--) {
    //leds[i] = CRGB::Goldenrod;
    leds[i].setRGB(255, 0, 127);
    leds[i - 3].setRGB(255, 0, 127);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
    if(i<=15){
      LCD.setCursor(i, 0);
      LCD.write((byte)0);
      LCD.setCursor(i, 1);
      LCD.write((byte)0);
    }
    delay(10);
  }
  }
  debut = debut + 4500;
  FastLED.clear();
  FastLED.show();
}
void refresh(double vit, int minutes, double Vmoy){ //Méthode qui met à jour les informations affichées sur l'écran (vitesse instantanée, vitesse moyenne et temps de parcours)
      LCD.clear(); //On efface ce qui est affiché sur l'écran
      LCD.setCursor(0, 0);  //On place le curseur en (0,0) c'est-à-dire sur l'emplcament au niveau de la première colone et de la première ligne
      LCD.print("Vit");     // On y écrit la chaîne de caractère "Vit"
      LCD.setCursor(5, 0);
      LCD.print("Min");
      LCD.setCursor(0, 1);
      LCD.print(String(vit, 1));
      LCD.setCursor(10, 0);
      LCD.print("Vmoy");
      LCD.setCursor(10, 1);
      LCD.print(String(Vmoy, 1));
      if (minutes < 10){
        LCD.setCursor(7, 1);
        LCD.print(minutes);
      }
      else if (minutes < 100){
        LCD.setCursor(6, 1);
        LCD.print(minutes);
      }
      else{
        LCD.setCursor(5, 1);
        LCD.print(minutes);
      }
}

//LOOP#####################################################################################################
void loop(){
  
while(digitalRead(capteur) == 0){ 
  if(digitalRead(Bdroite) ==1 && digitalRead(Bgauche) ==1){
    debut = millis();
    compteur = 0;
  }
   else if(digitalRead(Bdroite) ==1){
      ledScenario1();
    }
    else if(digitalRead(Bgauche) ==1){
      ledScenario2();
    }
  }
    
    vit = ((pi*diametre)*0.001)/(((millis()*0.001)-dernierInstant)/36000);
     
    dernierInstant = millis()*0.001;
    
    minutes = millis()*(0.001/60);
    
    if(vit < 50){
      compteur++;
      Vmoy = ((pi*diametre*compteur)*0.001)/((millis()-debut)*(0.001/36000));
      refresh(vit,minutes,Vmoy);
    }
    while(digitalRead(capteur)){
    }
  delay(10);
  }
