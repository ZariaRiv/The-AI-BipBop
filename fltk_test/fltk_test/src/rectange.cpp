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

//void fl_pie(int x,int y,int w,int h,double a1, double a2);



/*class Box{
private:
   int hardness = 10;
   int positionx;
   int positiony;
   int boxx =40;
   int boxy =40;
   color = colors[hardness];
   }
 * Box(int positionx,int positiony){
 * }
 *
 *
 * if box hit, hardness-=1 and so color also changes
 *
 */

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
}

class Ball{};
/* movement variable
 * speed maybe?
 * radius =
 */

class Platform;
/* bool move_right = false
 * bool move_left = false
 * bool stay = true
 * int positionx
 * int positiony
 * int plankx =100;
 * int planky =20;
 * maybe speed ?
 */


/*  //colors for different hardness of the boxes
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
	*/

int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(640, 480);
  window->color(FL_BLACK);

  Fl_Box *plank = new Fl_Box(280,460,100,20);
  plank->box(FL_UP_BOX); //could be also FLAT_BOX


  Fl_Box *ball = new Fl_Box(320,300,20,20);
  ball->box(FL_OVAL_BOX);  ///could be also OFLAT
  ball->color(FL_RED);


  int maxymalnex = 640;
  int maxymalney = 480/2;
  int brickx =40;
  int bricky =40;
      for (int i=5; i<=(maxymalney-bricky); i+=bricky+5){
    	  for (int j=5; j<=(maxymalnex-brickx); j+=brickx+5){
    		  Fl_Box* brick = new Fl_Box(j,i, 40, 40);
    		  brick->box(FL_UP_BOX);
    		  brick->color(FL_GREEN);
    	  }
      }
  window->end();
  window->show(argc, argv);
  return Fl::run();
}


