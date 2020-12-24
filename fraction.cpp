#include<iostream>

using namespace std;

class Fraction
{
private:
    int num;
    int den;
public:
    Fraction(int=0, int=1);
    Fraction(const Fraction&);
    ~Fraction(){}

    int getNum(){return num;}
    int getDen(){return den;}
    void setNum(int num){this->num = num;}
    void setDen(int den){this->den = den;}

    Fraction operator+(Fraction f);
    Fraction operator-(Fraction f);
    Fraction operator*(Fraction f);
    Fraction operator/(Fraction f);
    Fraction& operator=(Fraction f);
    bool operator==(Fraction f);
    bool operator!=(Fraction f);
    bool operator<(Fraction f);
    bool operator<=(Fraction f);
    bool operator>(Fraction f);
    bool operator>=(Fraction f);

    Fraction& operator++();  //prefix
    Fraction operator++(int); //postfix
    Fraction& operator--();  //prefix
    Fraction operator--(int); //postfix

 //   friend Fraction operator+(Fraction f1,Fraction f2);

    friend istream& operator>>(istream &in, Fraction &f);
    friend ostream& operator<<(ostream &out, const Fraction &f);

    operator float();

    void show()
    {
        cout<<num<<"/"<<den<<endl;
    }
};

Fraction::operator float()
{
    return (float)num/den;
}

istream& operator>>(istream &in, Fraction &f)
{
    in>>f.num>>f.den;
    return in;
}

ostream& operator<<(ostream &out, const Fraction &f)
{
    out<<f.num<<"/"<<f.den<<endl;
    return out;
}

Fraction& Fraction::operator++()  //prefix
{
    this->num = this->num + this->den;
    return *this;
}

Fraction Fraction::operator++(int a) //postfix
{
    Fraction tmp(*this);
    this->num = this->num + this->den;
    return tmp;
}

Fraction& Fraction::operator--()  //prefix
{
    this->num = this->num - this->den;
    return *this;
}

Fraction Fraction::operator--(int a) //postfix
{
    Fraction tmp(*this);
    this->num = this->num - this->den;
    return tmp;
}

/*
Fraction operator+(Fraction f1,Fraction f2)
{
    int n = f1.getNum()*f2.getDen() + f1.getDen()*f2.getNum();
    int d = f1.getDen()*f2.getDen();
    Fraction t(n, d);
    return t;
}
*/

bool Fraction::operator==(Fraction f)
{
    return (this->num*f.den == this->den*f.num);
}

bool Fraction::operator!=(Fraction f)
{
    return (this->num*f.den != this->den*f.num);
}

bool Fraction::operator<(Fraction f)
{
    return (this->num*f.den < this->den*f.num);
}

bool Fraction::operator<=(Fraction f)
{
    return (this->num*f.den <= this->den*f.num);
}

bool Fraction::operator>(Fraction f)
{
    return (this->num*f.den > this->den*f.num);
}

bool Fraction::operator>=(Fraction f)
{
    return (this->num*f.den >= this->den*f.num);
}

Fraction::Fraction(int n, int d)
{
    num = n;
    den = d;
}
Fraction::Fraction(const Fraction&other)
{
    num = other.num;
    den = other.den;
}

Fraction Fraction::operator+(Fraction f)
{
    Fraction t;
    t.num = this->num*f.den + this->den*f.num;
    t.den = this->den*f.den;
    return t;
}

Fraction Fraction::operator-(Fraction f)
{
    Fraction t;
    t.num = this->num*f.den - this->den*f.num;
    t.den = this->den*f.den;
    return t;
}


Fraction Fraction::operator*(Fraction f)
{
    Fraction t;
    t.num = this->num*f.num;
    t.den = this->den*f.den;
    return t;
}

Fraction Fraction::operator/(Fraction f)
{
    Fraction t;
    t.num = this->num*f.den;
    t.den = this->den*f.num;
    return t;
}

Fraction& Fraction::operator=(Fraction f)
{
    this->num = f.num;
    this->den = f.den;

    return *this;
}

/*
Fraction operator+(Fraction f1,Fraction f2)
{
    Fraction t;
    t.num = f1.num*f2.den + f1.den*f2.num;
    t.den = f1.den*f2.den;
    return t;
}
*/


/*
Fraction Fraction::add(Fraction f1,Fraction f2)
{
    Fraction t;
    t.num = f1.num*f2.den + f1.den*f2.num;
    t.den = f1.den*f2.den;
    return t;
}
*/


int main()
{
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    f1.show();
    f2.show();

   // Fraction f3 = f1.add(f1, f2);


    Fraction f3 = f1 + f2;     // f1 + f2   f1.operator+(f2)
    cout<<f3;
    f3 = f1 - f2;     // f1 - f2   f1.operator-(f2)
    cout<<f3;
    f3 = f1 * f2;     // f1 * f2   f1.operator*(f2)
    cout<<f3;
    f3 = f1 / f2;     // f1 / f2   f1.operator/(f2)
    cout<<f3;
    Fraction f4 = f2;
    cout<<f3;
    //f1 = 1/2
    ++f1; //
    cout<<"prefix increment: (3/2)"<<f1;
    f3 = f1++; //
    cout<<"postfix increment: f1=(5/2)"<<f1;
    cout<<"postfix increment: f3=(3/2)"<<f3;

    return 0;
}
