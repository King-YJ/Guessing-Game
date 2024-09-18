#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H
#include <iostream>
using namespace std;
class GuessingGame
{
private:
	string m_user;
protected:
	double m_points = 0;
	string description, welcome = "Welcome To Guessing Game ";
	bool correctGuess = false, exit = false; //
	int proceed = 0, modes = 0;
public:
	GuessingGame(const string user, const double points) : m_user(user), m_points(points) {}; //this is where i stopped
	void display(int choice = 0);
	void introduction(string welcome, string description = "");
	void run();
};
#endif // !GUESSINGGAME