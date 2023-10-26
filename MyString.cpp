#include <iostream>
#include <string.h>
#include <assert.h>

#include "MyString.h"

using namespace std;

/*void functie(MyString &x ,const MyString &y)
{
    if(y.buf==NULL)
    {
        x.l=0;
        x.buf=NULL;
    }
    else
    {
        x.l=strlen(y.buf);
        x.buf=new char[x.l+1];
        strcpy(x.buf,y.buf);
    }
}
*/

int MyString::numaram=0;

MyString::MyString()
{
    numaram++;
    cout<<numaram<<" ";

}

MyString::MyString(char *cuvant)
{
    if(cuvant==NULL)
    {
        l=0;
        buf=NULL;
    }
    else
    {
        l=strlen(cuvant);
        buf=new char[l+1];
        strcpy(buf,cuvant);
    }
    numaram++;
    cout<<numaram<<" ";
}

MyString::MyString(const MyString &x)
{
    ///functie(*this,x);
    if(x.buf==NULL)
    {
        l=0;
        buf=NULL;
    }
    else
    {
        l=strlen(x.buf);
        buf=new char[l+1];
        strcpy(buf,x.buf);
    }
    numaram++;
    cout<<numaram<<" ";
}

MyString& MyString::operator=(const MyString &x)
{
    ///functie(*this,x);
    if(x.buf==NULL)
    {
        l=0;
        buf=NULL;
    }
    else
    {
        l=strlen(x.buf);
        buf=new char[l+1];
        strcpy(buf,x.buf);
    }
}

MyString::~MyString()
{
    if(buf!=NULL)
    {
        l=0;
        delete [] buf;
        buf=NULL;
    }
    /*numaram--;
    cout<<numaram<<" ";*/
}

void MyString::citire()
{
    char aux[200]="";
    if(buf!=NULL)
    {
        l=0;
        delete [] buf;
        buf=NULL;
    }
    cout<<"Cuvant: ";
    cin>>aux;
    l=strlen(aux);
    buf=new char(l+1);
    strcpy(buf,aux);
}

void MyString::afisare() const
{
    cout<<buf<<" cu "<<l<<" litere\n";
}

/*friend*/ const MyString operator+(const MyString &x, const MyString &y)
{
    char aux[200]="";
    MyString concat;
    if(x.buf==NULL)
    {
        concat.l=y.l;
        concat.buf=new char[concat.l+1];
        strcpy(concat.buf,y.buf);
    }
    else if (y.buf==NULL)
    {
        concat.l=x.l;
        concat.buf=new char[concat.l+1];
        strcpy(concat.buf,x.buf);
    }
    else
    {
        concat.l=x.l + y.l;
        strcpy(aux,x.buf);
        strcat(aux,y.buf);
        concat.buf=new char[concat.l+1];
        strcpy(concat.buf,aux);
    }
    return concat;
}

MyString& MyString::operator+=(const MyString &x)
{
    *this=*this+x;
    return *this;
}

/*friend*/ bool operator==(const MyString &x, const MyString &y)
{
    if(strcmp(x.buf,y.buf)>0 || strcmp(x.buf,y.buf)<0)
        return 0;
    else
        return 1;
}

/*friend*/ bool operator!=(const MyString &x, const MyString &y)
{
    return (!(x==y));
}

/*friend*/ bool operator<(const MyString &x, const MyString &y)
{
    if(strcmp(x.buf,y.buf)<0)
        return 1;
    else
        return 0;
}

/*friend*/ bool operator>(const MyString &x, const MyString &y)
{
    if(strcmp(x.buf,y.buf)>0)
        return 1;
    else
        return 0;
}

/*friend*/ bool operator>=(const MyString &x, const MyString &y)
{
    if(strcmp(x.buf,y.buf)>=0)
        return 1;
    else
        return 0;
}

/*friend*/ bool operator<=(const MyString &x, const MyString &y)
{
    if(strcmp(x.buf,y.buf)<=0)
        return 1;
    else
        return 0;
}

char MyString::getChar(int x) const
{
    if(l<x)
        return NULL;
    else
        return buf[x-1];
}

int MyString::lookFor(char litera) const
{
    int nr=0;
    if(buf==NULL)
        return nr;
    for(int i=0; i<l; i++)
        if(buf[i]==litera)
            nr++;
    return nr;
}

/*friend*/ ostream& operator<<(ostream& dev, const MyString &x)
{
    dev<<x.buf<<" cu "<<x.l<<" litere\n";

}

/*friend*/ istream& operator>>(istream& dev, MyString &x)
{
    char aux[200]="";
    if(x.buf!=NULL)
    {
        x.l=0;
        delete [] x.buf;
        x.buf=NULL;
    }
    cout<<"Cuvant: ";
    cin>>aux;
    x.l=strlen(aux);
    x.buf=new char(x.l+1);
    strcpy(x.buf,aux);
}

char& MyString::operator[](int poz)
{
    assert(poz >= 0 && poz < this->l);
    return this -> buf[poz];
}

/*friend*/ void sortare(MyString *vect, int nr)
{
    MyString aux;
    for(int i=0; i<nr-1; i++)
        for(int j=i+1; j<nr; j++)
            if(vect[i]>vect[j])
            {
                aux=vect[i];
                vect[i]=vect[j];
                vect[j]=aux;
            }
}

/*friend*/ int cautare(const MyString *vect, int nr, const char *cuvant)
{
    int nr_ap=0;
    for(int i=0; i<nr; i++)
        if(strcmp(cuvant,vect[i].buf)==0)
            nr_ap++;
    return nr_ap;
}

/*static*/ void MyString::counter()
{
    cout<<"Nr de MyString-uri:"<<numaram<<endl;
}
