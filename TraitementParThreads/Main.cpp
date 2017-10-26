#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

/*
 * Variables
 */

int const tailleX = 2;
int const tailleY = 10000000;

int tableau[tailleX][tailleY];

chrono::time_point<chrono::system_clock> debutTraitementA, finTraitementA;
chrono::time_point<chrono::system_clock> debutTraitementB, finTraitementB;

bool stop;

/*
 * Fonctions
 */

void traitementA()
{
	debutTraitementA = chrono::system_clock::now();

	for(int i = 0; i < (tailleY / 2) - 1; i++)
	{ 
		int _nbr = tableau[0][i] * tableau[1][i];
	}

	finTraitementA = chrono::system_clock::now();

	// Je fais dormir les threads momentanément pour éviter  
	// que les messages ne s'affichent en même temps, sur la même ligne.

	this_thread::sleep_for(chrono::milliseconds(250));

	cout << "Fin du traitement du thread A en " << chrono::duration_cast<chrono::milliseconds>(finTraitementA - debutTraitementA).count() << " ms." << endl;
}

void traitementB()
{
	debutTraitementB = chrono::system_clock::now();

	for(int i = tailleY / 2 ; i < tailleY - 1; i++)
	{
		int _nbr = tableau[0][i] * tableau[1][i];
	}

	finTraitementB = chrono::system_clock::now();

	// Je fais dormir les threads momentanément pour éviter  
	// que les messages ne s'affichent en même temps, sur la même ligne.

	this_thread::sleep_for(chrono::milliseconds(500));

	cout << "Fin du traitement du thread B en " << chrono::duration_cast<chrono::milliseconds>(finTraitementB - debutTraitementB).count() << " ms." << endl;
}

int main()
{
	cout << "Programme avec deux threads" << endl;

	for (int x = 0; x < tailleX; x++)
	{
		for (int y = 0; y < tailleY; y++)
		{
			tableau[x][y] = rand() % 10;
		}
	}

	thread threadA(traitementA);
	thread threadB(traitementB);

	threadA.join();
	threadB.join();

	do 
	{
		cout << "Pour quitter le programme saisissez une touche et tapez sur Entree." << endl;
		cin >> stop;
	}
	while (stop);

	return 0;
}