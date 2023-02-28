
#ifndef LIFE_H_
#define LIFE_H_

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


Fl_JPEG_Image jpg("serce.jpeg");      // load jpeg image into ram   //https://www.google.com/imgres?imgurl=https%3A%2F%2Fak.picdn.net%2Fshutterstock%2Fvideos%2F1007581117%2Fthumb%2F1.jpg%3Fip%3Dx480&imgrefurl=https%3A%2F%2Fwww.shutterstock.com%2Fvideo%2Fclip-1025057726-shiny-pixel-heart-beat-on-digital-old&tbnid=p8iyItvbZOer1M&vet=12ahUKEwjEl4Kgqaf7AhXJsKQKHdLlD18QMygKegUIARDmAQ..i&docid=xSzYJgVXsceomM&w=480&h=270&q=pixel%20heart%20black%20background&ved=2ahUKEwjEl4Kgqaf7AhXJsKQKHdLlD18QMygKegUIARDmAQ


class Life: public Fl_Box{
private:
int x;

public:
Life(int x);
};

Life::Life(int x): Fl_Box(x,5,40,40){
	this-> x=x;
	this->image(jpg); // attach jpg image to box
	this->show();
}


#endif /* LIFE_H_ */
