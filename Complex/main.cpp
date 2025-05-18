#include"Complex.hpp"
using namespace  std;

int main(){

    Complex a;
    cin>>a;
    cout<<a;

    Complex b;
    cin>>b;
    cout<<b;

    Complex c = a.add(b);  //rvalue
    cout << c;

    c.setReal(2);
    cout << c;


    return 0;
}