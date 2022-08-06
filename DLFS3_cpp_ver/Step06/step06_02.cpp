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
        Variable(float data, float grad){
            m_data = data;
            m_grad = grad;
        }
        void Set_grad(float grad){
            m_grad = grad;
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
        virtual Variable Forward(Variable x) = 0;
        virtual float Backward(float gy) = 0;
};

class Square : public Function{
    public:
        Square(){
            Set_inputted(Variable(0));
            Set_outputted(Variable(0));
        }
        Variable Forward(Variable x){
            Set_inputted(x);
            Set_outputted(Variable(pow(x.Get_data(),2)));
            return Get_outputted();
        }
        float Backward(float gy){
            float x = Get_inputted().Get_data();
            float gx = 2 * x * gy;
            return gx;
        }
};

class Exp : public Function{
    public:
        Exp(){
            Set_inputted(Variable(0));
            Set_outputted(Variable(0));
        }
        Variable Forward(Variable x){
            Set_inputted(x);
            Set_outputted(Variable(exp(x.Get_data())));
            return Get_outputted();
        }
        float Backward(float gy){
            float x = Get_inputted().Get_data();
            float gx = exp(x) * gy;
            return gx;
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
        Variable Forward(Variable x){
            Set_inputted(x);
            Square A = Square();
            Exp B = Exp();
            Square C = Square();
            Set_outputted(C.Forward(B.Forward(A.Forward(x))));
            return Get_outputted();
        }
        float Backward(float gy){
            return float(0);
        }
};

int main(){
    Square f1 = Square();
    Variable x1 = Variable(2.0);
    float dy1 = numerical_diff(f1,x1);
    cout<<"dy is "<<dy1<<endl;

    Exp f2 = Exp();
    Variable x2 = Variable(2.0);
    float dy2 = numerical_diff(f2,x2);
    cout<<"dy2 is "<<dy2<<endl;

    foo f3 = foo();
    Variable xx = Variable(0.5);
    float dydy = numerical_diff(f3,xx);
    cout<<"dydy is "<< dydy <<endl;



    Square A = Square();
    Exp B = Exp();
    Square C = Square();

    Variable x = Variable(0.5);
    Variable a = A.Forward(x);
    Variable b = B.Forward(a);
    Variable y = C.Forward(b);

    y.Set_grad(1);
    b.Set_grad(C.Backward(y.Get_grad()));
    cout <<"dy/db is "<<b.Get_grad()<<endl;
    a.Set_grad(B.Backward(b.Get_grad()));
    cout <<"dy/da is "<<a.Get_grad()<<endl;
    x.Set_grad(A.Backward(a.Get_grad()));
    cout <<"dy/dx is "<<x.Get_grad()<<endl;
    return 0;
}