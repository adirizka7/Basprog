#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	int sku=0, sle=0;
	map <string, int> m;
	map <string, int>::iterator it;
	while(cin >> s)
	{
		if (s!="<TEXT>" && s!="</TEXT>" && s!=":" && s!="." && s!="," && s!="-" && s!="(" && s!=")" && s!=";")
		{
			for(int i=0;i<s.length();i++)
			{
				if (s[i]==':' || s[i]=='.' || s[i]==',' || s[i]=='-' || s[i]=='(' || s[i]==')' || s[i]==';')
				{
					s.erase(s.begin()+i);
					i--;
				}
				s[i]=tolower(s[i]);
			}
			if (s.length()>=3) m[s]++;
		}
	}
	for(it=m.begin(); it!=m.end(); it++)
	{
		if (it->second < 3) sku++;
		if (it->second > 3) sle++;
	}
	cout << sle << " " << sku << endl;
}
