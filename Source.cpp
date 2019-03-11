#include <iostream>
#include <conio.h>
using namespace std;

int sudoku[9][9] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
	{ 6, 0, 0, 1, 9, 5, 0, 0, 0 },
	{ 0, 9, 8, 0, 0, 0, 0, 0, 6 },
	{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
	{ 4, 0, 0, 8, 0, 3, 0, 0, 1 },
	{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
	{ 0, 6, 0, 0, 0, 0, 2, 8, 0 },
	{ 0, 0, 0, 4, 1, 9, 0, 0, 5 },
	{ 0, 0, 0, 0, 8, 0, 0, 7, 9 } };



bool VerificareRand(int sudoku[9][9], int ran, int valoare);
bool VerificareCol(int sudoku[9][9], int col, int valoare);
bool VerificarePatrat(int sudoku[9][9], int ran, int col, int valoare);
bool Rezolvat(int sudoku[9][9], int &ran, int &col);
bool Rezolvare(int sudoku[9][9]);

int main() {

	if (Rezolvare(sudoku)==true)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << sudoku[i][j];

			cout << endl;
		}
	}
	else
		cout << "nu e sudoku";

	_getch();

	return 0;
}

bool VerificareRand(int sudoku[9][9], int ran,int valoare) {

	for ( int col = 0;  col < 9;  col++)
		if (sudoku[ran][col] == valoare)
			return false;

		
	
	return true;
		
	

}

bool VerificareCol(int sudoku[9][9], int col, int valoare) {

	for (int ran = 0; ran < 9; ran++)
		if (sudoku[ran][col] == valoare)
			return false;

		
	return true;

	

}

bool VerificarePatrat(int sudoku[9][9], int ran, int col, int valoare) {

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (sudoku[i + ran][j + col] == valoare)
				return false;

	return true;

}

bool Rezolvat(int sudoku[9][9], int &ran, int &col) {

	for (ran = 0; ran< 9; ran++)
		for (col = 0; col < 9; col++)
			if (sudoku[ran][col] == 0)
				return false;
			
	return true;

}

bool Rezolvare(int sudoku[9][9])
{

	int ran = 0;
	int col = 0;

	if (Rezolvat(sudoku,ran,col))
		return true;

	for (int valoare = 1;valoare <= 9;valoare++) {

		if ((VerificareCol(sudoku, col, valoare)) && (VerificareRand(sudoku, ran, valoare)) && VerificarePatrat(sudoku, ran - ran % 3, col - col % 3, valoare)&&(sudoku[ran][col]==0)==true) 
		{

			sudoku[ran][col] = valoare;

			if (Rezolvare(sudoku))
				return true;

			sudoku[ran][col] = 0;
		}
	}
	return false;
}

