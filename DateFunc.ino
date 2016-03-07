void DateFunc()
{
   b= button_pressed(analogRead(A1));
  delay(500);
  while(b=='N')
  {
  b= button_pressed(analogRead(A1));
  delay(500);
  }
  if(b!='N')
  {
   if(b=='O') 
  {
  Wire.beginTransmission(0x6F);
  Wire.write(0x03); //status reg addr
  Wire.endTransmission();
  Wire.requestFrom(0x6F,3); // now get 6 bytes of data...
  dates=Wire.read();
  months=Wire.read();
  years=Wire.read() ;
  delay(1000); 
  //RTC current date
  printm();
  
  //after display
  delay(1000);
  lcd.setCursor(1,2);
  lcd.print("Set Date");
  
  delay(1000);
    Dt();    //function to set day
  delay(500);
printm();   //display current values
  lcd.setCursor(1,2);
  lcd.print("Set Month");
  
  delay(1000);
   Mon();    //function to set month
   delay(500);
printm();    //display current values
  lcd.setCursor(1,2);
  lcd.print("Set Year");
  
  delay(1000);
  Yr();     //function to set year
  delay(500);
  printm();  //display current values
   
  Callme();
  b='N';
  }
  }
}
int Dt()
 {
   while(1)
   { 
    b= button_pressed(analogRead(A1));
    delay(500);
    while(b=='N')
    {
     b= button_pressed(analogRead(A1));
     delay(500);
    }
   if(b!='N')
   {
    if(b=='D')
   { if(dates>=31)
      dates=1;
      else 
      dates++;
  }
  if(b=='U')
  { if(dates<=1)
      dates=31;
      else 
      dates--;
      
  }
  if(b=='O')
   return dates;
   
printm();
   }
  }
}
//setting month
  int Mon()
 {
   while(1)
   { b= button_pressed(analogRead(A1));
    delay(500);
    while(b=='N')
    {
     b= button_pressed(analogRead(A1));
     delay(500);
    }
   if(b!='N')
   {
    if(b=='D')
   { if(months>=12)
     months=1;
      else 
     months++;
  }
  if(b=='U')
  { if(months<=1)
      months=12;
      else 
      months--;
      
  }
  if(b=='O')
   return months;
   
printm();
  }
 }
}
//setting year
 int Yr()
 {
   while(1)
   {  b= button_pressed(analogRead(A1));
    delay(500);
    while(b=='N')
    {
     b= button_pressed(analogRead(A1));
     delay(500);
    }
   if(b!='N')
   {
    if(b=='D')
    {if(years>=50)
      years=0;
      else 
       years++;
    }
    if(b=='U')
  { if(years<=0)
            years=50;
      else 
           years--;
      
  }
    if(b=='O')
   return years;
     printm();
  } 
 }
}
//function to display all the values of date

void printm()
 { lcd.setCursor(0,1);
   lcd.print("                    ");
   lcd.setCursor(0,2);
   lcd.print("                    ");
 
 // lcd.clear();
  lcd.setCursor(0,1); 
  lcd.print("Date: ");
  lcd.setCursor(8,1); 
  lcd.print(bcdToDec(dates));
  lcd.print('/');
  lcd.print(bcdToDec(months));
  lcd.print('/');
  lcd.print(bcdToDec(years));
   delay(1000); 
 }

 
 byte readStatusReg(byte val)
 {
  Wire.beginTransmission(0x6F);
  Wire.write(0x07); // read status reg to clr bits
  Wire.endTransmission();
  Wire.requestFrom(0x6F,3); // now get the byte of data...
  statusReg=Wire.read();
  return(statusReg);
 }

//function to convert from bcd to decimal
byte bcdToDec(byte val)
{
  return ( (val/16*10) + (val%16) );
}
//function to convert from decimal to bcd
byte decToBcd(byte val)
{
  return ( (val/10*16) + (val%10) );
}

// function to write all the values to RTC
 void Callme()
 { 
   Wire.beginTransmission(0x6F);
   Wire.write(0x07); //status register
   Wire.write(0x90);  //
   Wire.endTransmission();
   Wire.beginTransmission(0x6F);
   Wire.write(0x03);
    Wire.write(dates); //date
   Wire.write(months); //month
   Wire.write(years); //year
   Wire.endTransmission();
   Wire.beginTransmission(0x6F);
   Wire.write(0x07); //status reg addr
   Wire.endTransmission();
   readStatusReg(statusReg); 
 }

