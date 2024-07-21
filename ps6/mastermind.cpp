#include <Arduino.h>
#include <time.h>
#include <string.h>

#include "mastermind.h"
#include "lcd_wrapper.h"

char* generate_code(bool repeat, int length)
{
  if(length>10&&repeat==false)
  {
    return NULL;
  }
  srand(time(0));
  char *code=(char*)calloc(1,length+1);
  int a=0;
  int q=0;
  for(int i=0;i<length;i++)
  {
    a=random(10)+48;
    if(repeat==false)
    {
      for(int x=0;x<i;x++)
      {
        if(a==code[x])
        {
          a=random(10)+48;
          x=-1;
        }
      }
    }
    code[i]=(char)a;
  }
  return code;
}

void play_game(char* secret)
{
  lcd_init();
  char txt[]="MASTERMIND";
  lcd_print_at(0,0,txt);
  char txt2[]="Guess my number";
  lcd_print_at(1,0,txt2);
  delay(2000);
  lcd_clear();
  //lcd_print_at(1,0,secret);
  char **history;
  history= (char**)calloc(11,sizeof(char*));
  int entry_nr=0;
  int guess_nr=0;
  int peg_a;
  int peg_b;
  turn_off_leds();
  for(int i=0;i<10;i++)
  {
    history[i] =(char*)calloc(5,sizeof(char));
    strcpy(history[i],"0000");
    char text[10];
    char turn[]="Turn:";
    lcd_print_at(0,0,turn);
    sprintf(text, "%d", (i+1));
    lcd_print_at(0,6,text);
    char guess[]="Your guess:";
    lcd_print_at(1,0,guess);
    lcd_print_at(1,12,history[i]);
    while(digitalRead(BTN_ENTER_PIN)!=HIGH)
    {
      if(digitalRead(BTN_1_PIN)==HIGH)
      {
        int a=0;
        while(digitalRead(BTN_1_PIN)==HIGH)
        {
          if(digitalRead(BTN_2_PIN)==HIGH)
          {
            a=1;
            if(entry_nr>1)
            {
              entry_nr--;
            }
            if(entry_nr>=1)
            {
              render_history(secret, history, entry_nr);
            }
          }
          else if(digitalRead(BTN_3_PIN)==HIGH)
          {
            a=1;
            if(entry_nr<i)
            {
              entry_nr++;
            }
            if(entry_nr>=1)
            {
              render_history(secret, history, entry_nr);
            }
          }
        }
        if(a==0)
        {
          ++(history[i][0]);
          if(history[i][0]==58)
          {
            history[i][0]=48;
          }
          lcd_print_at(1,12,history[i]);
        }
      }
      else if(digitalRead(BTN_2_PIN)==HIGH)
      {
        while(digitalRead(BTN_2_PIN)==HIGH)
        {
        }
        ++(history[i][1]);
        if(history[i][1]==58)
        {
          history[i][1]=48;
        }
        lcd_print_at(1,12,history[i]);
      }
      else if(digitalRead(BTN_3_PIN)==HIGH)
      {
        while(digitalRead(BTN_3_PIN)==HIGH)
        {
        }
        ++(history[i][2]);
        if(history[i][2]==58)
        {
          history[i][2]=48;
        }
        lcd_print_at(1,12,history[i]);
      }
      else if(digitalRead(BTN_4_PIN)==HIGH)
      {
        while(digitalRead(BTN_4_PIN)==HIGH)
        {
        }
        ++(history[i][3]);
        if(history[i][3]==58)
        {
          history[i][3]=48;
        }
        lcd_print_at(1,12,history[i]);
      }
    }
    get_score(secret, history[i], &peg_a, &peg_b);
    turn_off_leds();
    render_leds(peg_a, peg_b);
    if(peg_a==4)
    {
      lcd_clear();
      char win[]="You win in";
      //strcpy(win,"Vyhral si na");
      lcd_print_at(0,0,win);
      char w[]="guesses";
      lcd_print_at(1,3,w);
      lcd_print_at(1,0,text);
      i=10;
      delay(2000);
    }
    else if(i>=9)
    {
      lcd_clear();
      char lose[]="You lose game";
      //strcpy(lose,"Prehral_si");
      lcd_print_at(0,0,lose);
      char sec[]="Secret was:";
      lcd_print_at(1,0,sec);
      lcd_print_at(1,12,secret);
      delay(2000);
    }
    entry_nr=i+1;
    lcd_clear();
    while(digitalRead(BTN_ENTER_PIN)==HIGH)
    {
    }
  }
}

void render_leds(const int peg_a, const int peg_b)
{
  int a=0;
  int b=0;
  if(a<peg_a)
  {
    a++;
    digitalWrite(LED_RED_1, HIGH);
  }
  else if(b<peg_b)
  {
    b++;
    digitalWrite(LED_BLUE_1, HIGH);
  }
  if(a<peg_a)
  {
    a++;
    digitalWrite(LED_RED_2, HIGH);
  }
  else if(b<peg_b)
  {
    b++;
    digitalWrite(LED_BLUE_2, HIGH);
  }
  if(a<peg_a)
  {
    a++;
    digitalWrite(LED_RED_3, HIGH);
  }
  else if(b<peg_b)
  {
    b++;
    digitalWrite(LED_BLUE_3, HIGH);
  }
  if(a<peg_a)
  {
    a++;
    digitalWrite(LED_RED_4, HIGH);
  }
  else if(b<peg_b)
  {
    b++;
    digitalWrite(LED_BLUE_4, HIGH);
  }
}

void turn_off_leds()
{
  digitalWrite(LED_BLUE_1, LOW);
  digitalWrite(LED_RED_1, LOW);
  digitalWrite(LED_BLUE_2, LOW);
  digitalWrite(LED_RED_2, LOW);
  digitalWrite(LED_BLUE_3, LOW);
  digitalWrite(LED_RED_3, LOW);
  digitalWrite(LED_BLUE_4, LOW);
  digitalWrite(LED_RED_4, LOW);
}

void render_history(char* secret, char** history, const int entry_nr)
{
  int peg_a;
  int peg_b;
  get_score(secret,history[entry_nr-1],&peg_a,&peg_b);
  turn_off_leds();
  render_leds(peg_a, peg_b);
  lcd_print_at(0,12,history[entry_nr-1]);
}

void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b)
{
  int i, j, usedsecret[strlen(secret)], usedguesses[strlen(guess)];
  for(i=0; i<strlen(secret); i++)
  {
    usedsecret[i]=1;
    usedguesses[i]=1;
  }

  *peg_a = *peg_b = 0;
  for(i=0; i<strlen(secret); i++)
  {
        if(guess[i]==secret[i])   
        {
            ++*peg_a;
            usedsecret[i] = usedguesses[i] = 0;
        }
  }

    for(i=0; i<strlen(secret); i++)
    {
        for(j=0; j<strlen(guess); j++)
        {
            if(secret[i]==guess[j]  &&  usedsecret[i]  &&  usedguesses[j]  &&  i != j)        
            {
                ++*peg_b;
                usedsecret[j] = usedguesses[i] = 0;
            }
        }
    }
    delay(1000);
}
