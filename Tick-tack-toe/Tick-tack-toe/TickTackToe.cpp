#include <iostream>
#include <sstream>
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
	catch (...)
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
	catch (...)
	{
		return false;
	}
	return true;
}

int checkWinner(char **table)
{
	if ((table[0][0] == table[1][1] && table[1][1] == table[2][2]) || (table[0][2] == table[1][1] && table[1][1] == table[2][0]))
	{
		if (table[1][1] == 'X')
			return 1;
		else if (table[1][1] == 'O')
			return 2;
	}
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2])
		{
			if (table[i][1] == 'X')
				return 1;
			else if (table[i][1] == 'O')
				return 2;
		}
		else if (table[0][i] == table[1][i] && table[1][i] == table[2][i])
		{
			if (table[0][i] == 'X')
				return 1;
			else if (table[0][i] == 'O')
				return 2;
		}
	}
	return 0;
}

bool checkFull(char** table)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] == '.')
				return false;
		}
	}
	return true;
}

string game(string input)
{
	istringstream in(input);
	string answ = "";
	char** table = createTable();
	int player = 0;
	char players[2] = {'X', 'O'};
	while ((!checkFull(table)) && checkWinner(table) == 0)
	{
		answ += writeTable(table);
		try {
			int x, y;
			in >> x >> y;
			if (x == 0 || y == 0)
			{
				throw invalid_argument("x is not");
			}
			while (!fill(--x, --y, players[(player % 2)], table))
			{
				in >> x, y;
			}
		}
		catch (...)
		{
			return answ + "INVALID INPUT TRY AGAIN";
		}
		player++;
	}
	answ += writeTable(table);
	if (checkWinner(table) != 0)
	{
		answ += "P" + to_string(checkWinner(table)) + " WINS";
	}
	else
	{
		answ += "TIE";
	}
	return answ;
	

}

void game()
{
	char** table = createTable();
	int player = 0;
	char players[2] = { 'X', 'O' };
	while ((!checkFull(table)) && checkWinner(table) == 0)
	{
		cout<<writeTable(table);
		try {
			int x, y;
			cin >> x >> y;
			if (x == 0 || y == 0)
			{
				throw invalid_argument("x is not");
			}
			while (!fill(--x, --y, players[(player % 2)], table))
			{
				cin >> x, y;
			}
		}
		catch (...)
		{
			cout<<"INVALID INPUT TRY AGAIN";
		}
		player++;
	}
	cout<< writeTable(table);
	if (checkWinner(table) != 0)
	{
		cout<< "P" + to_string(checkWinner(table)) + " WINS";
	}
	else
	{
		cout << "TIE";
	}
}

int main()
{
	//cout << game("1 1 2 1 3 1 2 2 1 2 2 3");
	game();
	return 0;
}