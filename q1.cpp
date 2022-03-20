
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
	string cmp = "the";  
	try
	{
		file.open("file.txt",ios::in);
		if(!file)
		{
			throw 5;   		//if file not open then throw the exeption 
		}
	}
	catch(int x)     		 	
	{
	   	cout << "The file cannot open" << endl;   //catch the file not exeption opened
	     	exit (0);
	}
			
	while(file >> str)
	{
		if(str.compare(cmp)==0) //'the' word compare and if mach then count +1;
		{
			count++;
		}
		//cout << str << endl;			
		
	}
	
	cout << "Total 'the' word in file is "<<count<<endl;
	return 0;
}

