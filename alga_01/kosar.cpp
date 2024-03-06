#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct jatekos
{
	string nev;
	int magassag, pont;
};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Hun");
	jatekos csapat[12];

	//létszám bekérése
	int letszam;
	
	int i = 0;
	
	do
	{
		cout << "Adja meg a csapat létszámát:";
		
		cin >> letszam;
		

	} while (letszam<5 || letszam>12);


	//adatok feltöltése
	for ( i = 0; i < letszam; i++)
	{
		cout << i + 1 << ". játékos neve:";
		cin >> csapat[i].nev;
		csapat[i].magassag = rand() % 51 + 170; //(felso -also +1) +also
		csapat[i].pont = rand() % 101;
	}
	csapat[0].pont = 99;
	//tablazatos kiiras
	cout<< setw(20) << "név"
		<< setw(10) << "magasság"
		<< setw(10) << "pont"
		<< endl;

	for ( i = 0; i < letszam; i++)
	{
		cout << setw(20) << csapat[i].nev
			<< setw(10) << csapat[i].magassag
			<< setw(10) << csapat[i].pont
			<< endl;
	}

	//pontátlag -összegzés
	 int ossz=0;
	 for ( i = 0; i < letszam; i++)
	 {
		 ossz += csapat[i].pont;
	 }
	 cout << "Átlag:" << (float)ossz / letszam<<endl;

	 //legtöbb pont -kiválasztás (max)
	 int max = 0; //feltételezzük, hogy az 1. elem a max
	 for ( i = 1; i < letszam; i++)
	 {
		 if (csapat[i].pont > csapat[max].pont) 
			 max = i;
	 }
	 cout << "Legtöbb pontot dobta:" << csapat[max].nev << " " << csapat[max].pont<<" ponttal"<<endl;

	 //50 pont felettiek -megszámlálás
	 int t50=0;
	 for ( i = 0; i < letszam; i++)
	 {
		 if (csapat[i].pont > 50) t50++;
	 }
	 cout << "50 pont felettiek: " << t50 << endl;

	 //50 pont felettiek nevei -kiválogatás
	 string t50nevek[12]; //külön tömb a kiválogatott neveknek
	 int j=0; //külön léptetõ a t50nevek-nek
	 for (i = 0; i < letszam; i++)
	 {
		 if (csapat[i].pont > 50)
		 {
			 t50nevek[j] = csapat[i].nev; //pl t50nevek 1.eleme lehet a csapatnak akár a 3. elem is 
			 cout << t50nevek[j] << ", ";
			 j++;
		 }
	 }
	 cout << endl;

	 //volt-e 99 pontot dobó játékos -eldöntés
	 bool volt = false;
	 i = 0;
	 while (i<letszam && csapat[i].pont!=99)
	 {
		 i++;
	 }
	 if (i < letszam) cout << "Volt 99 pontot dobó játékos" << endl;
	 else cout << "Nem volt 99 pontot dobó játékos" << endl;

	return 0;
}