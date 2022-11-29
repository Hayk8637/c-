#include <iostream>
#include <vector>
using namespace std;

template <typename T> 
bool check (vector <T> a , vector <T> b)
{
    for(int i = 0 ; i < b.size() ; i++)
    {
        int k = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (b[i]  ==  a[j])
            {
                k++;
            }
        }
        if (k==0){
            return false;
        }
    }
    return true;
}

int main() {
    vector <int> a = {1,2,3,4} ;
    vector <int> b = {1,2,3,6,4};
    cout<<check(a,b)<<endl;;   
    return 0;
}