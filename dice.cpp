// dice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using std::cin;
using std::cout;

void throw_it(int num);


int main()
{
    int min{ 1 }, max{ 6 }, num_of_turns{ 4 }, score_pl{ 0 }, score_opp{ 0 };
    bool player_first{ 0 };
    char ready{ '0' };
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    int num = dist(rng);
    cout << "Let's play a game. Enter 'y' to begin. \n";
    cin >> ready;
    while (ready != 'y')
    {
        cout << "Ok, just tell me when you are ready by entering 'y'. \n";
        cin >> ready;
    }
    if (num < 4)
    {
        cout << "You go first. \n";
        player_first = 1;
    }
    else
    {
        cout << "I go first.";
    }

    ready = 'n';

    for (auto i{0}; i < num_of_turns; ++i)
    {
        if (player_first)
        {
            do
            {
                cout << "Enter 'y' to throw the die. \n";
                cin >> ready;
            } while (ready != 'y');
            num = dist(rng);
            cout << num << "\t";
            score_pl += num;
            throw_it(num);
            cout << "Your current score is: " << score_pl << ".\n";
            num = dist(rng);
            cout << num << "\t";
            score_opp += num;
            throw_it(num);
            cout << "My current score is: " << score_opp << ".\n";
            ready = 'n';
        }
        else
        {
            num = dist(rng);
            score_opp += num;
            throw_it(num);
            cout << "My current score is: " << score_opp << ".\n";
            do
            {
                cout << "Enter 'y' to throw the die. \n";
                cin >> ready;
            } while (ready != 'y');
            num = dist(rng);
            cout << num << "\t";
            score_pl += num;
            throw_it(num);
            cout << "Your current score is: " << score_pl << ".\n";
            ready = 'n';
        }
    }
    
    
    
    cout << "Ok, your final score is: "<<score_pl<<".\nMy final score is: "<<score_opp<<".\n";
    if (score_pl > score_opp) cout << "Congratulations, you won!\n";
    else if (score_opp > score_pl) cout << "I'm sorry, but you lost.\n";
    else cout << "It's a draw.\n";
    

}

void throw_it(int num)
{
    cout << " \n";
    char pic[3][3]{ ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', ' ' };
    switch (num) {
    case 1:
    {
        pic[1][1] = 'X';
        break;
    }
    case 2:
        pic[1][0] = 'X';
        pic[1][2] = 'X';
        break;
    case 3:
        pic[0][0] = 'X';
        pic[1][1] = 'X';
        pic[2][2] = 'X';
        break;
    case 4:
        pic[0][0] = 'X';
        pic[0][2] = 'X';
        pic[2][0] = 'X';
        pic[2][2] = 'X';
        break;
    case 5:
        pic[0][0] = 'X';
        pic[0][2] = 'X';
        pic[2][0] = 'X';
        pic[2][2] = 'X';
        pic[1][1] = 'X';
        break;
    default:
        pic[0][0] = 'X';
        pic[0][2] = 'X';
        pic[2][0] = 'X';
        pic[2][2] = 'X';
        pic[1][0] = 'X';
        pic[1][2] = 'X';
        
    }

    for (auto i{ 0 }; i < 3; ++i)
    {
        for (auto j{ 0 }; j < 3; ++j)
        {
            cout << pic[i][j] << " ";
        }
        cout << "\n";
    }
    cout << " \n";
}

