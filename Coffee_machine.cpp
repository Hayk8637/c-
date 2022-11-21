#include <iostream>
using namespace std;
struct Coffee
{
    string coffee;
    int money;
};

struct Small_return
{
    string coffee;
    int entered_money;
    int small_return;
};
class Coffee_machine
{
private:
    int *m_nProductPrice;
    string *m_sProductList;
    int m_nListLen = (*(&m_nProductPrice + 1) - m_nProductPrice) / 4;

public:
    Coffee_machine(int nProductPrice[], string sProductList[])
        : m_nProductPrice(nProductPrice), m_sProductList(sProductList)
    {
    }
    Small_return SmallReturn(Coffee prod, int price)
    {
        Small_return smallReturn;
        smallReturn.coffee = prod.coffee;
        smallReturn.entered_money = prod.money;
        smallReturn.small_return = prod.money-price;
        cout<<smallReturn.coffee<<endl;
        cout<<smallReturn.entered_money<<endl;
        cout<<smallReturn.small_return<<endl;
        return smallReturn;
    }
    void PrintPriceList()
    {
        cout << m_nListLen << endl;
        string *list = m_sProductList;
        int *price = m_nProductPrice;
        while (m_nListLen)
        {
            cout << *m_sProductList << " : " << *m_nProductPrice << endl;
            *m_nProductPrice++;
            *m_sProductList++;
            m_nListLen--;
        }
        m_nProductPrice = price;
        m_sProductList = list;
        m_nListLen = (*(&m_nProductPrice + 1) - m_nProductPrice) / 4;
    }
    bool Order(Coffee product)
    {
        string *prod = m_sProductList;
        for (int i = 0; i < m_nListLen; i++)
        {
            if (product.coffee == *m_sProductList)
            {
                if (product.money >= *m_nProductPrice + i)
                {
                    SmallReturn(product, *m_nProductPrice + i);
                    return true;
                }
                cout << "You haven't enaugh mony." << endl;
                return false;
            }
            *m_sProductList++;
        }
        cout << "Your selected drink we haven't." << endl;
        return false;
    }
};

int main()
{
    Coffee product;
    int a[] = {10, 20, 30, 40};
    string b[] = {"a", "b", "c", "d"};
    Coffee_machine c(a, b);

    cin>>product.coffee >> product.money;


    c.Order(product);
    //c.PrintPriceList();
    

    return 0;
}