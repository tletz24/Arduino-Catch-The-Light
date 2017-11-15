//Initalize the Arduino pinouts
int button = 13;      
int slideSwitch = 3;
int ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12};

//Initalize some global variables
int wait = 100;      
int score = 0;      
int wrong = 0;      

void setup ()
{
  //Setup all of the LED pins as outputs
  for (int index = 0; index <= 8; index++)
  {
    pinMode(ledPins[index], OUTPUT);
  }
  
  //Declare the button and slide switch pinouts as inptus
  pinMode(button, INPUT);
  pinMode(slideSwitch, INPUT);  
}
void loop ()
{
   gameMode1();
}

void gameMode1() {
  //TO PLAY WITHOUT A SWITCH REMOVE "&& digitalRead(slideSwitch) == HIGH" in this line below.
  while (digitalRead(button) == HIGH && digitalRead(slideSwitch) == HIGH )   
      {
       for (int x = 0; x<=8; x++)       
        {
         digitalWrite(ledPins[x], HIGH);
         delay(wait);
         
         //Reads when the button is pushed
         if (digitalRead(button) == LOW)   
           {
             if (x == 4)                    
             {
              blinkLED(ledPins[x], 7);                 
              score++;
              wait = wait * .85;               
             }
             else
             {
               blinkLED(ledPins[x], 2);
               digitalWrite(ledPins[x], LOW);        
               x = 0;                       
               wrong++;             
               if (wrong == 5)             
               {
                 for (int x = 0; x<=8; x++)
                 {
                   digitalWrite(ledPins[x], HIGH);    
                   delay(250);
                   wrong = 0;               
                   score = 0;               
                   wait = 100;              
                 } 
               } 
             } 
           }
         digitalWrite(ledPins[x], LOW);
        } 
     }
}

//Blinks to give feedback when an LED is selected
void blinkLED(int x, int times) {
    int wait = 75;

    for(int i = 0; i <= times; i++){
    digitalWrite(x, LOW);
    delay(wait);
    digitalWrite(x, HIGH);
    delay(wait);
    }
}
