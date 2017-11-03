#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int sign(int);
void genbreshen(int x1, int y1, int x2, int y2)
{
	int x=x1;
	int y=y1;
	int dx=abs(x2-x1);
	int dy=abs(y2-y1);
	int s1=sign(x2-x1);
	int s2=sign(y2-y1);
	int exchange=0,temp=0,e=0;
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		exchange=1;
	}
	else
		exchange=0;
	e=(2*dy)-dx;
	putpixel(x,y,3);
	for (int i = 1; i <= dx; i++)
	{
		while(e>=0)
		{
			if (exchange==1)
				x+=s1;
			else
				y+=s2;
			e=e-(2*dx);
		}
		if (exchange==1)
		{
			y+=s2;
		}
		else
			x+=s1;
		e=e+(2*dy);
		putpixel(x,y,3);
	}

}

int sign(int a)
{
	if(a<0)
		return -1;
	else if(a==0)
		return 0;
	else
		return 1;
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

	//genbreshen(x0,y0,x1,y1);
	genbreshen(x0+250,y0+250,x1+250,y1+250);
	//genbreshen(x0+250,y0+250,x1+250,y1+250);
	//genbreshen(x0+100,y0,x1+100,y1);
	line(250,0,250,500);
	line(0,250,500,250);
	getch();
	closegraph();

}
