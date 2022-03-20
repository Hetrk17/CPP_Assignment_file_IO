//Het Kanzariya

#include<fstream>
#include<iostream>
#include<cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class student
{
	public:
	     int ID; string name;string Location; string Branch;
	     void getdata()
	     {
	     	cout << "Enter ID" <<endl;
	     	cin>>ID;
	     	cout << "Enter Name" <<endl;
	     	cin>>name;
	     	cout << "Enter Location" <<endl;
	     	cin>>Location;
	     	cout<<"Enter Branch"<<endl;
	     	cin>>Branch;
	     }
	     void Addrecode()
	     {
	     	fstream f;
	     	student stu;
	     	f.open("student.txt", ios::app);
	     	stu.getdata();
	     	try
	     	{
	     	            if((isNumber(stu.ID)!=0) || (isNumber(stu.name)!=1) || (isNumber(stu.Location)!=1) || (isNumber(stu.Branch)!=1)) 
	     	            {	
	     	            	throw 5.4;
	     	            }
	     	            else
	     	            {
	     	       	        f << stu.ID << "\t" << stu.name << "\t" << stu.Location << "\t"<< stu.Branch << endl<<"Update\n";
	     	            }
	     	}
	     	catch(double x)
	     	{
	     	            cout<<"Enter valid data and try again \n";
	     	}
	     	f << stu.ID << "\t" << stu.name << "\t" << stu.Location << "\t"<< stu.Branch << endl;
	     	f.close();
	     }
	     void display()
	     {
	     	int id1;
	     	int count=1;
	     	int flag = 1;
	     	int count1=0;
	     	int num;
	     	string buf,str;
	     	fstream f1;
	     	student s;
	     	cout<< "Enter a student ID:-";
	     	cin >> id1;
	     	try
	     	{
	     		f1.open("student.txt", ios::in);
	     	     	if(!f1)
	     	     	{
	     	     		throw 5;
	     	     	}
	     	}
	     	catch(int x)
	     	{
	     		cout << "File not found\n";
	     		exit (0);
	     	}
	     	//stringstream ss; 
	     	while(getline(f1,buf))
		{
			stringstream ss(buf);
			while(getline(ss,str,'\t'))
	     		{
	     			if(count1 == 0)
	     			{
	     				count1++;
	     				continue;
	     			}
		     		else if(count == 0)
		     		{
		     			  stringstream obj;  
					  obj << str;  
					  obj >> num;  
					  if(num == id1)
					  {
					  	flag = 0;
					  	getline(ss,str,'\t');
					  	cout << "Name:- " << str << "\t";
					  	getline(ss,str,'\t');
					  	cout << "Location:- " << str << "\t";
					  	getline(ss,str,'\t');
					  	cout << "Branch:- " << str << "\t" << endl;
					  	cout << "\n--------------------------------------------------------\n\n\n";
					  	break;
					  }
		     		}
		     		count++;
	     		}
	     		count = 0;
	     	}
	     	if(flag)
	     	{
	     		cout << "Student ID is not found" << endl;
	     	}
	     	f1.close();
	     }
};

int main()
{
	student s1;
	fstream f;
	int choise;
	f.open("student.txt", ios::app);
	//f << "\n";
	//f << "ID\t" << "Name\t" << "Location\t" << "Branch" <<endl; 
	while(1)
	{
		cout << "\n\n---------------------Manu-------------------------------\n";
		cout << "1 : enter student detail \n2: find student \n3: Exit\n"; 
		cout << "Enter your choise:- ";
		cin >> choise;
		if(choise == 1)
		{
			s1.Addrecode();
			cout<<"updated!!!"<<endl;
			cout << "\n\n--------------------------------------------------------\n\n\n";
		}
		else if(choise == 2)
		{
			student s2;
			s2.display();
		}		
		else 
		{
			break;
		}
	}
	cout << "Thank you" << endl;
	return 0;
}
