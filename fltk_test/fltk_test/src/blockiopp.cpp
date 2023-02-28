/*
 * blockiopp.cpp
 *
 *  Created on: 25 paź 2022
 *      Author: admin
 */

/*
 * rectange.cpp
 *
 *  Created on: 14 paź 2022
 *      Author: admin
 */

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>

//#include "brick.h"


class Block:public Fl_Box{
private:
int x; int y;
public:
	Block(int x, int y);
};
Block::Block(int x, int y): Fl_Box(x,y,40,40){
	this -> box (FL_FLAT_BOX);
	this-> color (FL_BLACK);
	this-> x=x;
	this-> y=y;
	//this-> show();
}


class Brick:Block{
private:
	int hardness = 10;
public:
	Brick(int x, int y);
	void hit();
	//void draw();
};
Brick::Brick(int x, int y):Block(x,y){
	this-> box(FL_UP_BOX);
	this-> color(FL_GREEN);
	//this->x=x;
	//this->y=y;
	//this-> draw();
}

/*
void Brick::draw(){
	  int maxymalnex = 640;
	  int maxymalney = 480/2;
	  int brickx =40;
	  int bricky =40;
	      for (int i=5; i<=(maxymalney-bricky); i+=bricky+5){
	    	  for (int j=5; j<=(maxymalnex-brickx); j+=brickx+5){
	    		  Brick*brick = new Brick(j,i);
	    	  }
	      }
    this-> show();
}
*/

/*
Brick::hit(){
	if Brick (y+40) or Brick (x+40) <= Ball (x or y or x+20 or y+20)
	hardness--;
	color=colors[hardness];
	    //colors for different hardness of the boxes
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

		Fl_Color colors[] ={tenth, nine, eight, seventh,six,fifth,fourth,third,second,first};

} */


class Ball:public Fl_Box{
private:
	int x; int y;
public:
	Ball(int x, int y);
	void movement(int m);
	//{
		// if nothing happens, go down, so this->y-=5;
		//elseif hit the plank, go up this->y+=5;
		//depending on where we hit the plank, this->x changes too
	//}

};

Ball::Ball(int x, int y):Fl_Box(x,y,20,20){
	this-> box(FL_OVAL_BOX);
	this-> color(FL_RED);
	this-> x=x;
	this-> y=y;
	this-> show();
}


class Platform:public Fl_Box{
private:
int x; int y;
public:
Platform(int x, int y);

void movement(int input){
	if(input==FL_Right){
		this->x+=5;
	}
	if(input==FL_Left){
		this->x-=5;
	}
}
};
Platform::Platform(int x, int y): Fl_Box(x,y,100,20){
	this -> box (FL_FLAT_BOX);
	this-> color (FL_WHITE);
	this-> x=x;
	this-> y=y;
	this-> show();
}



int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(640, 480);
  window->color(FL_BLACK);

  Platform *plank = new Platform(280,460);

  Ball *ball = new Ball(320,300);
  //Brick.draw();
  int maxymalnex = 640;
  int maxymalney = 480/2;
  int brickx =40;
  int bricky =40;
      for (int i=5; i<=(maxymalney-bricky); i+=bricky+5){
    	  for (int j=5; j<=(maxymalnex-brickx); j+=brickx+5){
    		  Brick*brick = new Brick(j,i);
    	  }
      }
  //int key = Fl::event_key();
  window->end();
  window->show(argc, argv);
  return Fl::run();
}





