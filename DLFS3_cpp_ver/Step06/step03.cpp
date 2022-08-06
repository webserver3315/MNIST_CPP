#include <bits/stdc++.h>
using namespace std;

class Variable{
    private:
        float m_data;
    public:
        Variable(){
            m_data=0;
        }
        Variable(float data){
            m_data = data;
        }
        float Get(){
            return m_data;
        }
};

class Function{
    private:
        Variable x;
        Variable y;
    public:
        Function(){
            x = Variable(0);
            y = Variable(0);
        }
        Function(Variable input){
            x=input;
        }
        void Set_x(Variable input){
            x=input;
        }
        void Set_y(Variable input){
            y=input;
        }
        Variable Get_x(){
            return x;
        }
        Variable Get_y(){
            return y;
        }
        virtual Variable Forward(Variable input) = 0;
};

class Square : public Function{
    public:
        Square(){
            Set_x(Variable(0));
            Set_y(Variable(0));
        }
        Square(Variable input){
            Set_x(input);
            Set_y(Variable(0));
        }
        Variable Forward(Variable input){
            Set_y(Variable(pow(input.Get(),2)));
            return Get_y();
        }
};

class Exp : public Function{
    public:
        Exp(){
            Set_x(Variable(0));
            Set_y(Variable(0));
        }
        Variable Forward(Variable input){
            Set_y(exp(input.Get()));
            return Get_y();
        }

};

int main(){
    Square A = Square();
    Exp B = Exp();
    Square C = Square();

    Variable x = Variable(0.5);
    Variable a=A.Forward(x);
    Variable b=B.Forward(a);
    Variable y=C.Forward(b);
    cout<<"y is "<<y.Get()<<endl;
    return 0;
}