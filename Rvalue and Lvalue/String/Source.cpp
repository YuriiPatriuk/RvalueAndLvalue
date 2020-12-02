#include <iostream>
#include "String.h"

int main()
{
    String s1("qweqwe");
    String s2("www");
    s1.print();
    s2.print();

    String::swap(move(s1), move(s2));
    cout << "s1" << endl;
    s1.print();
    cout << "s2" << endl;
    s2.print();

    String copy(move(s1));
    copy.print();

    s1 = move(s2);
    s1.print();

   
}