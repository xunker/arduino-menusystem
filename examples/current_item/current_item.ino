/*
  current_item.ino - Example code using the menu system library.
  
  This example shows only the current menu item.
  
  Created by Jon Black, May 25th 2012.
  Released into the public domain.
  
  License: GPL 3
*/

#include <MenuSystem.h>

// Menu variables
MenuSystem ms;
Menu mm("");
MenuItem mm_mi1("Level 1 - Item 1 (Item)");
MenuItem mm_mi2("Level 1 - Item 2 (Item)");
Menu mu1("Level 1 - Item 3 (Menu)");
MenuItem mu1_mi1("Level 2 - Item 1 (Item)");

// Example variables
bool bRanCallback = false;
bool bForward = true;

// Menu callback function
// In this example all menu items use the same callback.

void on_item1_selected(MenuItem* p_menu_item)
{
  Serial.println("Item1 Selected");
  bRanCallback = true;
  bForward = true;
}

void on_item2_selected(MenuItem* p_menu_item)
{
  Serial.println("Item2 Selected");
  bRanCallback = true;
}

void on_item3_selected(MenuItem* p_menu_item)
{
  Serial.println("Item3 Selected");
  bRanCallback = true;
  bForward = false;
}

// Standard arduino functions

void setup()
{
  Serial.begin(9600);
  
  // Menu setup
  mm.add_item(&mm_mi1, &on_item1_selected);
  mm.add_item(&mm_mi2, &on_item2_selected);
  mm.add_menu(&mu1);
  mu1.add_item(&mu1_mi1, &on_item3_selected);
  ms.set_root_menu(&mm);
}

void loop()
{
  // Display the menu
  Serial.println(ms.get_current_menu_name());
  
  // Simulate using the menu by walking over the entire structure.
  ms.select();
  
  if (bRanCallback)
  {
    if (bForward)
      ms.next();
    else
      ms.prev();
    bRanCallback = false;
  }
  
  // Wait for two seconds so the output is viewable
  delay(2000);
}
