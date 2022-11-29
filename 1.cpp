#include <iostream>
using namespace std;


template <typename T>
class B
{
    private:
        T* arr;
        int n;
    public:
        B(){
            n=10;
            T a[10]={0,1,2,3,4,5,6,7,8,9};
            arr= a;
        }
        B(unsigned int m)
        :n(m)
        {
            T a[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = i;
            }
            arr = &a[0];
        }

        T getindex(int p) {
            return *arr + p;
        }
        void operator= (const B &b)
        {
            this->n = b.n;
            this->arr = b.arr;
        }


    bool operator== (const B &s) 
    {
        int z  = this->size();
        int *w = s.arr;
        if(z != s.n)
        {
            return false;
        }        
        for(int i = 0 ; i< z ; i++ ) {
           if( this->getindex(i) != *w+i){
            return false;
           }
        }
        return true;
    }

    int size(){return n;}

};

int main() {
    B <int> f;
    B <int> c(20);
    f=c;
    cout<<f.getindex(1)<<endl;

    cout<<f.size()<<endl;

    if(f==c){
        cout<<"yes"<<endl;
    }

    return 0;
}