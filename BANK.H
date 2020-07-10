#include<process.h>
#include<iostream.h>
#include<fstream.h>
class bank
{
int acc_no;
char name[20];
long int bal;
public:
void accept(int no)
{
acc_no=no;
cout<<"Enter the name:";
cin>>name;
bal=500;
cout<<"\nOpening Balance:"<<bal;
}
void display()
{
cout<<acc_no<<"\t\t\t";
cout<<name<<"\t\t";
cout<<bal;
}
int racno()
{
return acc_no;
}
long int rbal()
{
return bal;
}
void operator+=(int no)
{
bal=bal+no;
}
void operator-=(int no)
{
bal=bal-no;
}
};