#ifndef OVER_H_
#define OVER_H_

// including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <time.h>
#include <FL/Fl_Valuator.H>

using namespace std;


class Over: public Fl_Box{
public:
	Over();
};

Over::Over(): Fl_Box(280,270,100,50,"GAME OVER"){
	 /*a code for displaying that the game is over */
	this->box(FL_NO_BOX);
	this->labelsize(40);
	this->labelfont(FL_BOLD+FL_ITALIC);
	this->labelcolor(fl_rgb_color(162, 60, 20));
	this->hide();
};


#endif /* OVER_H_ */
