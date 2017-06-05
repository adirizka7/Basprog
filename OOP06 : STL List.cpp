#include <iostream>
#include <cstdio>
#include <list>
#include <iomanip>
 
#define jadiin data.setPerson(nama, usia, tb, bb)
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
 
using namespace std;
 
class Person {
   private:
      string nama;
      int usia;
      int tinggi;
      double berat;
      double imt;
      string status;
      double IMT() { double t=(double)tinggi/100.0; return (berat/(t*t)); }
      string StatusGizi() {
         double t=IMT();
         if (t<17.0) return "sangat kurus";
         else if (t<18.5) return "kurus";
         else if (t<25.0) return "normal";
         else if (t<28.0) return "gemuk";
         else return "sangat gemuk"; }
   public:
      Person() { nama=""; usia=tinggi=0; berat=0.0; }
      void setPerson(string nm, int u, int t, double b) {
         nama=nm; usia=u; tinggi=t; berat=b;
         imt=IMT(); status=StatusGizi();
      }
      string getNama() { return nama; }
      int getUsia() { return usia; }
      int getTinggi() { return tinggi; }
      double getBerat() { return berat; }
      double getIMT() { return imt; }
      string getStatusGizi() { return status; }
      void cetak() {
         cout << nama << " " << usia << " " << tinggi << " ";
         cout << fixed << setprecision(2) << berat << " " << imt << " " << status << endl;
      }
};
 
int main()
{
  int usia, tb, n, sisip;
  string nama;
  double bb;
  list <Person> p;
  list <Person>::iterator it;
  Person data;
  scanf("%d", &n);
  while(n--)
  {
    cin >> nama;
    scanf("%d %d %lf", &usia, &tb, &bb);
    jadiin;
    p.pb(data);
  }
 
  while(1)
  {
    scanf("%d", &n);
    if (n==-9) break;
    else if (n==1)
    {
      cin >> nama; scanf("%d %d %lf", &usia, &tb, &bb);
      jadiin;
      p.pf(data);
    }
    else if (n==2)
    {
      cin >> nama; scanf("%d %d %lf", &usia, &tb, &bb);
      jadiin;
      p.pb(data);
    }
    else if (n==3) p.popf();
    else if (n==4) p.popb();
    else if (n==5)
    {
      scanf("%d", &sisip); cin >> nama;
      scanf("%d %d %lf", &usia, &tb, &bb); jadiin;
      it = p.begin();
      for (int i=0;i<sisip;i++) it++;
      p.insert(it, data);
    }
  }
 
  for (it=p.begin();it!=p.end();it++) (*it).cetak();
}