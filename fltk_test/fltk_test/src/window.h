
#ifndef WINDOW_H_
#define WINDOW_H_

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>

// including header files with game objects
// header file with a block object
#include "block.h"
//header file with brick object
#include "plank2.h"
//header file with the ball object
#include "ball2.h"
//header file containing the brick object that is making a vector of blocks
#include "brick_new_v.h"
//header file with the life object
#include "lifes.h"
//header file with the game over display
#include "game_over.h"
//header file with the game end (winning) display
#include "win.h"


//creating the width and height variables for the game screen
//width
int maxymalnex=640;
//height
int maxymalney=480;



class TheWindow : public Fl_Window {
private:
	//creating the ball in the (almost) center of the screen
	//-> -10 is to subtract the radius of the ball from the position of the upper left corner, +4 due to bug fixing, division is to put it in the center
	//-> -20-20 is to subtract the width of the ball and the plank in order to position the ball on top of the plank at the beginning
	Ball *ball = new Ball(maxymalnex/2-10+4,maxymalney-20-20-5);

	//creating the plank at the bottom of the screen
	// -100 is to subtract the width of the plank from the position of the upper left corner, division is to put it in the center
	//-> -20 is to subtract the height of the plank
	Platform *plank = new Platform((maxymalnex-120)/2,maxymalney-20);

	// creating graphics that will represent lives of the player
	Life *heart1 = new Life(180);
	Life *heart2 = new Life(300);
	Life *heart3 = new Life(420);

	//setting the number of lives to three
	int life=3;


	//setting intitial score
	int score =0;
	string scorecount = "Score: " + to_string(score);

	//setting starting time
	int initial_time = 0;
	string timeeeer = to_string(initial_time);

public:
	TheWindow():Fl_Window(maxymalnex, maxymalney){
		Fl::add_timeout(0.5,animate ,(void*)this);
		if(life>0){
		Fl::add_timeout(1.0, timerf, (void*)this);
		}
		this->init_window();
	}
	bool isRunning();
	//callback functions
	static void animate(void *userdata);
	static void timerf(void *userdata);
	// function to bounce from the board
	void plank_bounce();
	//function to make the initial window
	void init_window();
	//function that display lives and deals with finishing the game if all the lives are lost
	void check_lifes();
	// function to deal with the ball-brick collision
	void bounce_bricks();
	//the function to make the game smart
	void smart_movement();

	//creating a score display
	Fl_Box * scorer = new Fl_Box(535,5,100,50, scorecount.c_str());

	//creating bricks that are shown only in the upper part of the screen and starts not directly at the top - leaving space for timer and score
	// defining position of the first brick
	Brick *bricks = new Brick(5,60);

	//create a timer
	Fl_Box * timeer = new Fl_Box(5,5,100,50, timeeeer.c_str());

	// winning and loosing messages (boxes)
	Over*game_over =new Over();
	Win*winning = new Win();
};


void TheWindow:: init_window(){
	TheWindow *screen = this;
	screen->color(FL_BLACK);

	//this->bricks->draw_all();
	this->ball->show();
	this->plank->show();


	this->scorer->box(FL_UP_BOX);
	this->scorer->labelsize(20);
	this->scorer->labelfont(FL_BOLD+FL_ITALIC);
	this->scorer->labelcolor(fl_rgb_color(162, 60, 20));
	this->scorer->show();

	this->timeer->box(FL_UP_BOX);
	this->timeer->labelsize(20);
	this->timeer->labelfont(FL_BOLD+FL_ITALIC);
	this->timeer->show();

	screen->show();
}


void TheWindow::plank_bounce(){
			// of the ball is 40 units above ground (or for some reason slightly below)   -> checking if the paddle is there
			if (this->ball->getY()>=maxymalney-40){
				//if the ball x coordinate is larger than the plank x coordinate (-10) because of the radius of the ball
				// and the ball x coordinate is smaller than the plank x coordinate + it's length minus the radius of the ball
				// that means the ball is hitting the plank and thus the speedY should change to UP
				if(this->ball->getX()>=(this->plank->getX()-10) && (this->ball->getX()<=(this->plank->getX()+110))){
					this->ball->speedY=-this->ball->speedY;
					if ((this->ball->getX()<= this->plank->getX()+14)){
						// going from left to right
						if (this->ball->speedX >= 0){
							this->ball->speedX-=2;   // should calculate 22.5 degrees but the computer crashes when I try to calculate
						}
						//going from right to left or at 90 degrees
						else{
							this->ball->speedX+=2;
						}
					}
					else if ((this->ball->getX()>= this->plank->getX()+86)){
						//going from left to right
						if (this->ball->speedX >= 0){
							this->ball->speedX+=2;
						}
						// going from right to left or at 90 degrees
						else{
							this->ball->speedX-=2;
						}
					}
				}
				else{
					//that means the ball fall on the ground and thus one life is subtracted
					this->life-=1;
					// and reposition ball to the starting position and wait for user input to start the ball movement again
					this->ball->speedY=0;
					this->ball->speedX=0;
					this->ball->move(maxymalnex/2-10, maxymalney-45);

				}
		}
	}

//a function to check how many lives is left and to signalizes it
void TheWindow::check_lifes(){
	// if life is lost for the first time hide the most left heart
	if( this->life == 2){
		heart1->hide();
	}
	//if life is lost for the second time, hide the middle heart
	else if(this->life == 1){
		heart2 -> hide();
	}

	//if the third life is lost, hide the last heart
	else if(this->life <=0){
		heart3 -> hide();
		//stop the game;
		this->ball->hide();
		this->ball->speedY=0;
		this->ball->speedX=0;
		this->plank->hide();
		// display the game over box
		this->game_over-> show();

	}
}

bool TheWindow::isRunning(){
	//moving the ball while the window is running
	this->ball->move(ball->getX()+ball->speedX, ball->getY()+ball->speedY);
	//making sure the ball will bounce from the board and bricks
	this->plank_bounce();
	this->bounce_bricks();
	//displaying correct number of lives
	this->check_lifes();
	//returning true if it's running
	this->smart_movement();
	return true;
}


// a callback function to animate the game
void TheWindow::animate(void *userdata) {
	TheWindow *s = (TheWindow *)userdata;
	// if the window is running repeat all the actions from the window every 0.05
    if (s->isRunning())
     Fl::repeat_timeout(0.05, animate, userdata);

}

// a callback function to increase the timer every second
void TheWindow::timerf(void *userdata) {
	TheWindow *s = (TheWindow *)userdata;
	// if the are any lives left or the player didn't win, increase the timer increment every second
	if (s->life>0   ||  s->score >=560){
		s->initial_time+=1;
	}
	s->timeeeer = to_string(s->initial_time);
    Fl::repeat_timeout(1.0, timerf, userdata);
}

// collision with bricks
void TheWindow::bounce_bricks(){
	// if the ball is in the upper half
	if (this->ball->getY() < 300){
		// go over all the bricks in the brick vector
		for (Block *brick : this->bricks->getBricks()){
			// create boolean to indicate if change of direction is needed
			bool changeX = false;
			bool changeY = false;
			// bottom and top wall
			// if the ball is on the x axis between the starting point of the brick and the ending point of the brick
			if (this->ball->getX()<=((brick->getX())+42) && this->ball->getX()>=brick->getX()-12){
				//check if the ball is touching the corner or is already inside the brick
				//for touching the bottom                    and the upper wall
				if ( (this->ball->getY()<=brick->getY()+42 && this->ball->getY()>=brick->getY()+38) || (this->ball->getY()+20>=brick->getY()-2  &&  this->ball->getY()+20<=brick->getY()+2) ){
					changeY = true;
				}
				// part of the ball is already inside and part is outside, which means it missed the border - case for going from below the brick
				if ((this->ball->getY()< brick->getY()+45) && ((this->ball->getY()+10) > (brick->getY()+45))){
					changeY = true;
				}
				// part of the ball is already inside and part is outside, which means it missed the border - case for going from above the brick
				if ((this->ball->getY()+20>brick->getY()) && ((this->ball->getY()<brick->getY()))){
					changeY = true;
				}
			}
			// right and left wall
			if (this->ball->getY()<=brick->getY()+42 && this->ball->getY()+12>=brick->getY()){

				if ( (this->ball->getX()<=brick->getX()+42 && this->ball->getX()>=brick->getX()+38) || (this->ball->getX()+20>=brick->getX()-2  &&  this->ball->getX()+20<=brick->getX()+2) ){
					changeX = true;
				}
				// part of the ball is already inside and part is outside, which means it missed the border - case for going from right
				if ((this->ball->getX()<(brick->getX())+45) && ((this->ball->getX()+20>(brick->getX())+45))){
					changeX = true;

				}
				// part of the ball is already inside and part is outside, which means it missed the border - case for going from left
				if ((this->ball->getX()+20>(brick->getX())) && ((this->ball->getX()<(brick->getX())))){
					changeX = true;
				}
			}
			// if the booleans for change are true change the speed how specified
			if (changeX || changeY){
				if(changeX){
					this->ball->speedX=-this->ball->speedX;

				}
				if(changeY){
					this->ball->speedY=-this->ball->speedY;
				}
			//change the score and hit an adequate brick
			brick->hit();
			this->score+=1;
			this->scorecount= "Score: " + to_string(score);

			//if all the bricks are destroyed, the player wins
			if (score>=560){
				//stop the game
				this->ball->hide();
				this->ball->speedY=0;
				this->ball->speedX=0;
				this->plank->hide();
				// display the winning message
				this->winning-> show();

			}
			break;
			}

		}
	}
}

// function that imitates player action, it is not design to win the game but it will not let the ball fall on the ground and thus not lose the game
void TheWindow::smart_movement(){
	// how to start a game
	if (this->ball->speedY == 0 && life>0){
		this->ball->speedY=-5;
		this->ball->speedX=2.1;
	}
	// calculate if the ball is outside the plank, to its right
	int differnece_right = (this->plank->getX()+100) - (this -> ball->getX());
	//if yes, move the plank to the right
	if( differnece_right < 0){
		int oldX =  this->plank->getX();
		int oldY = this->plank->getY();
		this->plank->move(oldX+15, oldY);
	}
	// check if the ball is outside the plank but on the left
	int differnece_left = (this->plank->getX()) - (this -> ball->getX());
	//if yes, move plank to the left
	if( differnece_left > 0){
		int oldX =  this->plank->getX();
		int oldY = this->plank->getY();
		this->plank->move(oldX-15, oldY);
	}

}

#endif /* WINDOW_H_ */
