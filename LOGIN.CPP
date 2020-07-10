#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<dos.h>
class login
{
char uname[20];
char pass[20];
public:
login();
int userlogin();
};
login::login()
{
strcpy(uname,"anuja");
strcpy(pass,"sandwich");
}
int login::userlogin()
{
char u[20],p[20];
int i=0,flag;
cout<<"Enter the username:";
cin>>u;
cout<<"Enter the password";
while((p[i]=getch())!=13)
{
if (p[i]==8&&i>0)
{
cout<<"\b \b";
i--;
}
else if(p[i]!=8)
{
cout<<"*";
i++;
}
}
p[i]='\0';
if(strcmpi(p,pass)==0&&strcmpi(u,uname)==0)
{
flag=0;
return flag;
}
else
{
flag=1;
return flag;
}
}