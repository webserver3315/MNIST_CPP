#ifndef VARIABLE
#define VARIABLE

#include "function.h"
class Function;

class Variable{
    private:
        float m_data;
        float m_grad;
        Function* m_creator; // 이거 순환참조 안뜨나?
    public:
        Variable(float data=0, float grad=0, Function* creator=(Function*)0);
        void Set_grad(float grad);
        void Set_creator(Function* creator);
        float Get_data();
        float Get_grad();
        Function* Get_creator();
        void Backward();
};

#endif