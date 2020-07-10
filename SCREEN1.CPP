#include"c:\TURBOC3\BIN\Banking\BAR.h"
#include"c:\TURBOC3\BIN\Banking\BANK.h"
#include"c:\TURBOC3\BIN\Banking\MENU.h"
#include"c:\TURBOC3\BIN\Banking\LOGIN.h"
#include"c:\TURBOC3\BIN\Banking\BORDER.h"
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
clrscr();
start();
int temp;
textcolor(WHITE);
textbackground(BLACK);
clrscr();
gotoxy(25,4);
cout<<"ENTER THE BANK EMPLOYEE DETAILS";
box1 r;
r.setvalue(21,5,58,18);
r.drawbox();
login p;
gotoxy(26,7);
int ans=p.userlogin();
if(ans==0)
{
void add();
void disp();
void deposite();
void withdraw();
void del();
char get;
do
{
textcolor(YELLOW);
textbackground(BLACK);
clrscr();
gotoxy(33,2);
cout<<"M A I N   M E N U";
textcolor(WHITE);
r.setvalue(18,3,62,18);
r.drawbox();
menu m(35,5);
temp=m.arrow();
switch(temp)
{
case 1:add();
break;
case 2:disp();
break;
case 3:deposite();
break;
case 4:withdraw();
break;
case 5:del();
break;
default:exit(0);
}
flushall();
cout<<"\n*****************************************************************\n";
cout<<"\nDo you want to continue(y/n):\n";
cin>>get;
}while(get!='n');
}
else
{
textcolor(WHITE);
textbackground(BLACK);
clrscr();
r.setvalue(21,5,58,18);
r.drawbox();
gotoxy(26,11);
cout<<"Invalid Username or password";
getch();
}
}
void add()
{
bank s;
int no;
fstream bank_fil("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::in|ios::binary);

bank_fil.seekp(-(long)sizeof(s),ios::end);
if(bank_fil.read((char*)&s,sizeof(s)))
{
no=s.racno()+1;
}
else
no=401;
cout<<"\nAccount Number:"<<no;
bank_fil.close();
cout<<"\n***************************************************************\n";
fstream bank_file("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::app|ios::binary);
s.accept(no);
//bank_fil.seekp(-(long)sizeof(s),ios::end);
bank_file.write((char*)&s,sizeof(s));
bank_file.close();
}
void disp()
{
fstream bank_file("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::in|ios::binary);
bank s;
int no,flag=0;
bank_file.seekg(0);
flushall();
cout<<"Enter the account number:";
cin>>no;
cout<<"\nAccount no."<<"\t\tName"<<"\t\tBalance"<<endl;
cout<<"******************************************************************\n";
while(bank_file.read((char*)&s,sizeof(s)))
{
if(no==s.racno())
{
s.display();
flag=1;
break;
}
}
if(flag==0)
cout<<"Records not found";
bank_file.close();
}
void deposite()
{
fstream bank_file("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::in|ios::out|ios::binary);
int no;
bank s;
cout<<"\nEnter the Account Number:";
cin>>no;
int found=0;
while(bank_file.read((char*)&s,sizeof(s))&&found==0)
{
if(no==s.racno())
{
cout<<"\nAmount to be Deposited:";
cin>>no;
s+=no;
bank_file.seekp(-(long)sizeof(s),ios::cur);
bank_file.write((char*)&s,sizeof(s));
found=1;
cout<<"\nAmount Deposited";
}
}
if(found==0)
cout<<"\nRecord not found";
bank_file.close();
}
void withdraw()
{
fstream bank_file("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::in|ios::out|ios::binary);
int no;
bank s;
cout<<"\nEnter the Account Number:";
cin>>no;
int found=0;
while(bank_file.read((char*)&s,sizeof(s))&&found==0)
{
if(no==s.racno())
{
found=1;
cout<<"\nAmount to be Withdrawn:";
cin>>no;
if(no<=(s.rbal()-500))
{
s-=no;
bank_file.seekp(-(long)sizeof(s),ios::cur);
bank_file.write((char*)&s,sizeof(s));
cout<<"\nBalance deducted";
}
else
cout<<"\nInsufficient Balance";
}
}
if(found==0)
cout<<"\nRecord Not Found";
bank_file.close();
}
void del()
{
int no,flag=0;
fstream bank_file("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::in|ios::binary);
fstream temp_file("c:\\TURBOC3\\BIN\\Banking\\temp.dat",ios::out|ios::binary);
bank b;
cout<<"\nEnter the Account Number:";
cin>>no;
while(bank_file.read((char*)&b,sizeof(b)))
{
if(no!=b.racno())
temp_file.write((char*)&b,sizeof(b));
else
flag=1;
}
bank_file.close();
temp_file.close();
bank_file.open("c:\\TURBOC3\\BIN\\Banking\\bank.dat",ios::out|ios::binary);
temp_file.open("c:\\TURBOC3\\BIN\\Banking\\temp.dat",ios::in|ios::binary);
while(temp_file.read((char*)&b,sizeof(b)))
{
bank_file.write((char*)&b,sizeof(b));
}

bank_file.close();
temp_file.close();
if(flag==1)
cout<<"\nRecord Deleted";
else
cout<<"\nRecord Not Found";
}


