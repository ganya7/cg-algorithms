#include <iostream.h>
#include <conio.h>
#include <graphics.h>

void dcircle(int rad, int cx, int cy)
{
	float p = 1 - rad;
	int x=0,y=rad;
	int xc=cx,yc=cy;
	putpixel(x,y,RED);
	while(x <= y)
	{
		x++;
		if(p<0)
			p = p + 2*x + 1;
		else
		{
			y--;
			p = p + 2 * ( x - y ) + 1;
		}
		putpixel(xc+x,yc+y,RED); //1 oct
		putpixel(xc+x,yc-y,RED);//8 oct
		putpixel(xc-x,yc+y,RED);//3 oct
		putpixel(xc-x,yc-y,RED);//5 oct
		putpixel(xc+y,yc+x,RED);//2 oct
		putpixel(xc+y,yc-x,RED);//4 oct
		putpixel(xc-y,yc+x,RED);//7 oct
		putpixel(xc-y,yc-x,RED);//6 oct
	}

}

void main()
{
	int r;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cout<<"\nEnter radius of circle: ";
	cin>>r;
	cout<<"\nEnter center coordinates: ";
	int xc,yc;
	cin>>xc>>yc;
	dcircle(r,xc,yc);
	getch();
	cleardevice();
	closegraph();
}
