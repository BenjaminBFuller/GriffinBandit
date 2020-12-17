//
// Benjamin Fuller's
// Griffin Bandit
//

#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void wait(int sec)
{this_thread::sleep_for(chrono::seconds(sec));}

void ellipse()
{
    wait(1);cout << ".";
    wait(1);cout << ".";
    wait(1);cout << "." << endl;
    wait(1);
}

void space()
{
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

int main()
{
    srand(time(NULL));
    char userChoice;
    int n = 1;
    int milesTrav = 0;
    int thirst = 0;
    int fatigue = 0;
    int water = 3;
    int enemyTrav = -25;
    int enemyBehind = milesTrav - enemyTrav;
    int run = 0;
    int walk = 0;
    int border = rand()%101+100;    // initializes "border" at value (100-200)
    int howFar = border;
    bool tryAgain = true;
    
    // Introduction ------------------------------------------------------------------
    
    cout << "Come on, dude"; ellipse(); cout << endl;
    cout << "You stole a fricking Griffin"; ellipse(); cout << endl;
    cout << "From the Queen of Scandanavia." << endl;
    wait(3); cout << endl;
    cout << "I guess we'll call you"; ellipse();
    cout << "-------------------------" << endl;
    cout << "|--------THE------------|" << endl;
    cout << "|--------GRIFFIN--------|" << endl;
    cout << "|--------BANDIT---------|" << endl;
    cout << "-------------------------" << endl;
    wait(2);
    cout << "(P.S. ";
    wait(2);
    cout << "The Queen's Army is on our tails.)" << endl;
    wait(1); cout << "." << endl;
    wait(1); cout << "." << endl;
    wait(1); cout << "." << endl;
    wait(1);
    cout << "We have to make it to the border before we are caught and dealt with." << endl;
    wait(2);
    
    // Introduction ------------------------------------------------------------------
    
    cout << "We are " << border << " miles away from the border." << endl << endl;
    wait(2);
    for (int count = 1; count == count; count++) // infinite day loop; the purpose is to end the game when you one of the scenarios occurs, not by reaching a certain day
    {
        do
        {
            cout << "What should we do next?" << endl;
            wait(2);
            cout << "---------------------" << endl;
            cout << "| a : Run           |" << endl;
            cout << "| b : Walk          |" << endl;
            cout << "| c : Rest          |" << endl;
            cout << "| d : Drink         |" << endl;
            cout << "| e : Check status  |" << endl;
            cout << "---------------------" << endl;
            cout << "| " << setw(10) << left << "Fatigue : ";     // Visual Fatigue counter
            for (int n = 0; n < fatigue; n++)
                {cout << "X ";}
            cout << setw(9-(2*fatigue)) << right << "|";
            cout << endl;
            cout << "| " << setw(10) << left << " Thirst : ";     // Visual Thirst counter
            for (int n = 0; n < thirst; n++)
                {cout << "X ";}
            cout << setw(9-(2*thirst)) << right << "|";
            cout << endl;
            cout << "| " << setw(10) << left << "  Water : ";     // Visual Water counter
            for (int n = 0; n < water; n++)
            {cout << "X ";}
            cout << setw(9-(2*water)) << right << "|";
            cout << endl;
            cout << "---------------------" << endl;
            wait(1);
            cout << "Type your answer: ";
            cin >> userChoice;
            // -----------------------------------------------Switch Statement : User's choice------------------------------------------------------------
  
            switch (userChoice)
            {
                case 'a':
                    tryAgain = true;
                    run = rand()%13+13; // initializes "run" at value (13-25)
                    cout << endl;
                    cout << "You chose to run" << endl;
                    ellipse();
                    cout << "You ran " << run << " miles with the Griffin." << endl;
                    fatigue ++;
                    thirst ++;
                    milesTrav += run;
                    border -= milesTrav;
                    wait(1);
                    cout << "You have traveled " << milesTrav << " miles." << endl;
                    wait(1);
                    break;
                case 'b':
                    tryAgain = true;
                    walk = rand()%8+5; // initializes "walk" at value (5-12)
                    cout << endl;
                    cout << "You chose to walk" << endl;
                    ellipse();
                    cout << "You walked " << walk << " miles with the Griffin." << endl;
                    thirst++;
                    milesTrav += walk;
                    border -= milesTrav;
                    wait(2);
                    cout << "You have traveled " << milesTrav << " miles." << endl;
                    wait(2);
                    break;
                case 'c':
                    if (fatigue == 0)
                    {
                        tryAgain = false;
                        wait(1);
                        cout << endl;
                        cout << "You do not feel tired enough to rest." << endl;
                        wait(1);
                        cout << "Try a different choice." << endl;
                        wait(1);
                    }
                    else
                    {
                        tryAgain = true;
                        cout << endl;
                        cout << "You chose to rest" << endl;
                        ellipse();
                        cout << "You now feel more refreshed." << endl;
                        fatigue --;
                        if (fatigue < 0)
                            fatigue = 0;
                        wait(1);
                        cout << "Let's make a move." << endl;
                        wait(1);
                    }
                    break;
                case 'd':
                    if (thirst == 0)
                    {
                        tryAgain = false;
                        wait(1);
                        cout << endl;
                        cout << "You do not feel thirsty." << endl;
                        wait(1);
                        cout << "Try a different choice." << endl;
                        wait(1);
                    }
                    else
                    {
                        tryAgain = true;
                        cout << endl;
                        cout << "You drank from your waterskin" << endl;
                        thirst--;
                        water--;
                        wait(1);
                    }
                    break;
                case 'e':
                    tryAgain = false;
                    wait(1);
                    cout << endl;
                    cout << "You are " << border << " miles away from the border." << endl;
                    wait(2);
                    enemyBehind = milesTrav - enemyTrav;
                    cout << "The Queen's men are " << enemyBehind << " miles behind us." << endl;
                    wait(2);
                    cout << "Let's make a move." << endl;
                    wait(1);
            }
            // -------------------------------------------------------------------------------------------------------------------------------------------
            if (fatigue > 4)
            {
                cout << endl;
                cout << "You passed out from fatigue." << endl;
                wait(1);
                cout << "-----------" << endl;
                cout << "|--GAME---|" << endl;
                cout << "|--OVER.--|" << endl;
                cout << "-----------" << endl;
                return 0;
            }
            
            if (thirst > 4)
            {
                cout << endl;
                cout << "You died of thirst." << endl;
                wait(1);
                cout << "-----------" << endl;
                cout << "|--GAME---|" << endl;
                cout << "|--OVER.--|" << endl;
                cout << "-----------" << endl;
                return 0;
            }
            
            if (n % 3 != 0)
                enemyBehind += rand()%16+10; // (enemy travels 10-25 miles per turn but rests on every 3rd turn)
            else if (n != 0 & n % 3 == 0)
            {
                cout << endl;
                cout << "I've gotten word that the men are taking a rest";
                ellipse();
                cout << "for now." << endl;
                wait(2);
            }
            
            if (enemyTrav >= milesTrav)
            {
                cout << endl;
                cout << "The men have caught us"; ellipse();
                cout << "I'm sorry,"; wait(2); cout << " but it's over." << endl;
                wait(1);
                cout << "-----------" << endl;
                cout << "|--GAME---|" << endl;
                cout << "|--OVER.--|" << endl;
                cout << "-----------" << endl;
                return 0;
            }
            
            if (milesTrav >= howFar)
            {
                cout << endl;
                cout << "Wait"; ellipse(); wait(1);
                cout << "Do you see that?" << endl;
                wait(2);
                cout << "We've made it to the border!" << endl;
                wait(1);
                cout << "----------" << endl;
                cout << "|--YOU---|" << endl;
                cout << "|--WIN!--|" << endl;
                cout << "----------" << endl;
                return 0;
            }
            //--------This is the turn tracker; n represents turns and only increments under certain user choices-------
            if (tryAgain == true)
                n++;
            //----------------------------------------------------------------------------------------------------------
            tryAgain = false; // End of day scenarios: tells do/while loop to start over
        } while (tryAgain == false);
    }
    wait(1);
    
    return 0;
}
