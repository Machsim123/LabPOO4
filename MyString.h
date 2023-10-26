#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class MyString
{
    char *buf=NULL;
    int l=0;
    static int numaram;

public:
 //constr fara param – initializeaza atrib. cu 0 sau NULL
    MyString();
 // constr cu param – primeste un sir de caractere
    MyString(char *);
 // constr de copiere
    MyString(const MyString &);
 // operator de atribuire
    MyString& operator=(const MyString &);
 // destructor
    ~MyString();
 // citeste date pentru un obiect MyString
    void citire();
 // afiseaza datele pentru un obiect MyString
    void afisare() const;
 // operator+ concateneaza 2 siruri si salveaza rezultatul intr-un
 // obiect nou de tip MyString pe care il returneaza
    friend const MyString operator+(const MyString &, const MyString &);
 // concateneaza 2 siruri si salveaza rezultatul
 // in primul operand a carui adresa o returneaza
    MyString& operator+=(const MyString &);
 // verifica daca cele 2 siruri sunt identice
    friend bool operator==(const MyString &, const MyString &);
 // verifica daca cele 2 siruri sunt diferite, poate folosi ==
    friend bool operator!=(const MyString &, const MyString &);
 // <, <= >, >= ordonare alfanumerica
    friend bool operator<(const MyString &, const MyString &);
    friend bool operator>(const MyString &, const MyString &);
    friend bool operator>=(const MyString &, const MyString &);
    friend bool operator<=(const MyString &, const MyString &);


 //returneaza caracterul de pe pozitia data ca parametru
    char getChar(int) const;
 // cauta caracterul dat ca parametru in sir si
 // returneaza numarul de aparitii
    int lookFor(char) const;

 // Vezi cursului 4
 // puteti implementa aceste 3 functii (dar nu e obligatoriu)

    friend ostream& operator<<(ostream&, const MyString &);
    friend istream& operator>>(istream&, MyString &);
    char& operator[](int);

    /*friend void functie(MyString &,const MyString &);*/
    friend void sortare(MyString *, const int);
    friend int cautare(const MyString *t, int, const char *);

    static void counter();
};
