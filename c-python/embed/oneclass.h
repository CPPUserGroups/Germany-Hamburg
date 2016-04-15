#ifndef ONECLASS_H
#define ONECLASS_H

#include <string>

class OneClass {
  int number;
  std::string text;
public:
  OneClass(int num);
  ~OneClass();
  void set(const std::string& s);
  void set(int n);
  std::string calc() const;
  int getNumber() const;
};

#endif // ONECLASS_H
