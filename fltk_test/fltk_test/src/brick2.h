
#ifndef BRICK_H_
#define BRICK_H_

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
// including header files with an object class
#include "block.h"

// including necessary libraries
#include <iostream>
#include <vector>
using namespace std;



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


class Brick: public Fl_Box{
private:
int x; int y;
int hardness = 9;
// the number of row and column
int row;
int column;

// Brick's body
vector<Block*> body;

public:
Brick(int x, int y, int row, int column);
	void move(int newX, int newY);
	int getX();
	int getY();
	void hit();
	void draw();
};

Brick::Brick(int x, int y, int row, int column): Fl_Box(x,y,40,40){
	this-> box(FL_UP_BOX);
	this-> color(FL_GREEN);
	this-> x=x;
	this-> y=y;
	// Rows and Columns
	this->column = column;
	this->row = row;
	//this-> show();
	// draw the bricks
	this->draw();
	this -> color(colors[hardness]);
}


void Brick::draw(){
    // draw the bricks
    int i, j;
    for(i=0; i<=this->row; i+=45){
        for(j=0; j<=this->column; j+=45){
            Block *bodySeg = new Block((this->x)+i, (this->y)+j);
            // Type of the brick
            bodySeg->box(FL_ENGRAVED_BOX);
            // Color of the brick
            bodySeg->color(colors[hardness]);
            // push_back()
            this->body.push_back(bodySeg);
            this->show();
        }
    }
    //show the bricks
    this->show();


}

void Brick::move(int newX, int newY){
	this -> hide();
	this -> x=newX;
	this -> y=newY;
	this->position(newX,newY);
	this->show();
}

int Brick::getX(){
	return this->x;
}
int Brick::getY(){
	return this->y;
}


#endif /* BRICK_H_ */
