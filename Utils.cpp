#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int Utils::getint() //
{
    int value;
    bool isValid = false;

    do {

        // Check if the input is a valid integer
        if (cin >> value) {
            isValid = true;
        }
        else {
            // Clear the input buffer in case of invalid input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Integer, retry: ";
        }

    } while (!isValid);

    // Clear the input buffer after successful input
    std::cin.ignore(1000, '\n');

    return value;
}

int Utils::enterInteger(int choice, int max, int min, const std::string word)
{
    int number = 0;
    bool valid = false;
    if (choice != 0)
        cout << "Enter a whole number(e.g: 1, 2) in the range " << min << " - " << max << " inclusive!" << endl;
    while (!valid)
    {
        cout << word << ": "; //
        number = getint();
        if (number > max || number < min)
        {
            cout << "Error, enter a whole number(e.g: 1, 2) in the range " << min << " - " << max << endl;
        }
        else
        {
            valid = true;
        }
    }
    return number;
}

streampos Utils::extractTillDigit(fstream& file, string& destination, streampos position)
{
    string words;
    int currentPos(static_cast<int>(position));
    if (file.is_open())
    {
        file.seekg(position);
        getline(file, words);
        if (words.empty())
        {
            file.ignore();
            position = file.tellg();
            getline(file, words);
        }
        for (char digit : words)
        {
            if (isdigit(digit))
            {
                break;
            }
            destination += digit;
            currentPos++;
        }
        if (!destination.empty() && destination.back() == ' ')
            destination.pop_back();
        return currentPos;
    }
    else
    {
        return 0;
    }
}

void Utils::appendToFile(fstream& file, string str, string fileName)
{
    if (!fileName.empty())
    {
        file.open(fileName, std::ios::out | std::ios::app);
        if (file.is_open())
        {
            if (str.empty())
            {
                cout << "Nothing to append to the file" << endl;
            }
            else
            {
                file << str << endl;
                file.flush();
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file " << fileName << endl;
        }
    }
    else
    {
        cout << "No file name provided" << endl;
    }
}
