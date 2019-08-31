/*				Object.h
*				Created: 28/02/2015
*				Last Update: 27/04/2015
*
*				Created by: Felipe Anargyrou
*				E-Mail : anargyrou4@hotmail.com
*/

#ifndef OBJECT_H
#define OBJECT_H
#include "ContentManager.h"
#include "Collision.h"
#include <map>

namespace mDir
{
	enum Direction
	{
		DOWN,
		UP,
		LEFT,
		RIGHT
	};
}

enum Size
{
	LARGE = 30,
	MEDIUM = 20,
	SMALL = 10
};

//Base class for every enemy, missiles and pickups in the game (including player)
class Object
{
public:
	Object();

	//set bLoadRect to true if the object is using an animated sprite sheet
	virtual void load(std::string id, sf::Vector2f position, bool bLoadRect = false);

	//Change texture; Return true if successful false if already changed
	bool changeTexture(std::string id);

	void SetMovement(float x, float y);
	void SetMovement(sf::Vector2f mMovement);

	void SetVelocity(float x, float y);
	void SetVelocity(sf::Vector2f mVelocity);

	//Returns object movement speed
	sf::Vector2f GetVelocity();
	sf::Vector2f GetMovement();

	//Returns object Sprite
	sf::Sprite GetSprite();

	virtual void update(){}
	//This function is for objects that needs to measure time to deal with it's logics
	virtual void update(sf::Time deltaTime){}
	/*
	Function for sprite sheet animation
	deltaTime = time measuring and FPS pattern (Should come all the way from Game base class)
	milliseconds = how fast the animation flows
	width = width of each frame; used to move the animation to the left or to the right in your Sprite Sheet
	height = height of each frame; used to move the animation up or down in your Sprite Sheet (TO BE IMPLEMENTED)
	*/
	void Animate(sf::Time deltaTime, int milliseconds, int width, int height = 0);


	//Set if object is Dead or not
	void setStatus(bool isDead);
	bool getStatus();

	//Return true if animation was completed
	bool waitAnimation(int waitPoint);

	//Return true if Object is outside window
	virtual bool isOffBounds();

	//Deals damage to the object
	void damageObject(int hit = 1);
	//Gets object's current HP
	int getHitPoints();

	void setMaxHitPoints(int hp);
	void explodeObject(sf::Time deltaTime, float scale = 1.f);

	void SetImmunity(float seconds);
	void UpdateImmunity(sf::Time deltaTime, bool bIsFlashing = false);
	bool isImmune();

	Size GetSize();
	void setSize(Size size);
protected:
	//Sets sprite origin relative to the current sprite
	void setCenter();

	sf::Sprite sprite;
	sf::Vector2f velocity; //use velocity for speed increasing
	sf::Vector2f movement; //use movement for every move effect desired
	Size size;
	std::string tID;
	//Holds the ID for the explosion texture
	static std::string explosionID;


	//This variable is for time measuring (To be used with update(sf::Time deltaTime))
	sf::Time lastFrame;
	sf::Time immunityDelay;
	sf::Time immunityEffect;
	float immunityTime;
	
	sf::IntRect rect;

	//Object states
	bool bIsHit;
	bool bIsDead;
	bool bIsExploding;
	bool bIsImmune;
	int hitPoints;
};

class ObjectTexture
{
public:
	void setTexture(int index, std::string id);
	std::string getTexture(int index);
private:
	std::map<int, std::vector<std::string>> texturesID;
};

#endif