/*
 * test.cpp
 *
 *  Created on: 14 paź 2022
 *      Author: admin
 */


#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include "std_lib_facilities.h"

int main() {
	Fl_Window *win = new Fl_Window(640, 480);
	win->color(FL_BLACK);
	Fl_Box * box = new Fl_Box(0,0,60,30);
	box->box(FL_UP_BOX);
	//box->color(c);
	win->show();
	//keep_window_open();
}


