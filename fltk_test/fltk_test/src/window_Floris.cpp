//header file with the window
#include "window.h"

//header file with the timer
#include "timer.h"

int main(){
	TheWindow *window= new TheWindow();
	//displaying the game in the window/screen created at the beginning
		window->end();
		window->show();
		return Fl::run();
}




