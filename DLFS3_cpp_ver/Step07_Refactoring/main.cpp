// 자동미분 구현
#include <bits/stdc++.h>
#include "function_inherited.h"
#include "variable.h"
#include "function.h"

using namespace std;

float numerical_diff(Function& f, Variable x, float eps/*=1e-4*/){ 
    Variable x0 = Variable(x.Get_data()-eps);
    Variable x1 = Variable(x.Get_data()+eps);
    Variable y0 = f.Forward(x0);
    Variable y1 = f.Forward(x1);
    return (y1.Get_data() - y0.Get_data())/(2*eps);
}

int main(){

    Square A = Square();
    Exp B = Exp();
    Square C = Square();

    Variable x = Variable(0.5);
    Variable a = A.Forward(x);
    Variable b = B.Forward(a);
    Variable y = C.Forward(b);
    cout<<"y is "<<y.Get_data()<<endl;

    y.Set_grad(1);
    b.Set_grad(C.Backward(y.Get_grad()));
    cout <<"dy/db is "<<b.Get_grad()<<endl;
    a.Set_grad(B.Backward(b.Get_grad()));
    cout <<"dy/da is "<<a.Get_grad()<<endl;
    x.Set_grad(A.Backward(a.Get_grad()));
    cout <<"dy/dx is "<<x.Get_grad()<<endl;

    
    cout << "y.creator == "<< y.Get_creator() << " C =="<< &C <<endl;
    cout << "y.creator.input == " << &(C.Get_inputted()) << " b ==" << &b <<endl;
    cout << "y.creator.input.creator == "<< b.Get_creator() << " B == "<< &B<<endl;
    cout << "y.creator.input.creator.input == "<< &(B.Get_inputted()) << " a == " << &a <<endl;
    cout << "y.creator.input.creator.input.creator == "<< a.Get_creator() <<" A == " << &A<<endl;
    cout << "y.creator.input.creator.input.creator.input == "<< &(A.Get_inputted()) << " x == " << &x <<endl;    
    
    /********************** Back Prop  77p**********************/
    y.Set_grad(1);
    b.Set_grad(C.Backward(y.Get_grad()));
    a.Set_grad(B.Backward(b.Get_grad()));
    x.Set_grad(A.Backward(a.Get_grad()));
    cout<<(x.Get_grad())<<endl;
    // assert(y.Get_creator() == C);
    return 0;
}