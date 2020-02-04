/* 
OGUZHAN BERBEROGLU 24001
CS300 Homework1
*/
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle()
{	
	Top = NULL;	Left = NULL;  Bottom = NULL;  Right = NULL; 
}

Rectangle::Rectangle(int t,int l,int b,int r) 
{  
	Top = t;	Left = l;	 Bottom = b;	 Right = r; 
}
// getters
int Rectangle::getTop() { return Top; }
int Rectangle::getLeft() { return Left; }
int Rectangle::getBottom() { return Bottom; }
int Rectangle::getRight() { return Right; }

bool Rectangle::checkIntersect_HorizantalLine(int centerYCord)
{
	if (centerYCord >= Top && centerYCord < Bottom)
		return true;
	return false;
}

bool Rectangle::checkIntersect_VerticalLine(int centerXCord)
{
	if (centerXCord >= Left && centerXCord < Right)
		return true;
	return false;
}

bool Rectangle::checkRectangleIs_TopSide(int centerYCord) // return true if it is on top side; false if it is bottom side
{
	if (Top >= centerYCord)
		return false;
	return true;
}

bool Rectangle::checkRectangleIs_LeftSide(int centerXCord) // return true if it is on left side; false if it is on right side
{
	if (Left >= centerXCord)
		return false;
	return true;
}

bool Rectangle::check_Point_InRectangle(int x,int y)
{
	if ((x>=Left && x<Right) && (y>=Top && y<Bottom))
		return true;
	return false;
}

bool Rectangle::check_Point_OnVerticalLine(int x)
{
	int centerLineX = (Left + Right) / 2;
	if (centerLineX == x)
		return true;
	return false;

}
bool Rectangle::check_Point_OnHorizantalLine(int y)
{
	int centerLineY = (Top + Bottom) / 2;
	if (centerLineY == y)
		return true;
	return false;
}

bool Rectangle::checkPointIs_TopSide(int y)
{
	int centerLineY = (Top + Bottom) / 2;
	if(y < centerLineY)
		return true;
	return false;
}
bool Rectangle::checkPointIs_LeftSide(int x)
{
	int centerLineX = (Left + Right) / 2;
	if(x < centerLineX)
		return true;
	return false;
}

void Rectangle::print()
{
	cout << Top << " " << Left << " " << Bottom << " "<< Right << endl;
}