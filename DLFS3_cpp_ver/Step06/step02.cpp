#include <bits/stdc++.h>
using namespace std;

class Variable{
    private:
        int m_data;
    public:
        Variable(int data=0){
            m_data = data;
        }
        int Get(){
            return m_data;
        }
};

class Function{
    private:
        Variable x;
        Variable y;
    public:
        Function(){
            x=Variable(0);
            y=Variable(0);
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

int main(){
    // Variable x = Variable(10);
    // Function f = Function(x);
    // Variable y=f.Forward();
    // cout<<typeid(y).name()<<endl;    
    // printf("x.m_data = %d\n",x.Get());
    // printf("y.m_data = %d\n",y.Get());

    Variable x = Variable(10);
    Square f = Square();
    Variable y = f.Forward(x);
    printf(typeid(y).name());
    cout<<y.Get()<<endl;
    return 0;
}