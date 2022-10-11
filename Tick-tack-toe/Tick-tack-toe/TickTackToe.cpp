#include <iostream>
#include <exception>
using namespace std;


bool clearTable(char (&TickTackToe_Table)[3][3])
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
bool writeTable(char (&TickTackToe_Table)[3][3])
{
	try {
		cout <<
			TickTackToe_Table[0][0]<<TickTackToe_Table[0][1]<< TickTackToe_Table[0][2] << endl <<
			TickTackToe_Table[1][0]<<TickTackToe_Table[1][1]<<TickTackToe_Table[1][2] << endl <<
			TickTackToe_Table[2][0]<<TickTackToe_Table[2][1]<<TickTackToe_Table[2][2] << endl;
	}
	catch (exception e)
	{
		return false;
	}
	return true;
}
int main()
{
	char TickTackToe_Table[3][3] = {
		{'.', ';', '.'},
		{'.', ';', '.'},
		{'.', '.', '.'},
	};
	clearTable(TickTackToe_Table);
	writeTable(TickTackToe_Table);
	return 0;
}