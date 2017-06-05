#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    std::ios::sync_with_stdio(false);
    vector <int> v;
    int i, lama;
    int a, cnt=0;
    double avg1, avg2;
    while(1)
    {
        cin >> a;
        if (a==-9) break;
        v.push_back(a);
    }
    int sum=0;
    lama = v.size();
    for (i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    avg1=1.0*sum/v.size(); //printf("%.2lf", avg1);
    while(1)
    {
        cin >> a;
        if (a==-9) break;
        else
        {
            v.erase(v.begin()+(a-1-cnt));
            cnt++;
        }
    }
    //cout << v.size() << endl;
    sum=0;
    for (i=0;i<v.size();i++)
    {
        sum+=v[i];
    }
    avg2=1.0*sum/v.size();
    printf("%d %d\n", lama, v.size());
    if (v.size()==0) printf("%.2lf -9.99\n", avg1);
    else printf("%.2lf %.2lf\n", avg1, avg2);
}