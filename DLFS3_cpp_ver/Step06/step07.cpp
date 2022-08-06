// 자동미분 구현
#include <bits/stdc++.h>
using namespace std;
//쓸데없는 클래스변수 쳐냄. 우리가 기억할 essential 한 것은 인스턴스 변수이며, inputted와 outputted 뿐.
class Function;
class Variable;

class Variable{
    private:
        float m_data;
        float m_grad;
        Function* m_creator; // 이거 순환참조 안뜨나?
    public:
        Variable(float data=0, float grad=0, Function* creator=NULL){
            m_data = data;
            m_grad = grad;
            m_creator = creator;
        }
        void Set_grad(float grad){
            m_grad = grad;
        }
        void Set_creator(Function* creator){
            // cout<<"Before: m_creator = "<<m_creator<<" creator = "<<creator<<endl;
            m_creator = creator;
            // cout<<"After: m_creator = "<<m_creator<<" creator = "<<creator<<endl;
        }
        float Get_data(){
            return m_data;
        }
        float Get_grad(){
            return m_grad;
        }
        Function* Get_creator(){
            // cout<<"Get_creator == "<<m_creator<<endl;
            return m_creator;
        }
};

class Function{
    private:
        Variable inputted;
        Variable outputted;
    public:
        Function(){

        }
        Variable& Get_inputted(){ // 여기서 & 안붙이면 복사되서 전달되므로, 아예 새로운 outputted 이므로 null이 출력된다.
            return inputted;
        }
        Variable& Get_outputted(){
            return outputted;
        }
        void Set_inputted(Variable input){ // 맞나?
            inputted = input;
        };
        void Set_outputted(Variable input){ // 맞나?
            outputted = input;
        }
        virtual Variable& Forward(Variable x) = 0;
        virtual float Backward(float gy) = 0;
};

class Square : public Function{
    public:
        Square(){
            Set_inputted(Variable(0));
            Set_outputted(Variable(0));
        }
        Variable& Forward(Variable x){
            Set_inputted(x);
            Set_outputted(Variable(pow(x.Get_data(),2))); // 이줄 빼고 아랫윗줄 전부 부모클래스로 못올리나?
            // cout<<"Square: Set_creator("<<this<<")"<<endl;
            Get_outputted().Set_creator(this);
            // cout<<"Square: Get_creator("<<Get_outputted().Get_creator()<<")"<<endl;
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
        Variable& Forward(Variable x){
            Set_inputted(x);
            Set_outputted(Variable(exp(x.Get_data())));
            // cout<<"Exp: Set_creator("<<this<<")"<<endl;
            Get_outputted().Set_creator(this);
            // cout<<"Exp: Get_creator("<<Get_outputted().Get_creator()<<")"<<endl;
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

int main(){

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

    
    cout << "y.creator == "<< y.Get_creator() << " C =="<< &C <<endl;
    cout << "y.creator.input == " << &(C.Get_inputted()) << " b ==" << &b <<endl;
    // cout << "y.creator.input.creator == "<< <<endl;
    // cout << "y.creator.input.creator.input == "<< <<endl;
    // cout << "y.creator.input.creator.input.creator == "<< <<endl;
    // cout << "y.creator.input.creator.input.creator.input == "<< <<endl;
    
    
    // assert(y.Get_creator() == C);
    return 0;
}