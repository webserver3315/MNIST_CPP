// 자동미분 구현
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

// f 에 Exp, Square 들어가도 될까?
// https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
// Function 같은 가상클래스는 애초에 "인스턴스화" 자체가 안되지만, 참조자나 포인터로 넘겨주는건 허용된다!
float numerical_diff(Function& f, Variable x, float eps=1e-4){ 
    Variable x0 = Variable(x.Get()-eps);
    Variable x1 = Variable(x.Get()+eps);
    Variable y0 = f.Forward(x0);
    Variable y1 = f.Forward(x1);
    return (y1.Get() - y0.Get())/(2*eps);
}

class foo : public Function{
    public:
        foo(){
            Set_x(Variable(0));
            Set_y(Variable(0));
        }
        Variable Forward(Variable input){
            Square A = Square();
            Exp B = Exp();
            Square C = Square();
            return C.Forward(B.Forward(A.Forward(input)));
        }
};

int main(){
    Square f = Square();
    Variable x = Variable(2.0);
    float dy = numerical_diff(f,x);
    cout<<"dy is "<<dy<<endl;

    Exp f2 = Exp();
    Variable x2 = Variable(2.0);
    float dy2 = numerical_diff(f2,x2);
    cout<<"dy2 is "<<dy2<<endl;

    foo f3 = foo();
    Variable xx = Variable(0.5);
    float dydy = numerical_diff(f3,xx);
    cout<<"dydy is "<< dydy <<endl;
    return 0;
}