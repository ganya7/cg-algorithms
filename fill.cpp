#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void boundaryFill(int x,int y,int fillColor,int borderColor)
{
	int curColor=getpixel(x,y);
	if((curColor!=borderColor)&&(curColor!=fillColor))
	{
		putpixel(x,y,fillColor);
		delay(10);
		boundaryFill(x,y+1,fillColor,borderColor);
		boundaryFill(x,y-1,fillColor,borderColor);
		boundaryFill(x+1,y,fillColor,borderColor);
		boundaryFill(x-1,y,fillColor,borderColor);
		
		boundaryFill(x-1,y-1,fillColor,borderColor);
		boundaryFill(x+1,y-1,fillColor,borderColor);
		boundaryFill(x-1,y+1,fillColor,borderColor);
		boundaryFill(x+1,y+1,fillColor,borderColor);

	}
}

void floodFill(int x,int y,int fillColor,int oldColor)
{
	int color=getpixel(x,y);
	if(color==oldColor)
	{
		putpixel(x,y,fillColor);
		delay(10);
		floodFill(x+1,y,fillColor,oldColor);
		floodFill(x-1,y,fillColor,oldColor);
		floodFill(x,y+1,fillColor,oldColor);
		floodFill(x,y-1,fillColor,oldColor);

		floodFill(x-1,y-1,fillColor,oldColor);
		floodFill(x+1,y-1,fillColor,oldColor);
		floodFill(x-1,y+1,fillColor,oldColor);
		floodFill(x+1,y+1,fillColor,oldColor);
	}
}

int main()
{
	int gd=DETECT,gm;
	int ch;
	int x,y;
	int fcol,bcol;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\bgi");
	cout<<"\nEnter seed point: ";
	cin>>x>>y;
	if(x > 200 && x < 225 && y > 200 && y < 225)
	{
		cout<<"\n\n1.Boundary fill \n2.Flood fill";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter filling colour: ";
					cin>>fcol;
					cout<<"\nEnter boundary colour: ";
					cin>>bcol;
					setcolor(bcol);
					/*line(200,200,225,200);
					line(225,200,225,225);
					line(225,225,200,225);
					line(200,225,200,200);*/
					rectangle(200,200,225,225);
					boundaryFill(x,y,fcol,bcol);
					break;
			case 2: cout<<"\nEnter filling colour: ";
					cin>>fcol;
					/*line(200,200,225,200);
					line(225,200,225,225);
					line(225,225,200,225);
					line(200,225,200,200);*/
					rectangle(200,200,225,225);
					floodFill(x,y,fcol,0);
					break;
		}
	}
	else
	{
		
		cout<<"\nPoint is not within object";
		/*getch();
		return 0;*/
	}
	getch();
	return 0;
}
