
#include <iostream>
#include <fstream>

using namespace std;

void WriteScore(int value)
{
	ofstream file ("test.txt");
	if(file.is_open())
	{
		file << "Your score is " << value << endl;
		file.close();
	}
	else
	{
		cout << "File was not able to be opened." << endl;
	}
}
