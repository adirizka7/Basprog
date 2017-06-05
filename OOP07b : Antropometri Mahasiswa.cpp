#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
   
class Person {
   string nama, nim;
   int usia, tinggi;
   double berat;
       
   public:
      Person() {nama=""; usia=tinggi=0; berat=0.0;}
      void setPerson(string ni, string na, int u, int t, double b) 
      {
         nim = ni;
         nama=na; usia=u; tinggi=t; berat=b; 
      } 
      double getIMT() { 
         double t=(double)tinggi/100.0;
         return berat/(t*t); }
      string getNim() {return nim;}
      string getNama() {return nama;}
      int getUsia() {return usia;}
      double getBerat() {return berat;}
      int getTinggi() {return tinggi;}
};
   
   
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, Person > m;
    string nim, nama;
    int n, usia, tinggi, t;
    double berat;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> nim >> nama >> usia >> tinggi >> berat;
        m[nim].setPerson(nim, nama, usia, tinggi, berat);
    }
       
    cin >> t;
    while(t--)
    {
        cin >> nim;
        if (m.find(nim) == m.end()) cout << "Data " << nim << " tidak ada" << endl;
        else
        cout << fixed << m[nim].getNama() << " " << m[nim].getUsia() << " " << m[nim].getTinggi() << " " << m[nim].getBerat() << " " << setprecision(2) << m[nim].getIMT() << endl; 
    }
}