#include "oneclass.h"
#include <iostream>

OneClass::OneClass(int num) 
  : number(num) 
{ 
  std::cout << "OneClass(" << num << ") " << (void*)this << std::endl; 
}

OneClass::~OneClass() 
{ 
  std::cout << "~OneClass() " << (void*)this << std::endl; 
}

void OneClass::set(const std::string& s) 
{ 
  text = s; 
}

void OneClass::set(int n) 
{ 
  number = n; 
}

std::string OneClass::calc() const 
{ 
  return text + ": " + std::to_string(number); 
}

int OneClass::getNumber() const 
{ 
  return number; 
}
