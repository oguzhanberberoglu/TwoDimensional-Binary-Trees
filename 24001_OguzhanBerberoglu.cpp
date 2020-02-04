/* 
OGUZHAN BERBEROGLU 24001
CS300 Homework1
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Rectangle.h"
#include "TwoDimTreeNode.h"
using namespace std;

int main()
{
	fstream file;
	string fileName = "rectdb.txt";
	do {
		file.open(fileName.c_str());
	} while (file.fail());

	int top,left,bottom,right;
	string s;
	// this part for root Rectangle of Tree
	getline(file,s);
	istringstream inp(s);
	inp >> top >> left >> bottom >> right;
	Rectangle rootExtent(top,left,bottom,right);
	TwoDimTreeNode *Tree = new TwoDimTreeNode(rootExtent);
	
	do
	{
		top = -1; // to deal with empty lines in .txt
		getline(file,s);
		istringstream input(s);
		input >> top;
		if (top >= 0) // valid Rectangle added to vector
		{
			input >> left >> bottom >> right;
			if (top < bottom && left < right) // insert the rectangles to tree
			{
				Rectangle add(top,left,bottom,right);
				Tree->insertRectangle(Tree,add);
			}
		}
	} while (top >= 0);
	
	bool loop = true;
	while (loop)
	{
		vector<Rectangle> ListofRectangles;
		int count = 0;
		cout << "Enter the query point: ";
		int x,y;
		cin >> x;
		if (x >= 0) // to exit program immediatley after entered negative value of x
			cin >> y;
		if (x<0 || y<0) // exit loop end finish execution
			loop = false;
		else // search the point in the tree
		{
			Tree->searchPoint(Tree,ListofRectangles,x,y,count);
			cout << count; // count many rectangles includes the point
			if (count != 0) // if any rectangle found; print the rectangles
			{ cout << endl;
				for (int i = 0; i < ListofRectangles.size(); i++)
					ListofRectangles[i].print();
			}
		} cout << endl;
	}
	Tree->deleteTree(Tree); // re-allocate dynamic memory 
	return 0;
}