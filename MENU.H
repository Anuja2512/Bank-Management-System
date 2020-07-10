#include<stdio.h>
#include<conio.h>
#include<bios.h>
#include<iostream.h>
#include<process.h>
#include<string.h>
#define max 6
class menu
{
char a[max][20];
int x,y;
public:
menu(int,int);
int action(int);
int arrow();
void disp(int);
};
menu::menu(int a1=1,int b=1)
{
char t[max][20]={"New Account","Balance Check","Cash Deposit","Cash Withdrawal","Delete Account","Exit"};
int i;
for(i=0;i<max;i++)
strcpy(a[i],t[i]);
x=a1;
y=b;
}
void menu::disp(int n)
{
int i,x1=x,y1=y;
textbackground(BLACK);
for(i=0;i<max;i++)
{
gotoxy(x1,y1);
if(n==i)
{
textbackground(WHITE);
textcolor(BLACK);
}
else
{
textbackground(BLACK);
textcolor(WHITE);
}
cprintf("%s",a[i]);
y1+=2;
}
}
int menu::arrow()
{
int ch,temp;
static int i=0;
disp(i);
do
{
ch=bioskey(0);
if(ch==18432)
i--;
if(ch==20480)
i++;
if(i==-1)
i=max-1;
if(i==max)
i=0;
if(ch==7181)
{
clrscr();
temp=action(i);
return temp;
getch();
}
disp(i);
}
while(ch!=283);
}
int menu::action(int ch)
{
int v;
switch(ch)
{
case 0:v=1;
break;
case 1:v=2;
break;
case 2:v=3;
break;
case 3:v=4;
break;
case 4:v=5;
break;
case 5:exit(0);
}
return v;
}