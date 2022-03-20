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
	char ch = 's';
	try
	{
		file.open("file.txt",ios::in);
		if(!file)
		{
			throw 5;
		}
	}
	catch(int x)
	{
	   	cout << "The file cannot open" << endl; 
	     	exit (0);
	}
				
	while(file >> str)
	{
		size = str.length();
		if(str[size-1]==ch)
		{
			count++;
		}
		//cout << str << endl;			
			
	}
	
	cout << "Total word end with 's' is "<<count<<endl;
	return 0;
}

