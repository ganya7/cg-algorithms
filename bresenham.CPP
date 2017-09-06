#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void breshen(int x0, int y0, int x1, int y1)
{
	int dx=x1-x0;
	int dy=y1-y0;
	int x=x0;
	int y=y0;
	int p=(2*dy)-dx;
	while(x<x1)
	{
		if(p<0)
		{
			putpixel(x,y,3);
			p=p+(2*dy);
		}
		else
		{
			putpixel(x,y,3);
			p=p+(2*(dy-dx));
			y++;
		}
		x++;
	}
}

void main()
{
	int x0=0,y0=0,x1=0,y1=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cout<<"Enter starting point: ";
	cin>>x0>>y0;
	cout<<"Enter end point: ";
	cin>>x1>>y1;

	breshen(x0,y0,x1,y1);
	getch();
	closegraph();

}