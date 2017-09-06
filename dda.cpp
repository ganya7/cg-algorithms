#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>


void DDA(int,int,int,int);

void main()
{
	int gDriver=DETECT,gMode;
	int x0,x1,y0,y1,steps,dx;
	initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
	cout<<"Enter x0 and y0\n";
	cin>>x0>>y0;
	cout<<"Enter x1 and y1\n";
	cin>>x1>>y1;
	DDA(x0,y0,x1,y1);
	getch();
	closegraph();
}
void DDA(int x0,int y0,int x1,int y1)
{
	int v,dx=x1-x0;
	int x=x0,y=y0;
	int dy=y1-y0;
	float xinc,yinc,steps;
	if(dx>dy)
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=dx/steps;
	yinc=dy/steps;
	for(v =0;v<steps;v++)
	{
		putpixel(x,y,3);
		x=x+xinc;
		y=y+yinc;
	}
}