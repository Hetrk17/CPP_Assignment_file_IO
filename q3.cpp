//Het Kanzariya

#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	fstream file;
	string str;
	int size;
	int count = 0;
	char ch = 'e';
	try
	{
		file.open("file.txt",ios::in);
		if(!file)
		{
			throw 5;		//if file not open then throw the exeption 
		}
	}
	catch(int x)
	{
	   	cout << "The file cannot open" << endl; 		//catch the file not exeption opened
	     	exit (0);
	}			
	while(file >> str)
	{
		//size = strlen(str)
		if(str[0]==ch)    //'e' charecter found at start and if found then count +1;
		{
			count++;
			continue;
		}
		//cout << str << endl;			
			
	}
	cout << "Total word start with 'e' is "<<count<<endl;
	return 0;
}

