#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// Initialization of LCD
LiquidCrystal_I2C lcd(0x3F,20,4);
int scrollPos=0;
char x;
char* menu[]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22",
"23"};
int menu1[]={0,1,2,3,4,5};
int menu2[]={0,1,2,3,4,5,6,7,8,9};
int* hr,m1,m2,s1,s2;
void setup()
{
 lcd.init();
 lcd.backlight();
 lcd.print("Welcome...");
 lcd.setCursor(0,1);
 lcd.print("Enter t for Time");
  lcd.setCursor(0,2);
 lcd.print("Enter d for Date");
 
 Serial.begin(9600);
  
}

void loop()
{   
   if(Serial.read()=='t')
   {lcd.clear();
     lcd.setCursor(5,2);
     lcd.print("00:00:00");
     lcd.setCursor(5,2);
     lcd.cursor();
   
   }
  lcd.noCursor();
  if(Serial.read=='h')
  {lcd.clear();
  hourt();
  }
 
  if(Serial.read=='a')
  {lcd.clear();
  loop1a();
  }

  if(Serial.read=='b')
  {lcd.clear();
  loop2a();
  }

  if(Serial.read=='c')
  {lcd.clear();
  loop1b();
  }

  if(Serial.read=='d')
  {lcd.clear();
  loop2b();
  }
}
void hourt()
{ drawMenu();
  while(1)
  { if(Serial.read()=='2')
     scrollUp();
        if(Serial.read()=='8')
     scrollDown();
        if(Serial.read()=='5')
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

void loop1a()
{ drawMenu1();
  while(1)
  { if(Serial.read()=='2')
     scrollUp1();
        if(Serial.read()=='8')
     scrollDown1();
        if(Serial.read()=='5')
        { m1=menu1[scrollPos];
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
        lcd.noCursor();
 }
  

}
void loop2a()
{ drawMenu2();
  while(1)
  { if(Serial.read()=='2')
     scrollUp1();
        if(Serial.read()=='8')
     scrollDown1();
        if(Serial.read()=='5')
        { m2=menu2[scrollPos];
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
void loop1b()
{ drawMenu1();
  while(1)
  { if(Serial.read()=='2')
     scrollUp1();
        if(Serial.read()=='8')
     scrollDown1();
        if(Serial.read()=='5')
        { s1=menu1[scrollPos];
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
void loop2b()
{ drawMenu2();
  while(1)
  { if(Serial.read()=='2')
     scrollUp2();
        if(Serial.read()=='8')
     scrollDown2();
        if(Serial.read()=='5')
        { s2=menu2[scrollPos];
           lcd.clear();
           lcd.setCursor(5,2);
           lcd.print(hr);
           lcd.print(":");
           lcd.print(m1);
           lcd.print(m2);
           lcd.print(":");
           lcd.print(s1);
           lcd.print("s2);
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
   if(scrollPos>0)
    {drawMenu();
    }
    //scrollPos--;
 }
 
void scrollDown()
 { scrollPos--;
   if(scrollPos<20)  //numMenuItems-noLcdRows
      {
       drawMenu();
      }
 }  
 void drawMenu1()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
    lcd.print(menu[i+scrollPos]);
    }
    
    
    
 }
 
 void scrollUp1()
 { scrollPos++;
   if(scrollPos>0)
    {drawMenu();
    }
    //scrollPos--;
 }
 
void scrollDown1()
 { scrollPos--;
   if(scrollPos<2)  //numMenuItems-noLcdRows
      {
       drawMenu();
      }
 }  
 void drawMenu2()
 { int i;
   for(i=0;i<4;i++)
    { lcd.setCursor(0,i);
    lcd.print(menu[i+scrollPos]);
    }
    
    
    
 }
 
 void scrollUp2()
 { scrollPos++;
   if(scrollPos>0)
    {drawMenu();
    }
    //scrollPos--;
 }
 
void scrollDown2()
 { scrollPos--;
   if(scrollPos<6)  //numMenuItems-noLcdRows
      {
       drawMenu();
      }
 }  
 
 
