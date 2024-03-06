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

	//l�tsz�m bek�r�se
	int letszam;
	
	int i = 0;
	
	do
	{
		cout << "Adja meg a csapat l�tsz�m�t:";
		
		cin >> letszam;
		

	} while (letszam<5 || letszam>12);


	//adatok felt�lt�se
	for ( i = 0; i < letszam; i++)
	{
		cout << i + 1 << ". j�t�kos neve:";
		cin >> csapat[i].nev;
		csapat[i].magassag = rand() % 51 + 170; //(felso -also +1) +also
		csapat[i].pont = rand() % 101;
	}
	csapat[0].pont = 99;
	//tablazatos kiiras
	cout<< setw(20) << "n�v"
		<< setw(10) << "magass�g"
		<< setw(10) << "pont"
		<< endl;

	for ( i = 0; i < letszam; i++)
	{
		cout << setw(20) << csapat[i].nev
			<< setw(10) << csapat[i].magassag
			<< setw(10) << csapat[i].pont
			<< endl;
	}

	//pont�tlag -�sszegz�s
	 int ossz=0;
	 for ( i = 0; i < letszam; i++)
	 {
		 ossz += csapat[i].pont;
	 }
	 cout << "�tlag:" << (float)ossz / letszam<<endl;

	 //legt�bb pont -kiv�laszt�s (max)
	 int max = 0; //felt�telezz�k, hogy az 1. elem a max
	 for ( i = 1; i < letszam; i++)
	 {
		 if (csapat[i].pont > csapat[max].pont) 
			 max = i;
	 }
	 cout << "Legt�bb pontot dobta:" << csapat[max].nev << " " << csapat[max].pont<<" ponttal"<<endl;

	 //50 pont felettiek -megsz�ml�l�s
	 int t50=0;
	 for ( i = 0; i < letszam; i++)
	 {
		 if (csapat[i].pont > 50) t50++;
	 }
	 cout << "50 pont felettiek: " << t50 << endl;

	 //50 pont felettiek nevei -kiv�logat�s
	 string t50nevek[12]; //k�l�n t�mb a kiv�logatott neveknek
	 int j=0; //k�l�n l�ptet� a t50nevek-nek
	 for (i = 0; i < letszam; i++)
	 {
		 if (csapat[i].pont > 50)
		 {
			 t50nevek[j] = csapat[i].nev; //pl t50nevek 1.eleme lehet a csapatnak ak�r a 3. elem is 
			 cout << t50nevek[j] << ", ";
			 j++;
		 }
	 }
	 cout << endl;

	 //volt-e 99 pontot dob� j�t�kos -eld�nt�s
	 bool volt = false;
	 i = 0;
	 while (i<letszam && csapat[i].pont!=99)
	 {
		 i++;
	 }
	 if (i < letszam) cout << "Volt 99 pontot dob� j�t�kos" << endl;
	 else cout << "Nem volt 99 pontot dob� j�t�kos" << endl;

	return 0;
}