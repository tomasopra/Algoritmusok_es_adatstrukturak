#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct fordulo
{
	int hGol, vGol;
	string h, v;
};

int main()
{
	setlocale(LC_ALL, "Hun");
	fordulo merk[8];
	ifstream olvaso ("merkozes.txt");
	int i = 0;

	while (!(olvaso.eof()))
	{
		olvaso >> merk[i].hGol;
		olvaso >> merk[i].vGol;
		olvaso >> merk[i].h;
		olvaso >> merk[i].v;
		i++;
	}
	olvaso.close();
	int db = i;
	//kiiratás
	cout << "Eredmények" << endl;
	cout.setf(ios::left); //balra igazítás
	cout << "\t" << setw(12) << "hazai cs."
				 << setw(12) << "vendég cs."
				 << "eredmény" << endl;

	for (i = 0; i < db; i++)
	{
		cout << "\t" << setw(12) << merk[i].h
			<< setw(12) << merk[i].v
			<< setw(2) << merk[i].hGol << " : "
			<< setw(2) << merk[i].vGol << endl;
	}


	//mérkõzésenkénti gólátlag -összegzés
	int osszg = 0;
	for ( i = 0; i < db; i++)
	{
		osszg += merk[i].hGol + merk[i].vGol;
	}
	cout << setprecision(2) << fixed;
	cout << "Gólátlag: " <<(float) osszg / db<<endl;

	//hazai gyõzelmek száma -megszámlálás
	int hgy = 0;
	for ( i = 0; i < db; i++)
	{
		if (merk[i].hGol > merk[i].vGol) hgy++;
	}
	cout << "Hazai gyõzelmek száma: " << hgy << endl;
	//max kiválasztás
	int max = 0;
	for ( i = 1; i < db; i++)
	{
		if ((merk[i].hGol+merk[i].vGol) > (merk[max].hGol+merk[max].vGol)) max = i;
	}

	cout << "A legtöbb gól a(z) " << merk[max].h << " - " << merk[max].v << " mérkõzésen volt" << endl;

	//volt-e döntetlen -eldöntés
	i = 0;
	while (i < db && merk[i].hGol != merk[i].vGol)
	{
		i++;
	}
	if (i < db) cout << "Volt döntetlen" << endl;
	else cout << "Nem volt döntetlen" << endl;

	//hány gólt lõtt a KTE?
	int kte = 0;
	/*for (i = 0; i < db; i++)
	{
		if(merk[i].h=="KTE" || merk[i].v=="KTE")
	}*/
	i = 0;
	while (merk[i].h != "KTE" && merk[i].v)
	{
		if (fordulo[i].h == "KTE") cout << merk[i].h << endl;
		else cout << merk[i].v << endl;
	}
	return 0;
}

