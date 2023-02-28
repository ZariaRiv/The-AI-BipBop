// File containing code to create box like objects that are later on used to create more complicated objects in the game

//creating and defining the file
#ifndef BLOCK_H_
#define BLOCK_H_

//including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>


// creating the class as an instance of the FL_Box class instance, and thus inheriting some of its properties
class Block: public Fl_Box{
	//defining private variables
private:
	//Defining x and y coordinates that corresponds to the position of the upper left corner of the object
int x; int y;
//defining public accessible functions
public:
// defining the function to create an instance of the class object
	Block(int x, int y);

	// defining a function that will make the object "move" on the screen
	void move(int newX, int newY);

	//defining functions that are getting the coordinates of an object
	int getX();
	int getY();
};

// creating the starting function based on the Fl_Box object, with concrete coordinates, dimensions and box style
//40 and 40 as width and height as specified in the project description
Block::Block(int x, int y): Fl_Box(x,y,40,40){
	this -> box (FL_FLAT_BOX);
	//-> color (FL_BLACK);
	this-> x=x;
	this-> y=y;
}

//creating the movement function
void Block::move(int newX, int newY){
	//hiding the widget
	this -> hide();
	//setting new coordinates
	this -> x=newX;
	this -> y=newY;
	//setting new position with the coordinates
	this->position(newX,newY);
	//showing the widget in the new position
	//this->show();
}

//creating the function that returns the x coordinate
int Block::getX(){
	return this->x;
}

//creating the function that returns the y coordinate
int Block::getY(){
	return this->y;
}

#endif /* BLOCK_H_ */

