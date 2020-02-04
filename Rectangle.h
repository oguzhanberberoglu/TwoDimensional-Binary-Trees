/* 
OGUZHAN BERBEROGLU 24001
CS300 Homework1
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
public:
	Rectangle();
	Rectangle(int,int,int,int);
	int getTop();
	int getLeft();
	int getBottom();
	int getRight();

	bool checkIntersect_HorizantalLine(int); // true if rectangle intersects with Horizantal Line
	bool checkIntersect_VerticalLine(int); // true if rectangle intersects with Vertical Line

	bool checkRectangleIs_TopSide(int); // return true if it is on top side; false if it is bottom side
	bool checkRectangleIs_LeftSide(int); // return true if it is on left side; false if it is on right side

	bool check_Point_InRectangle(int,int); // true; if the query point in the rectangle
	bool check_Point_OnVerticalLine(int); // true if query point on the Vertical Line
	bool check_Point_OnHorizantalLine(int); // true if query point on the Horizantal Line

	bool checkPointIs_TopSide(int); // true if point is on Top Side
	bool checkPointIs_LeftSide(int); // true if point is on Left Side

	void print(); // prints the coordinetes in order of (Top,Left,Bottom,Right)

private:
	int Top; // y coordinate of the upper edge
	int Left; // x coordinate of the left edge
	int Bottom; // y coordinate of the bottom edge
	int Right; // x coordinate of the right edge

	friend class TwoDimTreeNode;
};

#endif