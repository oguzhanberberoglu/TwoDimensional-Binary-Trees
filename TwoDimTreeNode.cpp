/* 
OGUZHAN BERBEROGLU 24001
CS300 Homework1
*/
#include <iostream>
#include "TwoDimTreeNode.h"
using namespace std;

TwoDimTreeNode::TwoDimTreeNode() // default constuctor
{
	TopLeft = NULL;
	TopRight = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
}
TwoDimTreeNode::TwoDimTreeNode(Rectangle E) // constructor with Rectangle object parameter
{
	Extent = E;
	TopLeft = NULL;
	TopRight = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
}
TwoDimTreeNode::~TwoDimTreeNode()
{}

void TwoDimTreeNode::deleteTree(TwoDimTreeNode *&ptr) // delete recursively
{
	if (ptr != NULL)
	{
		if (ptr->TopLeft != NULL)
			ptr->deleteTree(ptr->TopLeft);

		if (ptr->TopRight != NULL)
			ptr->deleteTree(ptr->TopRight);

		if (ptr->BottomLeft != NULL)
			ptr->deleteTree(ptr->BottomLeft);

		if (ptr->BottomRight != NULL)
			ptr->deleteTree(ptr->BottomRight);

		delete ptr;
		ptr = NULL;
	}
}

void TwoDimTreeNode::insertRectangle(TwoDimTreeNode *&tree,Rectangle rec)
{
	int centerLineX = (Extent.getRight() + Extent.getLeft()) / 2; // center lines of extent
	int centerLineY = (Extent.getBottom() + Extent.getTop()) / 2;

	if (rec.checkIntersect_VerticalLine(centerLineX)) // check if the rectangle intersects with Vertical Line
	{
		tree->Vertical.push_back(rec); 
	}
	else if (rec.checkIntersect_HorizantalLine(centerLineY)) // check if the rectangle intersects with Horizantal Line
	{
		tree->Horizontal.push_back(rec);
	}
	else if (rec.checkRectangleIs_TopSide(centerLineY) && rec.checkRectangleIs_LeftSide(centerLineX)) // given rectangle does not intersect any center lines AND it is on the top left
	{   // TOP LEFT
		if (tree->TopLeft == NULL)
		{
			Rectangle temp(Extent.getTop(), Extent.getLeft(), centerLineY, centerLineX); // area of Top Left
			tree->TopLeft = new TwoDimTreeNode(temp);
		}
		tree->TopLeft->insertRectangle(tree->TopLeft,rec);
	}
	else if (rec.checkRectangleIs_TopSide(centerLineY) && !rec.checkRectangleIs_LeftSide(centerLineX)) // top right
	{
		if (tree->TopRight == NULL)
		{
			Rectangle temp(Extent.getTop(), centerLineX + 1, centerLineY, Extent.getRight()); // area of Top Right
			tree->TopRight = new TwoDimTreeNode(temp);
		}
		tree->TopRight->insertRectangle(tree->TopRight,rec);
	}
	else if (!rec.checkRectangleIs_TopSide(centerLineY) && rec.checkRectangleIs_LeftSide(centerLineX)) // bottom left
	{
		if (tree->BottomLeft == NULL)
		{
			Rectangle temp(centerLineY+1, Extent.getLeft(), Extent.getBottom(), centerLineX); // area of Bottom Left
			tree->BottomLeft = new TwoDimTreeNode(temp);
		}
		tree->BottomLeft->insertRectangle(tree->BottomLeft,rec);
	}
	else if (!rec.checkRectangleIs_TopSide(centerLineY) && !rec.checkRectangleIs_LeftSide(centerLineX)) // bottom right
	{
		if (tree->BottomRight == NULL)
		{
			Rectangle temp(centerLineY+1, centerLineX+1, Extent.getBottom(), Extent.getRight()); // area of Bottom Left
			tree->BottomRight = new TwoDimTreeNode(temp);
		}
		tree->BottomRight->insertRectangle(tree->BottomRight,rec);
	}
}

void TwoDimTreeNode::searchPoint(TwoDimTreeNode*&tree, vector<Rectangle>&List, int x, int y,int &count)
{
	if (Extent.check_Point_OnVerticalLine(x)) // query point is on vertical line?
	{
		for (int i = 0; i < Vertical.size(); i++)
		{
			if (Vertical[i].check_Point_InRectangle(x,y))
			{
				List.push_back(Vertical[i]);
				count++;
			}
		}
	}
	else if(Extent.check_Point_OnHorizantalLine(y)) // query point is on horizantal line?
	{
		for (int k = 0; k < Horizontal.size(); k++)
		{
			if (Horizontal[k].check_Point_InRectangle(x,y))
			{
				List.push_back(Horizontal[k]);
				count++;
			}
		}
	}
	else // check the point in the rectangles that intersected with vertical and horizantal lines
	{
		for (int i = 0; i < Vertical.size(); i++) // vertical Line 
		{
			if (Vertical[i].check_Point_InRectangle(x,y))
			{
				List.push_back(Vertical[i]);
				count++;
			}
		}
		for (int j = 0; j < Horizontal.size(); j++) // horizantal line
		{
			if (Horizontal[j].check_Point_InRectangle(x,y))
			{
				List.push_back(Horizontal[j]);
				count++;
			}
		}
		// later; recursively called the function of tree that point stays on
		if (Extent.checkPointIs_TopSide(y) && Extent.checkPointIs_LeftSide(x)) // top left
		{
			if (tree->TopLeft != NULL)
				tree->TopLeft->searchPoint(tree->TopLeft,List,x,y,count);
		}
		else if (Extent.checkPointIs_TopSide(y) && !Extent.checkPointIs_LeftSide(x)) // top right
		{
			if (tree->TopRight != NULL)
				tree->TopRight->searchPoint(tree->TopRight,List,x,y,count);
		}
		else if (!Extent.checkPointIs_TopSide(y) && Extent.checkPointIs_LeftSide(x)) // bottom left
		{
			if (tree->BottomLeft != NULL)
				tree->BottomLeft->searchPoint(tree->BottomLeft,List,x,y,count);
		}
		else if (!Extent.checkPointIs_TopSide(y) && !Extent.checkPointIs_LeftSide(x)) // bottom right
		{
			if (tree->BottomRight != NULL)
				tree->BottomRight->searchPoint(tree->BottomRight,List,x,y,count);
		}
	}
}