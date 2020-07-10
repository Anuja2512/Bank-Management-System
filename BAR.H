#include"c:\TURBOC3\BIN\Banking\OUTLINE.h"
#include"c:\TURBOC3\BIN\Banking\WELCOME.h"
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void start()
{
int a,x=2,b=4,t=1;
float c=1;
textbackground(BLACK);
clrscr();
box l;
l.setvalue(1,1,79,24);
l.drawbox();
for(t=2;t<=78;t++)
{
gotoxy(t,12);
textcolor(7);
textbackground(b);
cprintf("%c",177);
}
for(a=1;a<=90;a++)
{
gotoxy(20,5);
if(a%8==0)
continue;
textbackground(a);
textcolor(BLACK);
cprintf(" * * * * * Welcome To GPP Bank * * * * * ");
delay(300);
 gotoxy(x,12);
textcolor(WHITE);
textbackground(b);
cprintf(" ");
x=x+1;
gotoxy(65,11);
textbackground(BLACK);
cprintf("%.0f%Completed",c);
c=c+1.27;
gotoxy(35,14);
textbackground(b);
cprintf("loading...");
}
}

