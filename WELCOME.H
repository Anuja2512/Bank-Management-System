#include<stdio.h>
#include<conio.h>
#include<dos.h>
void title()
{
int a;
textbackground(8);
clrscr();
for(a=1;a<=80;a++)
{
gotoxy(20,5);
if(a%8==0)
continue;
textbackground(a);
textcolor(BLACK);
cprintf(" * * * * * Welcome To GPP Bank * * * * * ");
delay(300);
}
textbackground(BLACK);
clrscr();
}
