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
		{
			putpixel(xc+x,yc+y,RED);
			putpixel(xc+x,yc-y,RED);
			putpixel(xc-x,yc+y,RED);
			putpixel(xc-x,yc-y,RED);
			putpixel(xc+y,yc+x,RED);
			putpixel(xc+y,yc-x,RED);
			putpixel(xc-y,yc+x,RED);
			putpixel(xc-y,yc-x,RED);

			p = p + 2*x + 1;
		}
		else
		{
			y--;
			putpixel(xc+x,yc+y,RED);
			putpixel(xc+x,yc-y,RED);
			putpixel(xc-x,yc+y,RED);
			putpixel(xc-x,yc-y,RED);
			putpixel(xc+y,yc+x,RED);
			putpixel(xc+y,yc-x,RED);
			putpixel(xc-y,yc+x,RED);
			putpixel(xc-y,yc-x,RED);
			p = p + 2 * ( x - y ) + 1;
		}
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