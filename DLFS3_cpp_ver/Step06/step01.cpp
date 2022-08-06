#include <bits/stdc++.h>
using namespace std;

class Variable{
    private:
        int m_data;
    public:
        Variable(int data){
            m_data = data;
        }
        int Get(){
            return m_data;
        }
};

int main(){
    Variable var1(1);
    printf("variable is %d\n", var1.Get());
    return 0;
}