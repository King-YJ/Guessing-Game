#include <iostream>
#include <fstream>
#include <vector>
#include "GuessingGame.h"
#include "Utils.h"
/*
* value - cannot be sent back to its original scope
* address - modifies the original using pointers (*)
* reference - modifies original using pointers(&)
*/

using namespace std;

struct User
{
    string username, password;
    int points = 0;
};

int main(int argc, char* argv[])
{
    Utils ut;
    vector<User> player;
    fstream file;
    string username, password;
    int i(-1), selection(0), points(0);
    bool valid(false);
    do
    {
        i++;
        file.open(argv[i]);
    } while (!file.is_open() && i < argc);
    if (file.is_open())
    {
        while (!file.eof() && file.peek() != EOF) {
            User tempUser;
            file >> tempUser.username >> tempUser.password >> tempUser.points;
            player.push_back(tempUser);
        }
        file.close();
        cout << "Welcome, please select 1 for sign in, or select 2 if you're a new player to sign up." << endl;
        selection = ut.enterInteger(1, 2, 1);
        if (selection == 1)
        {
            while (!valid)
            {
                cout << "Enter your username" << endl;
                cin >> username;
                cin.clear();
                cout << "Enter your password" << endl;
                cin >> password;
                cin.clear();
                for (User check : player)
                {
                    if (username == check.username && password == check.password)
                    {
                        points = check.points;
                        valid = true;
                    }
                }
                if (!valid)
                {
                    cout << "Username not found or password is wrong. Please select 1 to retry or select 2 to sign up as a new user." << endl;
                    selection = ut.enterInteger(1, 2, 1);
                    if (selection == 2)
                        valid = true;
                }
            }
        }
        if (selection == 2)
        {
            valid = false;
            while (!valid)
            {
                cout << "Enter your username(without spaces): ";
                cin >> username;
                cin.clear();
                cout << "Enter your password(without spaces): ";
                cin >> password;
                cin.clear();
                cout << "Username: " << username << " and password: " << password << ". Is this correct?" << endl;
                cout << "1.Yes\n" << "2.No" << endl;
                selection = ut.enterInteger(1, 2, 1);
                if (selection == 1)
                {
                    valid = true;
                    for (User check : player)
                    {
                        if (username == check.username)
                        {
                            cout << "Username already exist!!" << endl;
                            valid = false;
                        }
                    }
                    if (valid)
                    {
                        string str = username + ' ' + password + ' ' + to_string(points);
                        ut.appendToFile(file, str, argv[i]);
                    }
                }
            }
        }
        GuessingGame guess(username, points);
        guess.run();
        file.close();
    }
    else
    {
        cout << "Error opening file" << endl;
    }
    return 0;
}