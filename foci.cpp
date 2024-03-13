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
	//kiirat�s
	cout << "Eredm�nyek" << endl;
	cout.setf(ios::left); //balra igaz�t�s
	cout << "\t" << setw(12) << "hazai cs."
				 << setw(12) << "vend�g cs."
				 << "eredm�ny" << endl;

	for (i = 0; i < db; i++)
	{
		cout << "\t" << setw(12) << merk[i].h
			<< setw(12) << merk[i].v
			<< setw(2) << merk[i].hGol << " : "
			<< setw(2) << merk[i].vGol << endl;
	}


	//m�rk�z�senk�nti g�l�tlag -�sszegz�s
	int osszg = 0;
	for ( i = 0; i < db; i++)
	{
		osszg += merk[i].hGol + merk[i].vGol;
	}
	cout << setprecision(2) << fixed;
	cout << "G�l�tlag: " <<(float) osszg / db<<endl;

	//hazai gy�zelmek sz�ma -megsz�ml�l�s
	int hgy = 0;
	for ( i = 0; i < db; i++)
	{
		if (merk[i].hGol > merk[i].vGol) hgy++;
	}
	cout << "Hazai gy�zelmek sz�ma: " << hgy << endl;
	//max kiv�laszt�s
	int max = 0;
	for ( i = 1; i < db; i++)
	{
		if ((merk[i].hGol+merk[i].vGol) > (merk[max].hGol+merk[max].vGol)) max = i;
	}

	cout << "A legt�bb g�l a(z) " << merk[max].h << " - " << merk[max].v << " m�rk�z�sen volt" << endl;

	//volt-e d�ntetlen -eld�nt�s
	i = 0;
	while (i < db && merk[i].hGol != merk[i].vGol)
	{
		i++;
	}
	if (i < db) cout << "Volt d�ntetlen" << endl;
	else cout << "Nem volt d�ntetlen" << endl;

	//h�ny g�lt l�tt a KTE?
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

