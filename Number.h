#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include "GuessingGame.h"
class Number : public GuessingGame
{
private:
	int random = 0, numberGuessed = 0, tries = 0, correctTries = 0, life = 0, level = 0, maxLifes = 3, maxCorrectTries = 3;
	int range = 1;
public:
	Number(const string user, const double points) : GuessingGame(user, points) {};
	void run();
};

#endif // !NUMBER_H
