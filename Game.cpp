#include <iostream>
#include<string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "Act1.cpp"
#include "Act2.cpp"
#include "Act_3.cpp"
using namespace std;
using namespace chrono;
using namespace this_thread;
using namespace Act1;
using namespace Act2;
using namespace Act_3;
//Strength - 0; Dexterity - 1; Constitution - 2; Intelligence - 3; Wisdom - 4; Charisma - 5;
int Ability_scores[6] = {10,10,10,10,10,10}
int Ability_Points = 10;

int main(){
    int play_exit;
    do {
        cout<<"\t\t\t-------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t|\t\t\t\t\t\tWelcome to the Heist RPG!\t\t\t\t\t\t|"<<endl;
        cout<<"\t\t\t|\t\t\t\t\t\t\t\t1. PLAY\t\t\t\t\t\t\t\t\t|"<<endl;
        cout<<"\t\t\t|\t\t\t\t\t\t\t\t2. EXIT\t\t\t\t\t\t\t\t\t|"<<endl;
        cout<<"\t\t\t-------------------------------------------------------------------------"<<endl;
        cout<<"Your choice: ";
        cin>>play_exit;
        if(play_exit == 1) {
            break;
        }
        if(play_exit == 2) {
            cout<<"Well, Okay. You know better.\nBye!";
            return 0;
        }
    }while(play_exit !=1 or play_exit !=2);
    Act1::Act1_Day1();
    Act1::Act1_Day2();
    Act1::Act1_Day3();
    Act2::act2_day1();
    Act2::act2_day2();
    Act2::act2_day3();
    Act_3::Act3_day1();
    Act_3::Act3_day2();
    Act_3::Act3_day3();


}