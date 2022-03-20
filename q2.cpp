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
	char ch = 'a';
	try
	{
		file.open("file.txt",ios::in);
		if(!file)
		{
			throw 5;  		//if file not open then throw the exeption 
		}
	}
	catch(int x)
	{
	   	cout << "The file cannot open" << endl;       //catch the file not exeption opened
	     	exit (0);
	}			
	while(file >> str)
	{
		if(str.find(ch)!=-1) 			//'a' charecter found and if found then count +1;
		{
			count++;
			continue;
		}
		//cout << str << endl;			
		
	}
	
	cout << "Total word contains 'a' in file is "<<count<<endl;
	return 0;
}

