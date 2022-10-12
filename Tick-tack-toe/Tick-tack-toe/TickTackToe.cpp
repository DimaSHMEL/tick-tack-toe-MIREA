#include <iostream>
#include <exception>
using namespace std;

char** createTable()
{
	char** TickTackToe_Table = new char* [3];
	for (int count = 0; count < 3; count++)
		TickTackToe_Table[count] = new char[3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			TickTackToe_Table[i][j] = '.';
		}
	}
	return TickTackToe_Table;
}

bool clearTable(char **TickTackToe_Table)
{
	try {
		TickTackToe_Table[0][0] =
			TickTackToe_Table[0][1] =
			TickTackToe_Table[0][2] =
			TickTackToe_Table[1][0] =
			TickTackToe_Table[1][1] =
			TickTackToe_Table[1][2] =
			TickTackToe_Table[2][0] =
			TickTackToe_Table[2][1] =
			TickTackToe_Table[2][2] =
			'.';
		
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}

string writeTable(char **TickTackToe_Table)
{
	string answ = "";
	try {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				answ.append(1, TickTackToe_Table[i][j]);
			}
			answ.append(1, '\n');
		}
	}
	catch (exception e)
	{
		return "TABLE IS BROKEN";
	}
	return answ;
}

bool fill(int x, int y, char player, char **table)
{
	try {
		if(table[x][y] == '.')
			table[x][y] = player;
		else
			return false;
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}

int checkWinner(char **table)
{
	if ((table[0][0] == table[1][1] == table[2][2]) || (table[0][2] == table[1][1] == table[2][0]))
	{
		if (table[1][1] == 'X')
			return 1;
		else
			return 2;
	}
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == table[i][1] == table[i][2])
		{
			if (table[i][1] == 'X')
				return 1;
			else
				return 2;
		}
		else if (table[0][i] == table[1][i] == table[2][i])
		{
			if (table[0][i] == 'X')
				return 1;
			else
				return 2;
		}
	}
	return 0;
}

bool checkFull

void game()
{
	char** table = createTable();

	clearTable(table);
	cout << writeTable(table);

}
int main()
{
	game();
	
	return 0;
}