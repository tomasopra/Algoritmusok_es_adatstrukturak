#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Hun");
	int t[] = {7,34,56,4,57,45,67,6,43,32,33,99,33,100,11};
	//kiiratás
	for (int i = 0; i <15; i++)
	{
		cout << t[i] << " ";
	}
	cout << endl;

	//átlag
	double osszeg = 0;
	int db = sizeof(t) / sizeof(t[0]);
	for (int i = 0; i < db; i++)
	{
		osszeg += t[i];
	}
	
	cout << "Átlag: " << double(osszeg / db) << endl;

	//volt-e 100 pont?
	bool szaz_pontos=false;
	for (size_t i = 0; i < db; i++)
	{
		if (t[i] == 100);
		szaz_pontos = true;
	}
	if (szaz_pontos)
		cout << "Volt 100 pontos vizsga" << endl;
	else
		cout << "Nem volt 100 pontos vizsga" << endl;
	return 0;
}