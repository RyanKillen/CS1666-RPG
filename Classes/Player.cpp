#include "../Headers/Player.h"
#include "../Headers/Globals.h"
#include "../Headers/Helper.h"
#include <iostream>
	/*
	int strength = 1;
	int intelligence = 1;
	int dexterity = 1;
	int constitution = 1;
	int faith = 1;
	int currentExprience;
	Inventory inventory
	std::string name;
	*/
	//stores stats
	Player::Player() : Character("Player 1") {}
	Player::Player(std::string n) : Character(n) {}
	Player::Player(std::string n, int s, int i, int d, int c, int f) : Character(n, s,i,d,c,f){
		learnAbility(FIREBALL);
		learnAbility(SUMMON);
		isEnemy = false;

		pixelShiftAmountForAnimationInSpriteSheet = 128;
		numIdleAnimationFrames = 4;
		numRunAnimatonFrames = 7;
		currentFrame = 0;
		timeBetweenIdleAnimations = 120;
		timeBetweenRunAnimations = 100;
		imageIdleResource = "Images/Player/Player_Idle.png";
		imageRunResource = "Images/Player/Player_Run.png";
		Helper helper = Helper();
		textureIdle = helper.loadImage(imageIdleResource.c_str(), gRenderer);
		textureRun = helper.loadImage(imageRunResource.c_str(), gRenderer);
		textureActive = NULL;
		imageWidth = 128;
		imageHeight = 128;
		xPosition = 0; //will need to edit for starting level
		yPosition = 250.0; //will need to edit for starting level
		rectangle = { (int)xPosition, (int)yPosition, imageWidth, imageHeight };
		drawRectangle = { 0, 0, imageWidth, imageHeight };
		speedMax = 150.0;
		acceleration = 2000.0;
	}
	Player::Player(std::string n, std::vector<Attribute> attr) : Character(n, attr) {
		learnAbility(FIREBALL);
		learnAbility(SUMMON);
		isEnemy = false;
	}
	void Player::setAll(std::string n, int s, int i, int d, int c, int f) {
		attributes[STR] = Attribute("Strength", s);
		attributes[INT] = Attribute("Intelligence", i);
		attributes[DEX] = Attribute("Dexerity", d);
		attributes[CON] = Attribute("Constitution", c);
		attributes[FAI] = Attribute("Faith", f);
		name = n;
		isEnemy = false;

	    pixelShiftAmountForAnimationInSpriteSheet = 128;
		numIdleAnimationFrames = 4;
		numRunAnimatonFrames = 7;
		currentFrame = 0;
		timeBetweenIdleAnimations = 120;
		timeBetweenRunAnimations = 100;
		imageIdleResource = "Images/Player/Player_Idle.png";
		imageRunResource = "Images/Player/Player_Run.png";
		Helper helper = Helper();
		textureIdle = helper.loadImage(imageIdleResource.c_str(), gRenderer);
		textureRun = helper.loadImage(imageRunResource.c_str(), gRenderer);
		textureActive = NULL;
		imageWidth = 128;
		imageHeight = 128;
		xPosition = 0; //will need to edit for starting level
		yPosition = 250.0; //will need to edit for starting level
		rectangle = {(int)xPosition, (int)yPosition, imageWidth, imageHeight};
		drawRectangle = { 0, 0, imageWidth, imageHeight };
		speedMax = 150.0;
		acceleration = 2000.0;
	}


	Player::operator std::string() {
		
		std::string s = "Name: " +	name + "\n";
		for (auto i : attributes) {
			s += i.toString() + "\n";
		}
		return s;
		
	}
