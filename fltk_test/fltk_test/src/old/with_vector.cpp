/*
 * with_vector.cpp
 *
 *  Created on: 15 lis 2022
 *      Author: admin
 */
/*
 * movement.cpp
 *
 *  Created on: 1 lis 2022
 *      Author: admin
 */

// including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <time.h>
#include <FL/Fl_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Valuator.H>

#include <iostream>
#include <typeinfo>

using namespace std;

//#include <Fl_Timer.H> https://www.fltk.org/doc-1.3/classFl__Timer.html#aada0a137cbc6d1b48720bebd9de4cff5

// including header files with game objects
// header file with a block object
#include "block.h"
//header file with brick object
#include "brick2.h"
//header file with the board object
#include "plank2.h"
//header file with the ball object
#include "ball2.h"

//creating the width and height variables for the game screen
//width
int maxymalnex=640;
//height
int maxymalney=480;


/*NOT WORKING
void callback(void*) {
  printf("TICK\n");
  int k= (rand() % 10)-5;
  cout<<k;
  Fl::repeat_timeout(1.0, callback);    // retrigger timeout
}
*/


template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

// main function in the game
int main(){
	//creating the game screen with specific width and height and giving it background color
	Fl_Window *window = new Fl_Window(maxymalnex, maxymalney);
	window->color(FL_BLACK);


	 /*a code for marking where the score display will be, no functionalities */
	 Fl_Box *score = new Fl_Box(maxymalnex-5-100,5,100,50,"0");
	 //Fl_Valuator* score = new Fl_Valuator(maxymalnex-5-100,5,100,50);
	 score->box(FL_NO_BOX);
	 score->labelsize(20);
	 score->labelfont(FL_BOLD+FL_ITALIC);
	 score->labelcolor(fl_rgb_color(162, 60, 20));

	 /* trying ot display hearts */
	 Fl_Box *heart1= new Fl_Box((maxymalnex/2)+100,5, 40,40);     // widget that will contain image
	 Fl_JPEG_Image jpg("C:/Users/admin/Desktop/Tilburg/serce.jpeg");      // load jpeg image into ram   //https://www.google.com/imgres?imgurl=https%3A%2F%2Fak.picdn.net%2Fshutterstock%2Fvideos%2F1007581117%2Fthumb%2F1.jpg%3Fip%3Dx480&imgrefurl=https%3A%2F%2Fwww.shutterstock.com%2Fvideo%2Fclip-1025057726-shiny-pixel-heart-beat-on-digital-old&tbnid=p8iyItvbZOer1M&vet=12ahUKEwjEl4Kgqaf7AhXJsKQKHdLlD18QMygKegUIARDmAQ..i&docid=xSzYJgVXsceomM&w=480&h=270&q=pixel%20heart%20black%20background&ved=2ahUKEwjEl4Kgqaf7AhXJsKQKHdLlD18QMygKegUIARDmAQ
	 heart1->image(jpg); // attach jpg image to box
	 Fl_Box *heart2= new Fl_Box(300,5, 40,40);     // widget that will contain image
	 heart2->image(jpg); // attach jpg image to box
	 Fl_Box *heart3= new Fl_Box(180,5, 40,40);     // widget that will contain image
	 heart3->image(jpg); // attach jpg image to box


	 /*a code for marking where the timer will be, no functionalities */
	 int labl = 0;
	 string labels =to_string(labl);
	 string napis = "1";
	 Fl_Box *timer = new Fl_Box(5,5,100,50,"00:00");
	 timer->box(FL_UP_BOX);
	 //timer->label(FL_FREE_LABELTYPE, labl);
	 //timer->value(napis);
	 timer->labelsize(20);
	 timer->labelfont(FL_BOLD+FL_ITALIC);

	//creating the plank at the bottom of the screen
	// -100 is to substract the width of the plank from the position of the upper left corner, division is to put it in the center
	//-> -20 is to substract te height of the plank
	Platform *plank = new Platform((maxymalnex-100)/2,maxymalney-20);


	//creating the ball in the (almost) center of the screen
	//-> -10 is to substract the radius of the ball from the position of the upper left corner, division is to put it in the center
	//-> -20-20 is to substract the width of the ball and the plank in order to position the ball on top of the plank at the beginning
	Ball *ball = new Ball(maxymalnex/2-10,maxymalney-20-20);


	//creating bricks that are shown only in the upper part of the screen and starts not directly at the top - leaving space for timer and score
	// creating first brick
	Brick *brick = new Brick(5,60, 14, 4);
	// adding the rest of the bricks
	//brick->draw_all();


	//displaying the game in the window/screen created at the beginning
	window->end();
	window->show();
	//NOT WORKING
	//Fl::add_timeout(1.0, callback);       // set up first timeout
	return Fl::run();
}

