#include <iostream>
#include <string.h>
#include <assert.h>

#include "MyString.h"

using namespace std;

int main()
{
    MyString vec[4];
    int nr=4;
    MyString x;
    vec[0].citire();
    vec[1].citire();
    vec[2].citire();
    vec[3].citire();
    vec[0].afisare();
    vec[1].afisare();
    vec[2].afisare();
    vec[3].afisare();
    x+=vec[0]+vec[1]+vec[2]+vec[3];
    x.afisare();
    sortare(vec,nr);
    vec[0].afisare();
    vec[1].afisare();
    vec[2].afisare();
    vec[3].afisare();
    cout<<cautare(vec, nr, "cuv")<<endl;






    /*cout<<y;
    cout<<z;
    x=y;
    cout<<x;
    cout<<y;
    cin>>l;
    cout<<l;
    x=x+l;
    cout<<x;
    y+=l;
    cout<<y;
    cout<<y[2];
    cout<<(x==y)<<endl;
    cout<<(l==y)<<endl;
    cout<<(x!=y)<<endl;
    cout<<(l!=y)<<endl;
    cout<<(x<y)<<endl;
    cout<<(l<y)<<endl;
    cout<<(x>y)<<endl;
    cout<<(l>y)<<endl;
    cout<<(x>=y)<<endl;
    cout<<(l>=y)<<endl;
    cout<<(x<=y)<<endl;
    cout<<(l<=y)<<endl;
    cout<<x.getChar(5)<<endl;
    cout<<y.getChar(4)<<endl;
    cout<<l.getChar(3)<<endl;
    cout<<x.lookFor('l')<<endl;*/
    vec[1].counter();
    return 0;
}
