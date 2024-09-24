#include "GuessingGame.h"
#include <iostream>
#include "Utils.h"
#include "Number.h"
using namespace std;
Utils ut;
void GuessingGame::display(int choice)
{
    if (choice == 3) //
    {
        cout << "Select Gaming mode " << endl
            << "Number = 1 , Word = 2 , Countries = 3, Exit = 0" << endl;
    }
    else //
    {
        if (choice == 1)
        {
            cout << "You failed !" << endl;
        }
        else if (choice == 2)
        {
            cout << "Congratulations, you won in one go" << endl;
        }
        else
        {
            cout << "You won" << endl;
        }
        cout << "Do you want to continue ? (yes = 0, no = 1)" << endl;
    }
}

void GuessingGame::introduction(std::string welcome, std::string description)
{
    if (description.empty())
    {
        cout << welcome << m_user << endl;
    }
    else
    {
        cout << welcome << m_user << '\n' << description << endl;
    }
}

void GuessingGame::run()
{
    Number number(m_user, m_points);
    introduction(welcome);
    while (!exit) //
    {
        display(3); //
        modes = ut.enterInteger(0, 3, 0, "choice"); //
        if (modes == 1)
        {
            number.run();
        }
        else if (modes == 2)
        {
            cout << "In development" << endl;
        }
        else if (modes == 3)
        {
            cout << "Not yet available" << endl;
        }
        else if (modes == 0) //
        {
            exit = true;
            cout << "Thank you for playing the game " << m_user <<". We hope you enjoyed the game.See you next time!" << endl;
        }
    }
}
