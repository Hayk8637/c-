#include <iostream>
#include <cmath>
using namespace std;
class geometricFigure
{   
public:
    void i_am (){
        cout<<"I am geometric figure."<<endl;
    }
};
class ellips : public geometricFigure
{
private:
    int m_nR;
    int m_nF1;
    int m_nF2;
public:
    ellips()
    :m_nR(1)
    ,m_nF1(1)
    ,m_nF2(1)
    {}
    ellips(int r , int f1 , int f2)
    : m_nR(r)
    , m_nF1(f1)
    , m_nF2(f2)
    {}
    float surface(){
        return M_PI*m_nR*m_nR;
    }
    float perimetr(){
        return 2*M_PI*m_nR;
    }
};

class circle : public ellips
{
    private:
        // ellips֊ում արդեն m_nR֊ը հայտարարված է, պետք չէ circle֊ում նորից հայտարարել։
        // Նույնը վերաբերվում է, մյուս բոլոր ժառանգումներին
        int m_nR;
    public:
        circle(int r)
        :ellips(r,1,1)
        ,m_nR(r)
        {}
};
class triangle  : public geometricFigure
{
    private:
        int m_nA , m_nB , m_nC;
    public:
        triangle (int a , int b , int c)
            :m_nA(a)
            ,m_nB(b)
            ,m_nC(c)
            {}
        void i_have (){
            cout<<"I have tree peaks."<<endl;
        }
        float surface (){
            int  p = perimetr()/2;
            return sqrt(p*(p-m_nA)*(p-m_nB)*(p-m_nC));
        }
        int perimetr  (){
            return m_nA + m_nB + m_nC;
        }
};
class rectangle : public geometricFigure
{
    private:
        int m_nA , m_nB;
    public: 
        rectangle ()
            :m_nA(1)
            ,m_nB(1)
        {}
        rectangle(int a , int b)
            :m_nA(a)
            ,m_nB(b)
        {}
        void i_have(){
            cout<<"I have four peaks"<<endl;
        }
        int surface(){
            return m_nA*m_nB;
        }
        int perimetr(){
            return 2*(m_nA+m_nB);
        }
};
class square: public rectangle
{
    private:
        int m_nA;
    public:
        square(int a)
            :rectangle(a , a)
            ,m_nA(a)
        {}
};
 
int main() {
    circle c(4);
    cout<< c.surface();
    return 0;
}
