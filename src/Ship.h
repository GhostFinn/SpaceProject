/*				Ship.h
*				Created: 07/03/2015
*				Last Update: 07/04/2015
*
*				Created by: Felipe Anargyrou
*				E-Mail : anargyrou4@hotmail.com
*/

#ifndef SHIP_H
#define SHIP_H
#include "Object.h"

class Ship : public Object
{
public:
	Ship();
	void updateMissiles();
	
	std::vector<sf::Sprite> GetMissiles();
	sf::Sprite getMissileSprite(int index);
	void destroyMissile(int index);
	void setMaxSpeed(float speed);
protected:
	void fireMissile(std::string texture, mDir::Direction dir = mDir::Direction::UP);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Stop();

	sf::Time fireDelay;

	std::vector<sf::Sprite> missiles;

	float maxSpeed;
};
#endif