// File containing code to create box like objects that are later on used to create more complicated objects in the game

//creating and defining the file
#ifndef BLOCK_H_
#define BLOCK_H_

//including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>


//defining colors for different hardness of the boxes
		Fl_Color first = fl_rgb_color(0,110,51);   //dark green
		Fl_Color second = fl_rgb_color(0,154,23);  //green
		Fl_Color third = fl_rgb_color(170,219,30); //light green
		Fl_Color fourth = fl_rgb_color(204,255,0); //fluorescent yellow
		Fl_Color fifth = fl_rgb_color(255,239,0);  // yellow
		Fl_Color six = fl_rgb_color(255,130,0);    //orange
		Fl_Color seventh = fl_rgb_color(252,76,2); //halloween orange
		Fl_Color eight = fl_rgb_color(221,50,36);  // vermillion red
		Fl_Color nine = fl_rgb_color(225,6,0);     //red
		Fl_Color tenth = fl_rgb_color(0,0,0);      //black

		// creating an ordered list with colors
		Fl_Color colors[] ={tenth, nine, eight, seventh,six,fifth,fourth,third,second,first};



// creating the class as an instance of the FL_Box class instance, and thus inheriting some of its properties
class Block: public Fl_Box{
	//defining private variables
private:
	//Defining x and y coordinates that corresponds to the position of the upper left corner of the object
int x; int y;
int hardness = 9;
//defining public accessible functions
public:
// defining the function to create an instance of the class object
	Block(int x, int y);

	// defining a function that will make the object "move" on the screen
	void move(int newX, int newY);

	//defining functions that are getting the coordinates of an object
	int getX();
	int getY();

	//defining function to get the hardness of the brick
	int getH();

	//defining function that will activate when the brick is hit
	void hit();
};

// creating the starting function based on the Fl_Box object, with concrete coordinates, dimensions and box style
//40 and 40 as width and height as specified in the project description
Block::Block(int x, int y): Fl_Box(x,y,40,40){
	this -> box (FL_FLAT_BOX);
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
	this->draw();
}

//creating the function that returns the x coordinate
int Block::getX(){
	return this->x;
}

//creating the function that returns the y coordinate
int Block::getY(){
	return this->y;
}


// creating the function to get the hardness of the object
int Block::getH(){
	return this->hardness;
}


void Block::hit(){
		// if the brick is hit, set its hardness to a lower one
	    //and change its color so that it correspond the hardness, then show the brick
			this->hardness-=1;
			this -> color(colors[hardness]);
			this-> show();
			//if the brick is destroyed move to right lower corner so that it does not
			//interfere with ball movements
			if(hardness<=0){
				this->move(640,480);
		}
}


#endif /* BLOCK_H_ */

