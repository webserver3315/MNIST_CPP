#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Map;
class Player
{
public:
    int health;
    int damage;
    int defense;
    int gems=0;
    string race;
    string name;
    string location;


};
class Enemy
{
    public:

    int ehealth;
    int edamage;
    int edefense;
    int echoice;

};
class combat
{
public:
    Map* mapobj;
    int damagedealt;
    Player playerobj;
    Enemy enemeyobj;
    string cchoice;
    string retry;

    void initial()
    {
        cout <<"A wild orc has appeared\n";
        cout <<"What do you do?\n";
        cout <<"---------------------------\n";
        cout <<"|-------------------------|\n";
        cout <<"|----Attack-----Defend----|\n";
        cout <<"|-------------------------|\n";
        cout <<"---------------------------\n";
        cin >>cchoice;
        this->battle();
    }
    void newturn()
    {
        cout <<"The orc is still alive!";
        cout <<"What do you do?";
        cout <<"\n---------------------------\n";
        cout <<"|-------------------------|\n";
        cout <<"|----Attack-----Defend----|\n";
        cout <<"|-------------------------|\n";
        cout <<"---------------------------\n";
        cin >>cchoice;
        this->battle();
    };
    void battle()
    {

        enemeyobj.echoice = rand() % 2;
        if (enemeyobj.echoice= 1)
        {
            if (cchoice=="Attack")
            {
            playerobj.damage;
            enemeyobj.ehealth=enemeyobj.ehealth-playerobj.damage;
            cout <<"You did "<<playerobj.damage<<" points of damge to the enemey.\n";
            if (enemeyobj.ehealth>0)
            {
                playerobj.health=enemeyobj.edamage-playerobj.health;
                cout <<"The enemyattacked you. You now have "<<playerobj.health<<" health";
                if (playerobj.health>0)
                {
                    this->newturn();
                }
                else if (playerobj.health<=0)
                {
                    cout <<playerobj.name<<"was killed\n";
                    cout <<"Game Over";

                }

            }
            else if (enemeyobj.ehealth<=0)
            {
                    cout <<"You have defeated the orc!";
                    if (playerobj.location=="a")
                    {
                        mapobj->relaypointa();
                    }

            }

            }
            else if (cchoice=="Defend")
            {
                damagedealt=enemeyobj.edamage-playerobj.defense;
                playerobj.health=damagedealt-playerobj.health;
                cout <<"You defend but the enemey was able to deal\n";
                cout <<damagedealt<<" points of damage your health is\n";
                cout <<playerobj.health;
                if (playerobj.health>0)
                {
                    this->newturn();
                }
                else if (playerobj.health<=0)
                {
                    cout <<playerobj.name<<"was killed\n";
                    cout <<"Game Over";
                }
            }
        }
        else if (enemeyobj.echoice=2)
        {
            if (cchoice=="Attack")
            {
             damagedealt=enemeyobj.edefense-playerobj.damage;
             enemeyobj.ehealth=enemeyobj.ehealth-damagedealt;
             cout <<"You did "<<damagedealt<<" points of damage to the enemey";
             if (enemeyobj.ehealth>0)
             {
                 this->newturn();
             }
             else if (enemeyobj.ehealth<=0)
             {
                 cout <<"You have defeated the orc!";
                 mapobj->relaypointa();
             }
            }
            else if (cchoice=="Defend")
            {
                cout <<"Both parties defended";
                this->newturn();
            }
        }
    }
    };





class Map
{
    public:
    combat combatobj;
    string mchoice;
    int espawn;
    Player playerobj;
    Enemy enemeyobj;
    void relaypointaespawn()
    {
    playerobj.location=="relaypointa";
    enemeyobj.ehealth = rand() % 50 + 100;
    enemeyobj.edamage = rand() % 50 + 75;
    enemeyobj.edefense = rand() % 50 + 50;
    combatobj.initial();
    }
    void relaypointa()
    {
        cout <<"You have found yourself at the\n";
        cout <<"mouth of a mighty river to the north\n";
        cout <<"What do you want to do?\n";


    }


    void relaypointb()
    {
    playerobj.location=="relaypointb";
    cout << "\n\n%%%%%%%%%%%%%%%%%%%%\n";
    cout << "%                  %\n";
    cout << "%   #Wild North#   %\n";
    cout << "%                  %\n";
    cout << "%%%%%%%%%%%%%%%%%%%%\n\n";
    cout <<"You have entered the wild north this is where your journey starts\n";
    cout <<"What would you like to do\n\n";
    cin >>mchoice;
    if (mchoice=="Travel")
    {
        cout <<"Where would you like to travel?\n";
        cin >>mchoice;
        if (mchoice=="North")
        {

        }
        else if (mchoice=="East")
        {

        }
        else if (mchoice=="South")
        {

        }
        else if (mchoice=="West")
        {
            this->relaypointaespawn();
        }
        else
        {
            cout <<"Invalid command\n\n";
            this->relaypointb();
        }
           }


    }
    void relaypointcespawn()
    {
        playerobj.location=="a";
        enemeyobj.ehealth = rand() % 50 + 100;
        enemeyobj.edamage = rand() % 50 + 75;
        enemeyobj.edefense = rand() % 50 + 50;
        espawn = rand() % 2;
    }
};