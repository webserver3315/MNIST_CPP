// // 자동미분 구현
// #include <bits/stdc++.h>
// using namespace std;

// class Variable{
//     private:
//         float m_data;
//         float m_grad;
//     public:
//         Variable(){
//             m_data=0;
//             m_grad=0;
//         }
//         Variable(float data){
//             m_data = data;
//             m_grad = 0;
//         }
//         float Get_data(){
//             return m_data;
//         }
//         float Get_grad(){
//             return m_grad;
//         }
// };

// class Function{
//     private:
//         static Variable x; // static 붙으면 class 변수
//         static Variable y;
//         // 얘가 핵심이다. 인스턴스 변수이기 때문
//         Variable inputted; // static 없으면 instance 변수
//     public: // 어차피 추상클래스라 인스턴스 만들 일 업서서 생성자도 필요없음
//         void Set_x(Variable input){
//             x=input;
//         }
//         void Set_y(Variable input){
//             y=input;
//         }
//         void Set_inputted(Variable input){
//             inputted = input;
//         }
//         Variable Get_x(){
//             return x;
//         }
//         Variable Get_y(){
//             return y;
//         }
//         Variable Get_inputted(){
//             return inputted;
//         }
//         virtual Variable Forward(Variable input) = 0;
//         virtual Variable Backward(Variable gy) = 0;
// };

// class Square : public Function{
//     public:
//         Square(Variable input = Variable(0)){
//             Set_x(input);
//             Set_y(Variable(0));
//             Set_inputted(input);
//         }
//         Variable Forward(Variable input){
//             float ret = pow(input.Get_data(),2);
//             Set_y(Variable(ret));
//             return Get_y();
//         }
//         Variable Backward(Variable gy){
//             float fl_inputted = Get_inputted().Get_data();
//             Set_x(Variable(fl_inputted));
//             float fl_gy = gy.Get_data();
//             float fl_gx = 2*fl_inputted*fl_gy;
            
            
//         }
// };

// class Exp : public Function{
//     public:
//         Exp(Variable input = Variable(0)){
//             Set_x(input);
//             Set_y(Variable(0));
//             Set_inputted(input);
//         }
//         Variable Forward(Variable input){
//             float ret = exp(input.Get_data());
//             Set_y(Variable(ret));
//             return Get_y();
//         }
//         Variable Backward(Variable gy){

//         }
// };

// // f 에 Exp, Square 들어가도 될까?
// // https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
// // Function 같은 가상클래스는 애초에 "인스턴스화" 자체가 안되지만, 참조자나 포인터로 넘겨주는건 허용된다!
// float numerical_diff(Function& f, Variable x, float eps=1e-4){ 
//     Variable x0 = Variable(x.Get_data()-eps);
//     Variable x1 = Variable(x.Get_data()+eps);
//     Variable y0 = f.Forward(x0);
//     Variable y1 = f.Forward(x1);
//     return (y1.Get_data() - y0.Get_data())/(2*eps);
// }

// class foo : public Function{
//     public:
//         foo(){
//             Set_x(Variable(0));
//             Set_y(Variable(0));
//         }
//         Variable Forward(Variable input){
//             Square A = Square();
//             Exp B = Exp();
//             Square C = Square();
//             return C.Forward(B.Forward(A.Forward(input)));
//         }
//         Variable Backward(Variable gy){
            
//         }
// };

// int main(){
//     Square f = Square();
//     Variable x = Variable(2.0);
//     float dy = numerical_diff(f,x);
//     cout<<"dy is "<<dy<<endl;

//     Exp f2 = Exp();
//     Variable x2 = Variable(2.0);
//     float dy2 = numerical_diff(f2,x2);
//     cout<<"dy2 is "<<dy2<<endl;

//     foo f3 = foo();
//     Variable xx = Variable(0.5);
//     float dydy = numerical_diff(f3,xx);
//     cout<<"dydy is "<< dydy <<endl;
//     return 0;
// }

int main(){
    return 0;
}