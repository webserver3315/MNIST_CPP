#include <iostream>
using namespace std;
class base {
     public:
        virtual void vfunc() {
            cout << "This is base's vfunc().\n";
         }
         virtual void foo() = 0;
};
 class derived1 : public base {
      public:
            void vfunc() {
                 cout << "This is derived1's vfunc().\n";
            }
            void foo(){
                cout<<"foo"<<endl;
            }
};
int main()
{
     base *p;
     derived1 d1;
     // point to base
     // point to derived1
     p = &d1;
     p->vfunc(); // access derived1's vfunc()
     return 0;
}
