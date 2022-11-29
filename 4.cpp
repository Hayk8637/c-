#include <iostream>
#include <vector>
using namespace std;

vector <int> check (vector <int> a)
{
    vector <int> res;
    for(int i =  1 ; i<a.size()-1 ; i++)
    {
        if(a[i-1]>a[i] && a[i] < a[i+1])
        {
            res.push_back(a[i]);
        }
    }
    return res;
}


int main() {

    vector <int> s = {4,5,2,7,9};
    vector <int> res = check (s);
    for(int i = 0 ; i < res.size( ) ; i++) {
        cout<< res[i]<<" "; 
    }
    return 0;
}