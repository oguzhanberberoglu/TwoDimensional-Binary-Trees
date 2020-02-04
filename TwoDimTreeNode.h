/* 
OGUZHAN BERBEROGLU 24001
CS300 Homework1
*/
#ifndef TWODIMTREENODE_H
#define TWODIMTREENODE_H
#include <vector>
#include "Rectangle.h"
using namespace std;

class TwoDimTreeNode
{
public:
	TwoDimTreeNode(); // constructor
	TwoDimTreeNode(Rectangle); // Extent parameter of Tree given constructor
	~TwoDimTreeNode(); // destructor
	void deleteTree(TwoDimTreeNode *&); // re-allocate dynamic memory
	void insertRectangle(TwoDimTreeNode*&,Rectangle); // insert a rectangle to Tree
	void searchPoint(TwoDimTreeNode*&,vector<Rectangle>&,int,int,int&); // given point searching in Tree

private:
	Rectangle Extent;
	vector<Rectangle> Vertical, Horizontal;
	TwoDimTreeNode *TopLeft, *TopRight, *BottomLeft, *BottomRight;
};
#endif