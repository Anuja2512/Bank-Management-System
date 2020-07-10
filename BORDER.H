#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
class box1
{
int x,y,x1,y1;
public:
	void setvalue(int,int,int,int);
	void drawbox();
};
void box1::setvalue(int a,int b,int c,int d)
{
	x=a;
	y=b;
	x1=c;
	y1=d;
}
void box1::drawbox()
{
textcolor(WHITE);
gotoxy(x,y);
putch(201);
gotoxy(x1,y);
putch(187);
gotoxy(x,y1);
putch(200);
gotoxy(x1,y1);
putch(188);
for(int i=x+1;i<x1;i++)
{
gotoxy(i,y);
putch(205);
gotoxy(i,y1);
putch(205);
}
for(i=y+1;i<y1;i++)
{
gotoxy(x,i);
putch(186);
gotoxy(x1,i);
putch(186);
}
}

