//
// Created by Mubina Asadova on 23/04/25.
//

#include "Act1.h"
using namespace std;
using namespace chrono;
using namespace this_thread;
int charisma, dexterity, strength, constitution, intelligence, wisdom;
int Ability_points = 10;
int main() {

    //introduction
    char name[20];
    int type;
    int response;
    sleep_for(milliseconds(100));
    cout<<"Welcome to Heist RPG!"<<endl;
    cout<<"Please, choose a name for yourself."<<endl;
    cout<<"Your name: ";
    cin>>name;
    cout<<"Alright, "<<name<<", let's start the game!"<<endl;
    cout<<"------------------------------------------------------"<<endl;

    //game start, act 1,day 1
    cout<<" DAY 1"<<endl;
    cout<<name<<", you wake up in your messy bedroom in the morning. Sun is shining right through the curtains. Everything stays still as you left the day before.\nYou have not been able to look after your house due to work pressure experienced these recent days. You promised yourself to take a break from your work and go to vacation after finishing your last big project.\nThe day begins as always: you eat cereals for breakfast, change your clothes immediately while thinking on how to hande the project. "<<endl;
cout<<" "<<endl;
    cout<<"Choose a vehicle to go to work:"<<endl;
    cout<<"A.Your car"<<endl;
    cout<<"B.Bus"<<endl;
    cout<<"Vehicle type:"<<endl;
    cin>>type;
    cout<<"Reasonable choice"<<endl;
cout<<" "<<endl;
    cout<<"You are on your way..."<<endl;
cout<<" "<<endl;
    cout<<"You meet your colleagues. David warmly greets you. He apologises for leaving early yesterday without completing project and explains he had something urgent came up.";
cout<<" "<<endl;
    cout<<"Your response will be as:"<<endl;
    cout<<"a.understanding and caring friend"<<endl;
    cout<<"b.selfish and tired of excuses colleague"<<endl;
    cout<<"Your choice:"<<endl;
    cin>>response;
    cout<<response;
    if (response=='a') {
        cout<<"Great. Friends need supporting."<<endl;
    }
      if (response=='b') {
        cout<<"Great. "<<endl;
    }
cout<<" "<<endl;
    cout<<"And now you start working..."<<endl;

    //Minigame

    cout<<"End of the workday"<<endl;
    cout<<" "<<endl;
    cout<<"You are currently not in a relationship. You really like the girl who works at the registration desk."<<endl;
    cout<<"Will you invite her to dinner? (yes or no)"<<endl;
    cin>>response;
    if (response=='yes') {
        cout<<"";
    }
    //charisma check






return 0;
}
