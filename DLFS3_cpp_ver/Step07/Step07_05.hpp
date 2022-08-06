// 자동미분 구현
// 역전파 구현시작
// Function, FunctionConcrete 분리.
// https://stackoverflow.com/questions/20013901/im-getting-an-error-invalid-use-of-incomplete-type-class-map
// 답변에 따라, hpp와 cpp 분리해보자.
class Variable;
class Function;
class Square;
class Exp;

class Variable{
    private:
        float m_data;
        float m_grad;
        Function* m_creator; // 이거 순환참조 안뜨나?
    public:
        Variable(float data=0, float grad=0, Function* creator=NULL);
        void Set_grad(float grad);
        void Set_creator(Function* creator);
        float Get_data();
        float Get_grad();
        Function* Get_creator();
        void Backward();
};

class Function{
    private:
        Variable* inputted;
        Variable outputted;
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

// f 에 Exp, Square 들어가도 될까?
// https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
// Function 같은 가상클래스는 애초에 "인스턴스화" 자체가 안되지만, 참조자나 포인터로 넘겨주는건 허용된다!
float numerical_diff(Function& f, Variable x, float eps=1e-4);