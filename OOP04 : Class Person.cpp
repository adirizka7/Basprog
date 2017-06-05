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
   public:
      Person() { nama=""; usia=tinggi=0; berat=0.0; }
      void setPerson(string nm, int u, int t, double b) {
         nama=nm; usia=u; tinggi=t; berat=b;
         imt=IMT(); status=StatusGizi();
      }

      string StatusGizi() {
         double t=IMT();
         if (t<17.0) return "sangat kurus";
         else if (t<18.5) return "kurus";
         else if (t<25.0) return "normal";
         else if (t<28.0) return "gemuk";
         else return "sangat gemuk"; }
      
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
  int usia, tb, n, sum=0;
  int sakur=0, kur=0, norm=0, gem=0, sagem=0;
  string nama;
  double bb;
  list <Person> p;
  list <Person>::iterator it;
  Person data;
  scanf("%d", &n);
  int sumtb=0;
  for(int i=0;i<n;i++)
  {
  	cin >> nama;
    scanf("%d %d %lf", &usia, &tb, &bb);
    sumtb+=tb;
    jadiin;
    p.pb(data);
  }
  double ratatb = (1.0*sumtb)/n;
  for (it=p.begin();it!=p.end();it++) 
  {
		(*it).cetak();
		if ((*it).getTinggi() > ratatb) sum++;
		if ((*it).StatusGizi() == "sangat kurus") sakur++;
		else if ((*it).StatusGizi() == "kurus") kur++;
		else if ((*it).StatusGizi() == "normal") norm++;
		else if ((*it).StatusGizi() == "gemuk") gem++;
		else sagem++;
  }
  	cout << ratatb << endl;
  	cout << sum << endl;
  	printf("%d %d %d %d %d\n", sakur, kur, norm, gem, sagem);
}