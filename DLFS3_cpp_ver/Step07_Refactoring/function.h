#ifndef FUNCTION
#define FUNCTION

#include "variable.h"
class Variable;

class Function{
    private:
        Variable* inputted;
        Variable* outputted;
    public:
        Function();
        Variable& Get_inputted();
        Variable& Get_outputted();
        void Set_inputted(Variable* input);
        void Set_outputted(Variable input);
        virtual Variable& Forward(Variable& x) = 0;
        virtual float Backward(float gy) = 0;
};

class Square : public Function{
    public:
        Square();
        Variable& Forward(Variable& x);
        float Backward(float gy);
};

class Exp : public Function{
    public:
        Exp();
        Variable& Forward(Variable& x);
        float Backward(float gy);
};
#endif