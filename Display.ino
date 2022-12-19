void refresh()
{
  lcd.setCursor(0, 0);
  lcd.print("          ");
  lcd.setCursor(0, 0);
  lcd.print(dex[1]);

  lcd.setCursor(0, 1);
  lcd.print("          ");
  lcd.setCursor(0, 1);
  lcd.print(dex[2]);

  lcd.setCursor(0, 2);
  lcd.print("          ");
  lcd.setCursor(0, 2);
  lcd.print(dex[3]);

  lcd.setCursor(0, 3);
  lcd.print("          ");
  lcd.setCursor(0, 3);
  lcd.print(dex[4]);  
}

void setbackground()
{
  lcd.setCursor(10, 0); // Set the cursor on the third column and first row.
  lcd.print("-IPM"); // Print the string "          "
  lcd.setCursor(10, 1); // Set the cursor on the third column and first row.
  lcd.print("-Rotation"); // Print the string "          "
  lcd.setCursor(10, 2); // Set the cursor on the third column and first row.
  lcd.print("-Pulses"); // Print the string "          "
 // lcd.setCursor(10, 3);
  //lcd.print("-RPM ");
}
