#include "function.h"
#include <math.h>

Function::Function() {

}

Variable& Function::Get_inputted(){ // 여기서 & 안붙이면 복사되서 전달되므로, 아예 새로운 outputted 이므로 null이 출력된다.
    return *inputted;
}
Variable& Function::Get_outputted(){
    return *outputted;
}
void Function::Set_inputted(Variable* input){ // 맞나?
    inputted = input;
};
void Function::Set_outputted(Variable input){ // 맞나?
    // delete(outputted) 필요?
    outputted = input;
}


Square::Square(){
    Set_inputted(0);
    Set_outputted(Variable(0));
}
Variable& Square::Forward(Variable& x){
    Set_inputted(&x);
    Set_outputted(Variable(pow(x.Get_data(),2))); // 이줄 빼고 아랫윗줄 전부 부모클래스로 못올리나?
    Get_outputted().Set_creator(this);
    return Get_outputted();
}
float Square::Backward(float gy){
    float x = Get_inputted().Get_data();
    float gx = 2 * x * gy;
    return gx;
}

Exp::Exp(){
    Set_inputted(0);
    Set_outputted(Variable(0));
}
Variable& Exp::Forward(Variable& x){
    Set_inputted(&x);
    Set_outputted(Variable(exp(x.Get_data())));
    Get_outputted().Set_creator(this);
    return Get_outputted();
}
float Exp::Backward(float gy){
    float x = Get_inputted().Get_data();
    float gx = exp(x) * gy;
    return gx;
}