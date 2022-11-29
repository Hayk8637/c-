#include <iostream>
using namespace std;

template <typename T> class vector {
private:
    T* arr;
    int capacity;
    int current;
 
public:
    vector()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }
    vector(vector <T> &p)
    :arr(p.arr)
    ,capacity(p.capacity)
    ,current(p.current)
    {   
    }
    vector(T a[] , int n)
    : vector()
    {
        for (int i = 0; i < n; i++)
        {
            push_back(a[i]);
        } 
    }
 
    void push_back(T data)
    {
        if (current == capacity) {
            T* temp = new T[2 * capacity];
             for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
             delete[] arr;
            capacity *= 2;
            arr = temp;
        }
         arr[current] = data;
        current++;
    }
 
    void push(T data, int index)
    {
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
 
    T get(int index)
    {
         if (index < current)
            return arr[index];
    }
 
    void pop_back() 
    {
         current--; 
    }
 
    int size() 
    { 
        return current; 
    }
 
    int getcapacity() 
    {
        return capacity;
    }
 
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool empty()
    {
        return (size()==0);
    }
    void clear()
    {
        current = 0;
    }

    void operator= (const T &g)
    {
        this->clear();
        for (int i = 0; i < g.size(); i++)
        {
            this->push_back(g[i]);
        }
    }

    bool operator == (const vector &s) 
    {
        int z = this->size();     
        if (z != s.current){
            return false;
        }

        for (int i = 0;  i < z; i++){
            T p = this->arr[i];
            if (p != s.arr[i]){ 
                return false;
            }
        };
        return true;
    }


};  

int main(){
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout<<a.size()<<endl;
    cout<<a.empty()<<endl;
    cout<<a.getcapacity()<<endl;
    int arr [] = {1,2,3,4,5};
    a.print();
    a.pop_back();
    a.print();
    vector <int> b(arr , 5);
    if( b==a){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    b=a;
    if(b==a){
        cout<<"yes"<<endl;
    }
    vector <int> g(b);
    g.print();
    return 0;
}




