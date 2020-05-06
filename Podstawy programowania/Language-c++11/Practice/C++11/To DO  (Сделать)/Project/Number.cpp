#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        int i, N, temp, temp1=1, del, mas_pr[3450], i_prost=0;
        bool *bArray, fl;
        cout<<"Enter the number N(no more 32767): "<<endl;
        cin>>N;
    N++;
    bArray = new bool [N];
    memset(bArray, 1, N);
    for(i = 2; i < N; ++i)
        if(bArray[i])
        for(int j = i*i; j < N; j += i)
             bArray[j] = false;
    for(i = 2; i < N; ++i)
        if(bArray[i])
                {
             cout<<"Dellitsya li zdumnnoe chislo na "<<i<< ".Esli delitsya naghmite 1, Esli ne delitsya naghmite 0"<<endl;
                         cin>>del;
                         if(del==1)
                         {
                                 mas_pr[i_prost]=i;
                                 i_prost++;
                         }
                }
        for(i=0; i<i_prost; i++)
           temp1*=mas_pr[i];
        for(i=0; i<i_prost; i++)
        {
            fl=false;
            temp=mas_pr[i];
            while(!fl)
            {
                temp=pow(temp,2);
                cout<<"Dellitsya li zdumnnoe chislo na 1 "<<temp<< "Esli delitsya naghmite 1, Esli ne delitsya naghmite 0"<<endl;
                cin>>del;
                         if(del==1)
                                temp1*=pow(temp, 0.5);
                         else
                                 fl=true;
            }
        }
        cout<<"Zadumannoe chislo: "<<temp1<<endl;
        system("pause");
    return 0;
}
