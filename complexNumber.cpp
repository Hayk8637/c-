#include <iostream>
using namespace std;

class Complex {
    private:
        int m_nFalse ;
        int m_nReal ;
    public:
        Complex();
    
        Complex(int a , int b);
        void operator = (Complex const &obj) 
        {
            m_nFalse = obj.m_nFalse;
            m_nReal = obj.m_nReal;
        }
        Complex operator+ (Complex const &obj)
        {
            Complex res;
            res.m_nFalse = m_nFalse + obj.m_nFalse;
            res.m_nReal = m_nReal + obj.m_nReal;
            return res;
        }
        bool operator== (Complex const &obj)
        {
            if (( m_nReal == obj.m_nReal ) && ( m_nFalse == obj.m_nFalse ))
            {
                return true;
            }
            else
                return false;
            
        }
        void operator+=(Complex const &obj)
        {
            m_nFalse += obj.m_nFalse;
            m_nReal += obj.m_nReal;
        }
        Complex operator++ (){
            ++m_nFalse;
            ++m_nReal;
            return *this;
        }

        void printComplex(){
            cout<<m_nReal<<"+i"<<m_nFalse<<endl;
        }
};
Complex::Complex()
            :m_nReal(0)
            ,m_nFalse(0)
        {}
Complex::Complex(int a, int b)
            :m_nReal(a)
            ,m_nFalse(b)
        {}

int main(){
    Complex a (2,4);
    Complex b (3,6);
    Complex c = ++a;
    c.printComplex();
    return 0;
}