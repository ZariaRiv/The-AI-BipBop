#ifndef TIMER_H_
#define TIMER_H_

// including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <time.h>
#include <FL/Fl_Valuator.H>

#include <sstream>
#include <string.h>

#include <iostream>
#include <typeinfo>

using namespace std;


class Timer: public Fl_Box{
private:


public:
	int number =0;
	Timer();
};

Timer::Timer(): Fl_Box(5,5,100,50, "0"){

	 //Fl_Valuator* score = new Fl_Valuator(5,5,100,50);
	this->box(FL_UP_BOX);
	//timer->label(FL_FREE_LABELTYPE, labl);
	//timer->value(napis);
	this->labelsize(20);
	this->labelfont(FL_BOLD+FL_ITALIC);
	this->show();



};


#endif /* TIMER_H_ */
