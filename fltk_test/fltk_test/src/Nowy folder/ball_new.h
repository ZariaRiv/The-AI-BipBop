// File containing code to create ball object that is used in the game

//creating and defining the file
#ifndef BALL_H_
#define BALL_H_

//including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <stdio.h>      /* printf */
#include <math.h>       /* asin */
#include <tgmath.h>

//Defining constant pi that is used for calculating angles
#define PI 3.14159265

double speedX=0;
//NOT WORKING

// creating the class as an instance of the FL_Box class instance, and thus inheriting some of its properties
class Ball:public Fl_Box{
//defining private variables
private:
	//Defining x and y coordinates that corresponds to the position of the upper left corner of the object
int x; int y;
//defining public accessible functions
public:
// defining the function to create an instance of the class object
	Ball(int x, int y);

	// a specific function that specify how the object is allowed to move in different scenarios
	void movement(int m);

	// defining a function that will make the object "move" on the screen
	void move(int newX, int newY);

	//defining functions that are getting the coordinates of an object
	int getX();
	int getY();

	//https://bumpyroadtocode.com/2018/04/08/flying-airplane-image-animation-fltk/

	//defining a function that will handle different events
	int handle(int event);

	//defining speed in x and y axis

	double speedY=5;
	double speedX=0;

};


// creating the starting function based on the Fl_Box object, with concrete coordinates, dimensions, color and box style
//20 and 20 as width and height as specified in the project description (that is because radius is 10)
Ball::Ball(int x, int y):Fl_Box(x,y,20,20){
	this-> box(FL_OVAL_BOX);
	this-> color(FL_RED);
	this-> x=x;
	this-> y=y;
	//showing the ball on the screen
	this-> show();
}

//creating the movement function
void Ball::move(int newX, int newY){
    // hide the block
    this->hide();
    // set the new coordinates
    this->x = newX;
    this->y = newY;
    // reposition the block
    this->position(newX, newY);
    // show the block
    this->show();
}


//Getters
//creating the function that returns the x coordinate
int Ball::getX(){
    return this->x;
}

//creating the function that returns the y coordinate
int Ball::getY(){
    return this->y;
}




// creating a function for handling pressing specific keys (FLTK handler for keys)
// this function is not being called in any specific place but is automatically executed when an even occurs
// FLTK handler for keys
int Ball::handle(int event){

    //getting current position of an object
    int currentx=this->getX();
    int currenty=this->getY();

    //an algorithm that will execute different things depending on which key will be pressed
    switch(event){

    case FL_KEYDOWN:
    case FL_KEYUP:// keyboard key released
                {
                	// if
        if(Fl::event_key() == FL_Down){
            // move
            //Fl::add_timeout(1.0, callback);
        	int k= (rand() % 10)-5;
        	speedX=k;
        	this->move((currentx+speedX),currenty+this->speedY);
        	redraw();
            return 1;
            break;
        }
        else if(Fl::event_key() == FL_Up){
        	int k= (rand() % 10)-5;
        	speedX=k;
        	this->move((currentx+speedX),currenty-this->speedY);
        	redraw();
            return 1;
            break;
        }
     //no break
     default: return Fl_Widget::handle(event);
    }
    }
}



#endif /*BALL_H_*/
