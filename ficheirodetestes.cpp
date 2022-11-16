#include <iostream>
#include<string>
using namespace std;
//Code by devenum.com
void displaymenu()
{ cout<<"===================================================== \n";
cout<<" \t\tMENU \t \n ";
cout<<"===================================================== \n";
cout<<" 1.Vendas\n";
cout<<" 2.Stock\n";
cout<<" 3.Relatorios \n";
cout<<" 4.Clientes \n";
}//Code by devenum.com
void Addstudent()
{
cout<< "you have selected add student : \n";
}
void DeleteStudent()
{
cout<< "you have selected delete student \n";
}
void updatestudent()
{
cout<< "you have selected update student 3\n";
}
void ViewAllStudentRecords()
{
cout<< "View all student records 4\n";
}
void FindStudent()
{
cout<< "you have selected Find a stduent \n";
}
 
//Code by devenum.com
 
int main()
{ 
 
string st[20];
int itemcount = 0;
displaymenu(); 
int yourchoice;
string confirm;
do
{ cout<<"Enter your choice(1-5):";
cin>>yourchoice;
switch (yourchoice)
{
case 1: Addstudent(); break;
case 2: DeleteStudent();break;
case 3: updatestudent(); break;
case 4: ViewAllStudentRecords(); break;
case 5: FindStudent();break;
default: cout<<"invalid"; break;
}
cout<<"Press y or Y to continue:";
cin>>confirm;
} while (confirm == "y" || confirm == "Y");
return 0;
}