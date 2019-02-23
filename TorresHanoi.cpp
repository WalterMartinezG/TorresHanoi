#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include <Windows.h>
#include <cctype>
using namespace std;

COORD coord = { 0,0 }; // this is global variable

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hanoi(int num, char A, char C, char B)
{
	if (num == 1)
	{
		cout << "Mueva el disco " << num << " desde " << A << " hasta  " << C << endl;

	}
	else
	{
		hanoi(num - 1, A, B, C);
		cout << "Mueva el disco " << num << " desde " << A << " hasta  " << C << endl;
		hanoi(num - 1, B, C, A);
	}
}

int main()
{
	char salir = 'y';

	while (salir == 'y')
	{
		char A, B, C, discos[2];
		int digito;
		bool verif = FALSE;
		system("cls");


		system("color A");
		gotoxy(45, 0);
		cout << "****TORRES DE HANOI RESOLUCION****\n";
		cout << "Ingrese el numero de discos para calcular la solucion: ";
		cin >> discos;
		digito = atoi(discos);

		while (verif == FALSE)
		{

			if (digito == 0)
			{
				system("cls");
				gotoxy(45, 0);
				cout << "****TORRES DE HANOI RESOLUCION - TORRES IDENTIFICADAS COMO A, B y C****\n";
				cout << "Usted ingreso no ingreso un numero. Ingrese el numero de discos para calcular la solucion: ";
				cin >> discos;
				digito = atoi(discos);

			}
			else
			{
				verif = TRUE;
			}
		}

		hanoi(digito, 'A', 'C', 'B');
		system("pause");
		system("cls");
		cout << "Presione cualquier tecla para salir o Y si desea otra solucion: ";
		cin >> salir;
		
	}

	system("cls");
	system("color F");
	gotoxy(20, 8);
	cout << "*****Gracias por utilizar el sistema de resolucion de las Torres de Hanoi********\n";
	cout << "\n";
	cout << "Integrantes: \n";
	cout << "Walter Estuardo Martinez Garrido 0900-18-10129\n";
	cout << "Javier Alejandro Montenegro Barrios 0900-10-1098\n";
	cout << "Pedro Luis Mejia Dardon 0900-12-13905\n";
	system("pause");
	system("exit");
}

