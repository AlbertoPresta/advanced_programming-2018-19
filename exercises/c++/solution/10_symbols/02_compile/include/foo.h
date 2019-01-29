
#include<string>
#include<iostream>
#ifndef FOO
#define FOO

extern std::string to_upper(const std::string& os);

struct Foo{
  static double f;
  std::string bar;
  Foo() = delete;
    Foo(const std::string& s) : bar(to_upper(s)){};
};

double Foo::f;
#endif
