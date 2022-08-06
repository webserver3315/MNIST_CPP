// 자동미분 구현
#include <bits/stdc++.h>
using namespace std;
//쓸데없는 클래스변수 쳐냄. 우리가 기억할 essential 한 것은 인스턴스 변수이며, inputted와 outputted 뿐.
class Variable{
    private:
        float m_data;
        float m_grad;
    public:
        Variable(){
            m_data=0;
        }
        Variable(float data){
            m_data = data;
        }
        float Get_data(){
            return m_data;
        }
        float Get_grad(){
            return m_grad;
        }
};

class Function{
    private:
        Variable inputted;
        Variable outputted;
    public:
        Function(){
        }
        Variable Get_inputted(){
            return inputted;
        }
        Variable Get_outputted(){
            return outputted;
        }
        void Set_inputted(Variable input){
            inputted = input;
        };
        void Set_outputted(Variable input){
            outputted = input;
        }
        virtual Variable Forward(Variable input) = 0;
};

class Square : public Function{
    public:
        Square(){
            Set_inputted(Variable(0));
            Set_outputted(Variable(0));
        }
        Variable Forward(Variable input){
            Set_inputted(input);
            Set_outputted(Variable(pow(input.Get_data(),2)));
            return Get_outputted();
        }
};

class Exp : public Function{
    public:
        Exp(){
            Set_inputted(Variable(0));
            Set_outputted(Variable(0));
        }
        Variable Forward(Variable input){
            Set_inputted(input);
            Set_outputted(Variable(exp(input.Get_data())));
            return Get_outputted();
        }
};

// f 에 Exp, Square 들어가도 될까?
// https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
// Function 같은 가상클래스는 애초에 "인스턴스화" 자체가 안되지만, 참조자나 포인터로 넘겨주는건 허용된다!
float numerical_diff(Function& f, Variable x, float eps=1e-4){ 
    Variable x0 = Variable(x.Get_data()-eps);
    Variable x1 = Variable(x.Get_data()+eps);
    Variable y0 = f.Forward(x0);
    Variable y1 = f.Forward(x1);
    return (y1.Get_data() - y0.Get_data())/(2*eps);
}

class foo : public Function{
    public:
        foo(){
            Set_inputted(Variable(0));
            Set_outputted(Variable(0));
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