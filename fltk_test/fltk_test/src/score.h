#ifndef SCORE_H_
#define SCORE_H_

// including necessary libraries
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <time.h>
#include <FL/Fl_Valuator.H>

#include <iostream>
#include <typeinfo>

using namespace std;


class Score: public Fl_Box{

public:
Score();
int score =0;
void update();
};

Score::Score(): Fl_Box(535,5,100,50,"0"){
	 /*a code for marking where the score display will be, no functionalities */
	 //Fl_Valuator* score = new Fl_Valuator(maxymalnex-5-100,5,100,50);
	 this->box(FL_NO_BOX);
	 this->labelsize(20);
	 this->labelfont(FL_BOLD+FL_ITALIC);
	 this->labelcolor(fl_rgb_color(162, 60, 20));
	this->show();
};

void Score::update(){
	this->score+=1;
	std::string str = std::to_string(score);
	char const *c = str.data();
    this->label(c);
}


#endif /* SCORE_H_ */
