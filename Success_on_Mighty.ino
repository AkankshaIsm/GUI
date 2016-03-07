#include <Wire.h>   //Serial Communication
#include <LiquidCrystal_I2C.h>   //LCD I2C 
//macros defined
#define EN2_VREG_PIN                     PORTA6
#define EN2_VREG_OUT			(DDRA	|=	_BV(EN2_VREG_PIN))               //For new board - mighty 1284p
#define EN2_VREG_ENABLE			(PORTA	|=	_BV(EN2_VREG_PIN))
#define EN2_VREG_DISABLE		(PORTA	&=	~(_BV(EN2_VREG_PIN)))

LiquidCrystal_I2C lcd(0x3F,20,4);
//variables for Time
int scrollPos=0;
int scrollPos1=0;
int scrollPos2=0;
int scrollPos3=0;
int scrollPos4=0;
char x,y,z,w,p,g;
char* menu[]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22",
"23"};
char menu1[]={'0','1','2','3','4','5'};
char menu2[]={'0','1','2','3','4','5','6','7','8','9'};
char menu3[]={'0','1','2','3','4','5'};
char menu4[]={'0','1','2','3','4','5','6','7','8','9'};
char m1,m2,s1,s2;
char* hr;

//Variables for Date
int scrollPos5=0;
int scrollPos6=0;
int scrollPos7=0;

char x1,y1,z1;
char* menu5[]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22",
"23","24","25","26","27","28","29","30","31"};
char* menu6[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char* menu7[]={"1995","1996","1997","1998","1999","2000","2001","2002","2003","2004","2005","2006","2007","2008","2009","2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020"};

char* m5;
char* m6;
char* m7;

void setup()
{EN2_VREG_OUT;                  //For the new board mighty 1284p
 EN2_VREG_ENABLE; 
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0,0);
 //Calling the main menu
 mainMenu();
 //for Serial Communication
 Serial.begin(9600);
  
}

void loop()
{   
  x=Serial.read();
  //for time
   if(x=='t')
   {lcd.clear();
     lcd.setCursor(5,2);
     lcd.print("00:00:00");
     lcd.setCursor(5,2);
     lcd.cursor();
    }
  lcd.noCursor();
 
  
  if(x=='h')  //For Hour 
  {lcd.clear();
   hourt();
  }
  
  if(x=='a')  // for minutes decimal place
  {lcd.clear();
  loop1a();
  }

  if(x=='b')   //for minutes unit place
  {lcd.clear();
  loop2a();
  }

  if(x=='c')  //for second's decimal place
  {lcd.clear();
  loop1b();
  }

  if(x=='f')  //for second's unit place
  {lcd.clear();
 loop2b();
  }
  //for date
  if(x=='d')   
   {lcd.clear();
     lcd.setCursor(5,2);
     lcd.print("00:xxx:0000");
     lcd.setCursor(5,2);
     lcd.cursor();
    }
  lcd.noCursor();
 
  
  if(x=='n')  //for day
  {lcd.clear();
   dayt();
  }
  
  if(x=='o')   //for month
  {lcd.clear();
  montht();
  }

  if(x=='p')    //for year
  {lcd.clear();
  yeart();
  }
}

//The main menu
void mainMenu()
{
 lcd.print("Welcome...");
 lcd.setCursor(0,1);
 lcd.print("Enter t for Time");
 lcd.setCursor(0,2);
 lcd.print("Enter d for Date");
}

//Hour Function
void hourt()
{ 
  drawMenu();
  while(1)
  {   y=Serial.read();
      if(y=='2')
     scrollUp();  //scrolling up of values
        if(y=='8')
     scrollDown();   //scrolling down of values
        if(y=='5')
        { hr=menu[scrollPos];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(hr);
           lcd.print(":00:00");
           lcd.setCursor(8,2);
           lcd.cursor();
           break;
        }
        lcd.noCursor();
 }

}
// for minutes decimal place
void loop1a()
{  
drawMenu1();
  while(1)
  { z=Serial.read();
   if(z=='2')
     scrollUp1();     //scrolling up of values
     if(z=='8')
     scrollDown1();  //scrolling down of values
      if(z=='5')
        { m1=menu1[scrollPos1];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(hr);
           lcd.print(":");
           lcd.print(m1);
           lcd.print("0:00");
           lcd.setCursor(9,2);
           lcd.cursor();
           break;
        }
        
 }
}

//for minutes unit place
 void loop2a()
{ 
  
  drawMenu2();
  while(1)
  {  g=Serial.read();
  if(g=='2')
     scrollUp2();   //scrolling up of values
        if(g=='8')
     scrollDown2();   //scrolling down of values
        if(g=='5')
        { m2=menu2[scrollPos2];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(hr);
           lcd.print(":");
           lcd.print(m1);
           lcd.print(m2);
           lcd.print(":00");
           lcd.setCursor(11,2);
           lcd.cursor();
           break;
        }
        lcd.noCursor();
 }
}
//for second's decimal place
void loop1b()
{ 
drawMenu3();
  while(1)
  { w=Serial.read();
   if(w=='2')
     scrollUp3();  //scrolling up of values
        if(w=='8')
     scrollDown3();  //scrolling down of values
        if(w=='5')
        { s1=menu3[scrollPos3];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(hr);
           lcd.print(":");
           lcd.print(m1);
           lcd.print(m2);
           lcd.print(":");
           lcd.print(s1);
           lcd.print("0");
           lcd.setCursor(12,2);
           lcd.cursor();
           break;
        }
        lcd.noCursor();
 }
}

//second's unit place
void loop2b()
{  
drawMenu4();
  while(1)
  { p=Serial.read();
    if(p=='2')
     scrollUp4();  //scrolling up of values
        if(p=='8')
     scrollDown4();  //scrolling down of values
        if(p=='5')
        { s2=menu4[scrollPos4];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(hr);
           lcd.print(":");
           lcd.print(m1);
           lcd.print(m2);
           lcd.print(":");
           lcd.print(s1);
           lcd.print(s2);
           break;
        }
        lcd.noCursor();
 }
}

void drawMenu()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
      lcd.print(menu[i+scrollPos]);
    }
 }
 
 void scrollUp()
 { scrollPos++;
   if(scrollPos > 0)
    {drawMenu();
    }
   
 }
 
void scrollDown()
 { (scrollPos--);
   if(scrollPos < 20)  //numMenuItems-noLcdRows
      {
       drawMenu();
      }
 }  
 void drawMenu1()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
    lcd.print(menu1[i+scrollPos1]);
    }
    
    
    
 }
 
 void scrollUp1()
 { (scrollPos1++);
   if(scrollPos1 > 0)
    {drawMenu1();
    }
    
 }
 
void scrollDown1()
 { (scrollPos1--);
   if(scrollPos1 < 2)  //numMenuItems-noLcdRows
      {
       drawMenu1();
      }
 }  
 void drawMenu2()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
    lcd.print(menu2[i+scrollPos2]);
    }
    
    
    
 }
 
 void scrollUp2()
 { scrollPos2++;
   if(scrollPos2>0)
    {drawMenu2();
    }
    
 }
 
void scrollDown2()
 { scrollPos2--;
   if(scrollPos2<6)  //numMenuItems-noLcdRows
      {
       drawMenu2();
      }
 }   
  void drawMenu3()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
    lcd.print(menu3[i+scrollPos3]);
    }
    
    
    
 }
 
 void scrollUp3()
 { scrollPos3++;
   if(scrollPos3>0)
    {drawMenu3();
    }
   
 }
 
void scrollDown3()
 { scrollPos3--;
   if(scrollPos3<6)  //numMenuItems-noLcdRows
      {
       drawMenu3();
      }
 }   
  void drawMenu4()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
    lcd.print(menu4[i+scrollPos4]);
    }
    
    
    
 }
 
 void scrollUp4()
 { scrollPos4++;
   if(scrollPos4>0)
    {drawMenu4();
    }
    
 }
 
void scrollDown4()
 { scrollPos4--;
   if(scrollPos4<6)  //numMenuItems-noLcdRows
      {
       drawMenu4();
      }
 }   
 
/* The DATE function */ 
 
 //for date
 void dayt()
{ drawMenu5();
  while(1)
  {   y1=Serial.read();
      if(y1=='2')
     scrollUp5();
        if(y1=='8')
     scrollDown5();
        if(y1=='5')
        { m5=menu5[scrollPos5];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(m5);
           lcd.print(":xxx:0000");
           lcd.setCursor(8,2);
           lcd.cursor();
           break;
        }
        lcd.noCursor();
 }
 }
 
 
 void drawMenu5()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
      lcd.print(menu5[i+scrollPos5]);
    }
  
 }
 
 void scrollUp5()
 { scrollPos5++;
   if(scrollPos5 > 0)
    {drawMenu5();
    }
   
 }
 
void scrollDown5()
 { (scrollPos5--);
   if(scrollPos5 < 27)  //numMenuItems-noLcdRows
      {
       drawMenu5();
      }
 }  
 // for month
 void montht()
{ 
  drawMenu6();
  while(1)
  {   x1=Serial.read();
      if(x1=='2')
     scrollUp6();
        if(x1=='8')
     scrollDown6();
        if(x1=='5')
        { m6=menu6[scrollPos6];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(m5);
           lcd.print(":");
           lcd.print(m6);
          lcd.print(":0000");
           lcd.setCursor(12,2);
           lcd.cursor();
           break;
        }
        lcd.noCursor();
 }
 }
 
 
 void drawMenu6()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
      lcd.print(menu6[i+scrollPos6]);
    }
  
 }
 
 void scrollUp6()
 { scrollPos6++;
   if(scrollPos6 > 0)
    {drawMenu6();
    }
   
 }
 
void scrollDown6()
 { (scrollPos6--);
   if(scrollPos6 < 8)  //numMenuItems-noLcdRows
      {
       drawMenu6();
      }
 }  
//for year 
 void yeart()
{ 
  drawMenu7();
  while(1)
  {   z1=Serial.read();
      if(z1=='2')
     scrollUp7();
        if(z1=='8')
     scrollDown7();
        if(z1=='5')
        { m7=menu7[scrollPos7];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(m5);
           lcd.print(":");
           lcd.print(m6);
          lcd.print(":");
          lcd.print(m7);
           break;
        }
        lcd.noCursor();
 }
 }
 
 
 void drawMenu7()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
      lcd.print(menu7[i+scrollPos7]);
    }
  
 }
 
 void scrollUp7()
 { scrollPos7++;
   if(scrollPos7 > 0)
    {drawMenu7();
    }
   
 }
 
void scrollDown7()
 { (scrollPos7--);
   if(scrollPos7 < 22)  //numMenuItems-noLcdRows
      {
       drawMenu7();
      }
 }  
