#pragma once
class LivingThing
{
public:
	//Constructors and Destructors
	LivingThing();
	~LivingThing();
	
	//Get and Set Functions
	int getXpos();
	void setXpos(int);
	
	int getYpos();
	void setYpos(int);
	
	int getLife();
	void setLife(int);
	
	int getSpeed();
	void setSpeed(int);

	int getMaxXPos();
	void setMaxXPos(int);
	
	int getMaxYPos();
	void setMaxYPos(int);

	void setFrameWidth(int);
	int getFrameWidth();

	void setFrameHeight(int);
	int getFrameHeight();
	
	//Functions
	virtual void draw() = 0;
	void Update(int Horizontal_Move, int Verticle_Move, int damage);
private:
	//Limiting Variables
	int maxXPos, maxYPos;
	//Animation Variavles
	int frameWidth;
	int frameHeight;
	int life, speed, x_pos, y_pos;
	void UpdatePosition(int &, int&);
};

