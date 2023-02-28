// File containing code to create "brick" objects that are used in the game

//creating and defining the file
#ifndef BRICK_H_
#define BRICK_H_

// including header files with an object class
//#include "block_new.h"
#include "block.h"

// including necessary libraries
#include <iostream>
#include <vector>
using namespace std;
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <algorithm>



// creating the class as an instance of the Block class instance, and thus inheriting some of its properties
class Brick: public Block{
private:
	// adding hardness variable and setting it to 9
	//(indexes in lists starts with 0 and so 9th index will be the 10th element in the list)
	int hardness = 9;

	// Brick's body
	vector<Block*> body;

//defining public accessible functions and variables
public:
	// defining the function to create an instance of the class object
	Brick(int x, int y);

	// defining a function that will be used to handle situations in which the object is hit by another object (the ball)
	//void hit();

	//defining a function that will draw multiple instances of an object
	void draw_all();

	//defining function that is getting the hardness of an object
	int getH();

	//Defining a function to get the body of the bricks
	vector<Block*> getBricks();


	void deleteBrick();
};

// creating the starting function based on the Fl_Box object, with concrete coordinates,dimensions(inherited), box style and color
Brick::Brick(int x, int y):Block(x,y){
	this-> box(FL_NO_BOX);
    // draw the bricks
	this->draw_all();

}

//function to get the vector body of the bricks
vector<Block*> Brick::getBricks(){
	return this->body;
}

// creating the function to get the hardness of the object
int Brick::getH(){
	return this->hardness;
}

//creating the function to draw more instances of the object
void Brick::draw_all(){

	// bricks are allowed to only show up in a specific are so we are defining that area maximum values
	// they are not limited in x axis so it is just the width of the screen
	int maxx_brick = 640;
	//they are allowed to show up only in the upper part of the screen
	int maxy_brick = 480/2;


	// since the dimensions are not accessible from this scope I redefine the height and width of a brick
	int brickx = 40;
	int bricky = 40;


	// getting the coordinates of the first brick
	int row = this->getX();
	int col = this->getY();


// creating a nested loop that will create bricks that are going to be 5 units apart from each other, next to each other, from left to right
	// once a row is filled with bricks it will move one row lower and continue the same until it reaches the set maximum (middle of the screen)
	      for (int i=col; i<=(maxy_brick-bricky); i+=bricky+5){
	    	  for (int j= row; j<=(maxx_brick-brickx); j+=brickx+5){
	    		  // Building brick
	    		  Block*brick = new Block(j,i);

	    		  //giving it the right color
	    		  brick -> color(colors[hardness]);

	    		  //adding a brick to brick's vector
	              this->body.push_back(brick);
	    	  }
	      }
	      //displaying bricks on the screen
	 this-> show();
}


void Brick::deleteBrick(){
	for (Block *brick : this->body){
		if (brick->getH()<= 0){
			vector<Block*>::iterator new_end;
			//if (this->bricks.front() == brick){
			// second element becomes first element
			//}
			if (this->body.back() == brick){
				this->body.pop_back();
			}
			else{
				new_end = remove(this->body.begin(), this->body.end(), brick);
			}

		}
	}
}

#endif /* BRICK_H_ */
