#include "variable.h"

Variable::Variable(float data/*=0*/, float grad/*=0*/, Function* creator/*=NULL*/){
    m_data = data;
    m_grad = grad;
    m_creator = creator;
}
void Variable::Set_grad(float grad){
    m_grad = grad;
}
void Variable::Set_creator(Function* creator){
    // cout<<"Before: m_creator = "<<m_creator<<" creator = "<<creator<<endl;
    m_creator = creator;
    // cout<<"After: m_creator = "<<m_creator<<" creator = "<<creator<<endl;
}
float Variable::Get_data(){
    return m_data;
}
float Variable::Get_grad(){
    return m_grad;
}
Function* Variable::Get_creator(){
    // cout<<"Get_creator == "<<m_creator<<endl;
    return m_creator;
}
void Variable::Backward(){
    Variable& x = m_creator->Get_inputted();
    x.Set_grad(m_creator->Backward(m_grad));
}