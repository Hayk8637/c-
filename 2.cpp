#include <iostream>
#include <vector>
using namespace std;


vector <string> vec (vector <string> v ) {
    vector <string> res;
    for (int i = 0; i < v.size(); i++)
    {
        for(int j=0 ; j< v[i].length() ; j++)
        {
            if (int(v[i][j])<=57 && int(v[i][j])>=48 )
            {
                res.push_back(v[i]);
                break;
            }
        }
    }
    return res;
}
int main(){
    vector <string> v = {"Hello" , "1student", "bestfrends4ever", "bye"};
    vector <string> res = vec(v);
    for(int i = 0 ; i < v.size( ) ; i++) {
        cout<< v[i]<<" "; 
    }
    return 0;
}