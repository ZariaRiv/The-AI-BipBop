// File containing code to create "plank" object that is used in the game

//creating and defining the file
#ifndef PLANK2_H_
#define PLANK2_H_

// including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>


// creating the class as an instance of the FL_Box class instance, and thus inheriting some of its properties
class Platform:public Fl_Box{
	//defining private variables
private:
	//Defining x and y coordinates that corresponds to the position of the upper left corner of the object
int x; int y;
//defining public accessible functions
public:
// defining the function to create an instance of the class object
	Platform(int x, int y);

	// defining a function that will make the object "move" on the screen
	void move(int newX, int newY);

	//defining functions that are getting the coordinates of an object
	int getX();
	int getY();

	//defining a function that will handle different events
	int handle(int event);
};


//creating the movement function
void Platform::move(int newX, int newY){
	//hiding the widget
	this -> hide();
	//setting new coordinates
	this -> x=newX;
	this -> y=newY;
	//setting new position with the coordinates
	this->position(newX,newY);
	//showing the widget in the new position on the screen
	this->show();
}

//creating the function that returns the x coordinate
int Platform::getX(){
    return this->x;
}

//creating the function that returns the y coordinate
int Platform::getY(){
    return this->y;
}


// creating a function for handling pressing specific keys (FLTK handler for keys)
// this function is not being called in any specific place but is automatically executed when an even occurs
int Platform::handle(int event){

    // ASCI key codes for capital A and D which are sometimes used to move right and left
    int RKey = 100;
    int LKey = 97;

    //getting current position of an object
    int currentx=this->getX();
    int currenty=this->getY();

    //an algorithm that will execute different things depending on which key will be pressed
    switch(event){
    case FL_KEYDOWN:            // keyboard key pushed
    case FL_KEYUP:              // keyboard key released
    	{
    	// if left arrow or A were pressed
        if(Fl::event_key() == FL_Left || Fl::event_key() == LKey){
            // move 10 units to the left by calling the move function (only in x axis)
        	this->move((currentx-10), currenty);
        	//redraw the window to make sure all widgets are now in correct places
        	redraw();
            return 1;
            break;
        }
        // if right arrow or D were pressed
        else if(Fl::event_key() == FL_Right || Fl::event_key() == RKey){
        	// move 10 units to the right by calling the move function (only in x axis)
        	this->move((currentx+10), currenty);
        	//redraw the window to make sure all widgets are now in correct places
        	redraw();
            return 1;
            break;
        }
     //no break
     default: return Fl_Widget::handle(event);
    }
    }
}


// creating the starting function based on the Fl_Box object, with concrete coordinates, dimensions, color and box style
//100 and 20 as width and height as specified in the project description
Platform::Platform(int x, int y): Fl_Box(x,y,100,20){
	this -> box (FL_FLAT_BOX);
	this-> color (FL_WHITE);
	this-> x=x;
	this-> y=y;
	//displaying the board on the screen
	this-> show();
}


#endif /* PLANK2_H_ */
