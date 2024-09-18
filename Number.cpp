#include "Number.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Utils.h"

void Number::run()
{
	srand(time(0));
    Utils ut;
    welcome = "Welcome to Number Mode\n"; //
    description = "In this mode, you have to guess a number in the range specified below. Everytime you advance to the next level, the range of numbers you have to guess from increases by 2, and you gain a life. Note: Your reward increases as you level up, and you start the game with 3 lives"; //
    introduction(welcome, description); //
    while (proceed == 0)
    {
        life = maxLifes;
        range += 2;
        ++level;
        cout << "Level " << level << endl;
        while (correctTries != maxCorrectTries && life != 0)
        {
            random = (rand() % range);  //
            while (!correctGuess && life != 0)
            {
                ++tries;
                numberGuessed = ut.enterInteger(1, range - 1); //max = 100 and min = 0
                if (numberGuessed == random)
                {
                    correctGuess = true;
                    ++correctTries;
                    cout << "Correct, " << (maxCorrectTries - correctTries) << " more guesses left before you can pass the level." << endl;
                }
                else if (numberGuessed > random)
                {
                    life = life - 1;
                    if (life == 0)
                    {
                        cout << "Too high" << endl;
                        cout << "You have no lives left!" << endl;
                    }
                    else
                    {
                        cout << "Too high, try again!" << endl;
                        cout << "lives left = " << life << endl;
                    }
                }
                else
                {
                    life = life - 1;
                    if (life == 0)
                    {
                        cout << "Too low" << endl;
                        cout << "You have no lives left!" << endl;
                    }
                    else
                    {
                        cout << "Too low, try again!" << endl;
                        cout << "lives left = " << life << endl;
                    }
                }
            }
            correctGuess = false;
        }
        if (life == 0)
        {
            display(1);
            proceed = ut.enterInteger(0, 1); // max = 1 and min = 0
            if (proceed == 1)
            {
                cout << "Game Over !!" << endl;
            }
            else if (proceed == 0)
            {
                range -= 2;
                level = level - 1;
                life = maxLifes;
                correctTries = 0;
            }
        }
        else if (correctTries == maxCorrectTries && life == maxLifes)
        {
            m_points += (0.5 * level);
            display(2);
            //functions for the below redundancy
            proceed = ut.enterInteger(0, 1, 0);
            if (proceed == 1)
            {
                cout << "Congratulations, you guessed the numbers after " << tries << " guesses" << endl;
            }
            else if (proceed == 0)
            {
                cout << "You are going to the next level after " << tries << " guesses" << endl;
                ++maxLifes;
                life = maxLifes;
                correctTries = 0;
            }
        }
        else
        {
            m_points += (0.25 * level);
            display();
            proceed = ut.enterInteger(0, 1, 0);
            if (proceed == 1)
            {
                cout << "Congratulations, you guessed the numbers after " << tries << " guesses" << endl;
            }
            else if (proceed == 0)
            {
                cout << "You are going to the next level after " << tries << " guesses" << endl;
                ++maxLifes;
                life = maxLifes;
                correctTries = 0;
            }
        }
    }
    cout << "You accumulated " << m_points << " points" << endl
        << "See you next time" << endl;
}
