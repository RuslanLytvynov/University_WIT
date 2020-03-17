#include <iostream>
#include <cmath>

using namespace std;

double polygonal()
{
    double x1,x2,y1,y2,sum=0;
    for(int index=0; cin>>x1>>y1>>x2>>y2; index++)
    {
        sum = sum + sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    }
    cout << sum;
}

int main()
{
    polygonal();
    return 0;
}
