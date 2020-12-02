#include <iostream>
#include"Array.h"
using namespace std;

void funcValueRef(int& num) //referance to Lvalue modifable
{
    cout << "funcValueRef: " << ++num << endl;
}

void funcConstValueRef(const int& num) //referance to Lvalue nonmodifable
{
    cout << "funcConstValueRef: " << num << endl;
}

void funcRightValueRef(int&& num)
{
    num *= 5;
    cout << "funcRightValueRef: " << num << endl;
}

int main()
{
    //// Lvalue(modifable, nonmodifable)  Rvalue
    //int val = 123; // val -> lvalue   123 ->Rvalue
    //
    //cout << &val << endl; //Lvalue modifable
    //const int SIZE = 100;
    //cout << &SIZE << endl; //Lvalue nonmodifable
    ////123, 1.2, true, "string" -> Rvalue
    //
    //int arr[3]{ 10, 21, 32 };
    //arr[1]++;
    //funcValueRef(arr[0]);
    ////funcValueRef(arr[0] + 25); //error compile. We pass Rvalue

    //funcConstValueRef(SIZE);
    //funcConstValueRef(arr[2]);
    //funcConstValueRef(arr[0]+33); //Rvalue ---> const Lvalue &

    //int&& ref = arr[0] + 1; //int&& - referense to Rvalue
    //++ref;
    //cout << "&ref :" << &ref << endl;

    //cout << "~~~~~~~~~~~~DEMO~~~~~\n";
    //funcRightValueRef(arr[0]+0);
    //funcRightValueRef(move(1000 + arr[0]));

    //string one = "ONEONEONEONEONEONEONEONEONEONEONEONEONEONE", two = "TWOTWOTWOTWOTWOTWOTWOTWOTWOTWOTWOTWOTWOTWOTWOTWO";
    //cout << "Adress buffer one: " << (void*)one.data()<< endl;
    //cout << "Adress buffer two: " << (void*)two.data()<< endl;
    //string tmp(move(one)); //copy ctor
    //one = move(two);// operator = assign with COPY
    //two = move(tmp);
    //cout << "After swap: " << one << "," << two << endl;
    //cout << "Adress buffer one: " << (void*)one.data() << endl;
    //cout << "Adress buffer two: " << (void*)two.data() << endl;

    Array arr(5, 1);
    arr[0] = 500;
    arr[10] = 12345;

    Array arr2(7);
    arr2[3] = 11;
    arr2[4] = 33;

    Array arr3 = arr + arr2;
    arr3.print();

    /*Array tmp = move(arr);
    arr = move(arr2);
    arr2 = move(tmp);

    arr.print();
    arr2.print();*/

}
