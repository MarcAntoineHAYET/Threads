#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int const tailleX = 2;
	int const tailleY = 1000;

	int tableau[tailleX][tailleY];

	for(int x = 0; x < tailleX; x++)
	{
		for(int y = 0; y < tailleY; y++)
		{
			tableau[x][y] = rand() % 10;

			cout << "Position X : " << x << " - Position Y : " << y << " - Nombre : " << tableau[x][y] << endl;
		}
	}
	
	system("Pause");

	return 0;
}