//
// Created by Mubina Asadova on 23/04/25.
//

#include "Act2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "Act1.cpp"
using namespace std;
using namespace chrono;
using namespace this_thread;



void printStats(const Player& p);
void goToLibrary(Player& player);
void goToGym(Player& player);
void act2_day1(Player& player);
void act2_day2(Player& player);

void printStats(const Player& p) {
    sleep_for(milliseconds(100));
    cout << "Player Stats:\n"
         << "Strength: " << p.Strength << "\n"
         << "Dexterity: " << p.Dexterity << "\n"
         << "Constitution: " << p.Constitution << "\n"
         << "Intelligence: " << p.Intelligence << "\n"
         << "Wisdom: " << p.Wisdom << "\n"
         << "Charisma: " << p.Charisma << "\n\n";
}

void goToLibrary(Player& player) {
    string book;
    cout << "Which book do you want to read? ";
    cin.ignore();
    getline(cin, book);

    sleep_for(milliseconds(100));
    cout << "You enjoy reading \"" << book << "\" and gain knowledge.\n";
    player.Intelligence += 1;
    cout << "+1 Intelligence\n";
    cout << "Your Intelligence: " << player.Intelligence << "\n";
}

void goToGym(Player& player) {
    string workout;
    sleep_for(milliseconds(100));
    cout << "\nYou head to the gym.\nWhat do you want to do? (lift / run): ";
    cin >> workout;

    if (workout == "lift") {
        player.Strength += 1;
        cout << "You lift heavy weights and feel your power grow.\n";
        cout << "+1 Strength\n";
        cout << "Your Strength: " << player.Strength << "\n";
    } else if (workout == "run") {
        player.Dexterity += 1;
        cout << "You run laps and feel quicker on your feet.\n";
        cout << "+1 Dexterity\n";
        cout << "Your Dexterity: " << player.Dexterity << "\n";
    } else {
        cout << "You just stand around unsure of what to do.\n";
    }
}


void act2_day1(Player& player) {
    sleep_for(milliseconds(100));
    cout << "Day 1:\n";
    sleep_for(milliseconds(100));
    cout<<"\t\t\tYou wake up on a mattress so thin you can feel every crack in the concrete beneath it.\n";
    sleep_for(milliseconds(100));
    cout << "\t\t\t\t The air is stale, heavy with bleach and something metallic, like rusted hope.\n";
    sleep_for(milliseconds(100));
    cout << "\tA weak strip of light buzzes overhead, and for a second, you forget where you are—until the silence reminds you.\n";
    sleep_for(milliseconds(100));
    cout << "\nA tray is slid through the slot. You're told you can choose today’s breakfast: cereal or toast.\n";


    string breakfast1;
    cout << "Choose your breakfast: (cereal / toast): ";
    cin >> breakfast1;
    while (breakfast1 != "cereal" && breakfast1 != "toast") {
        cout << "Invalid option. Please choose either 'cereal' or 'toast': ";
        cin >> breakfast1;
    }

    cout << "You chose: " << breakfast1 << endl;

    sleep_for(milliseconds(100));
    cout << "\nYou unwrap the foil. It’s plain cereal. It was always going to be cereal.\n";
    cout << "Maybe the toast machine's been broken since the '90s.\n";

    string location;
    cout << "Where do you want to go? (yard/library): ";
    cin >> location;
    while (location != "yard" && location != "library") {
        cout << "Invalid option. Please choose either 'yard' or 'library': ";
        cin >> location;
    }

    cout << "You are going to the " << location << endl;


    if (location == "library") {
        goToLibrary(player);
        return;
    }

    else if (location == "yard") {
        sleep_for(milliseconds(100));
        cout << "\n\t\tYou step out into the yard, the morning sun casting long shadows over the uneven ground.\n";
        cout<<"\t\t  A few people mill about—some sharpening tools, others speaking in low, guarded tones. \n";
        cout<<"You approach a small group, nodding in greeting, and begin to ask carefully worded questions about those who aren’t present,\n";
        cout<<"  watching their faces for the flicker of recognition or hesitation that might tell you more than their words ever could.\n";
        string choice;
        cout << "\nA big guy insults you. Do you want to fight him? (yes/no): ";
        cin >> choice;

        if (choice == "no") {
            sleep_for(milliseconds(100));
            cout << "You avoid the fight and head to the library.\n";
            goToLibrary(player);
            return;
        }

        if (choice == "yes") {
            string style;
            sleep_for(milliseconds(100));
            cout << "\nHow do you want to fight? (strength/dexterity):\n";
            cout << "Your Strength: " << player.Strength << "\n";
            cout << "Your Dexterity: " << player.Dexterity << "\n";
            cout << "Enter choice: ";
            cin >> style;

            if (style == "strength") {
                string action;
                sleep_for(milliseconds(100));
                cout << "How will you fight? (punch / grab): ";
                cin >> action;

                if (action == "punch" || action == "grab") {
                    if (player.Strength >= 12) {
                        sleep_for(milliseconds(100));
                        cout << "You " << action << " your opponent and win the fight.\n";
                        player.reputation += 1;
                        cout << "Your Reputation increases!\n";

                        if (player.Charisma >= 7) {
                            sleep_for(milliseconds(100));
                            cout << "You explain it to the guards and walk away clean.\n";
                        } else {
                            cout << "The guards don’t believe you. You’re sent to isolation.\n";
                            player.inIsolation = true;
                        }
                    } else {
                        cout << "You tried to " << action << ", but weren’t strong enough. You got injured.\n";
                        player.injured = true;
                    }
                } else {
                    cout << "You hesitated and got injured.\n";
                    player.injured = true;
                }
            }

            else if (style == "dexterity") {
                string action;
                sleep_for(milliseconds(100));
                cout << "How will you fight? (dodge / trip): ";
                cin >> action;

                if (action == "dodge" || action == "trip") {
                    if (player.Dexterity >= 8) {
                        sleep_for(milliseconds(100));
                        cout << "You " << action << " your opponent and win the fight.\n";
                        player.reputation += 1;
                        cout << "Your Reputation increases!\n";

                        if (player.Charisma >= 7) {
                            sleep_for(milliseconds(100));
                            cout << "You smooth-talk the guards and avoid trouble.\n";
                        } else {
                            cout << "The guards are suspicious. You’re sent to isolation.\n";
                            player.inIsolation = true;
                        }
                    } else {
                        cout << "You failed to " << action << " properly. You got injured.\n";
                        player.injured = true;
                    }
                } else {
                    cout << "Wrong move. You slipped and got injured.\n";
                    player.injured = true;
                }
            }

            else {
                cout << "You froze and didn’t choose properly. You got injured.\n";
                player.injured = true;
            }
        }
    }

    else {
        cout << "Invalid location. You wander around doing nothing.\n";
    }
}

void act2_day2(Player& player) {
    sleep_for(milliseconds(100));
    cout<<"Day 2:\n";
    cout <<"\t\t\t You wake to the sound of boots echoing down the hall, \n";
    cout<<"each step sharp and deliberate, reverberating through the stillness of the early morning.\n";

    sleep_for(milliseconds(100));
    cout << "\nThe guard offers a cheerful, \"Pancakes or porridge today?\"\n";

    string breakfast2;
    cout << "Choose your breakfast: (pancakes / porridge): ";
    cin >> breakfast2;
    while (breakfast2 != "pancakes" && breakfast2 != "porridge") {
        cout << "Invalid option. Please choose one of them: ";
        cin >> breakfast2;
    }

    cout << "You chose: " << breakfast2 << endl;

    sleep_for(milliseconds(100));
    cout << "\nYou lift the lid. It's porridge. Cold, lumpy, and familiar.\n";
    cout << "You wonder if pancakes were ever really on the table.\n";


    sleep_for(milliseconds(100));
    cout << "\nA clipboard is passed around, asking if you'd like 'yard time' or 'room rest'.\n";
    cout << "You tick a box. Doesn’t matter.\n";

    string fakeChoice;
    cout << "Choose your preference: (yard / room): ";
    cin >> fakeChoice;
    while (fakeChoice != "yard" && fakeChoice != "room") {
        cout << "Invalid option. You can go either to the yard or the room: ";
        cin >> fakeChoice;
    }

    cout << "You chose: " << fakeChoice << endl;

    sleep_for(milliseconds(100));
    cout << "\nThe guards glance at your form, then bark, \"Everyone out.\"\n";
    cout << "So, like yesterday, you’re in the yard. The box you checked probably ended up in a shredder. And you're thinking how will your day be.\n";


    string firstLocation;
    sleep_for(milliseconds(100));
    cout << "\nWhere do you want to go after the yard? (gym / library): ";
    cin >> firstLocation;

    const char *secondLocation;

    if (firstLocation == "gym") {
        goToGym(player);
        secondLocation = "library";
    } else if (firstLocation == "library") {
        goToLibrary(player);
        secondLocation = "gym";
    } else {
        sleep_for(milliseconds(100));
        cout << "You waste time doing nothing.\n";
        cout << "After lunch, you still feel unproductive and end up doing nothing again.\n";
        return;
    }

    sleep_for(milliseconds(100));
    cout << "\nAfter lunch, it's time for your second activity. You go to the " << secondLocation << ".\n";

    if (secondLocation == "gym") {
        goToGym(player);
    } else if (secondLocation == "library") {
        goToLibrary(player);
    }

    sleep_for(milliseconds(100));
    cout << "\nYou return to your room and go to sleep, wondering what tomorrow will bring...\n";
}

void act2_day3(Player& player) {
    sleep_for(milliseconds(100));
    cout << "Day 3: You wake up feeling the weight of the week settle into your bones.\n";

    sleep_for(milliseconds(100));
    cout << "\nThey ask, just like always: \"Want eggs or oatmeal?\"\n";

    string breakfast3;
    cout << "Choose your breakfast: (eggs / oatmeal): ";
    cin >> breakfast3;
    while (breakfast3 != "eggs" && breakfast3 != "oatmeal") {
        cout << "Invalid option. You can eat only one of them: ";
        cin >> breakfast3;
    }

    cout << "You chose: " << breakfast3 << endl;

    sleep_for(milliseconds(100));
    cout << "\nYou get oatmeal. No one gets eggs. Maybe no one ever did.\n";
    cout << "You eat in silence, the illusion intact just enough to keep you from screaming.\n";

    sleep_for(milliseconds(100));
    cout << "\nYou feel it's time. You come up with a detailed escape plan.\n";

    string choice;
    sleep_for(milliseconds(100));
    cout << "Do you want to ask for help or escape on your own? (ask / solo): ";
    cin >> choice;

    if (choice == "ask") {
        sleep_for(milliseconds(100));
        if (player.reputation >= 2) {
            cout << "\nSome inmates trust you and agree to help.\n";
            cout << "They lead you to a secret passage and hide you in their shelter.\n";
            cout << "You wait a couple of days...\n";
            sleep_for(seconds(2));
            cout << "Eventually, the guards stop searching. You slip out and go home!\n";
        } else {
            sleep_for(milliseconds(100));
            cout << "\nThe inmates don’t trust you. One of them tells the guards.\n";
            cout << "You’re dragged to isolation before you can act.\n";
            player.inIsolation = true;
        }
    }

    else if (choice == "solo") {
        sleep_for(milliseconds(100));
        cout << "\nYou decide to escape on your own. Which method do you use? (strength / dexterity): ";
        string method;
        cin >> method;

        if (method == "strength") {
            if (player.Strength >= 11) {
                sleep_for(milliseconds(100));
                cout << "You force your way through a loose bar in the fence and make it outside.\n";
                cout << "You run and disappear into the night. You’re free!\n";
            } else {
                sleep_for(milliseconds(100));
                cout << "You struggle with the bars but can’t break through. You’re caught!\n";
                player.injured = true;
            }
        }

        else if (method == "dexterity") {
            if (player.Dexterity >= 10) {
                sleep_for(milliseconds(100));
                cout << "You slip through a maintenance duct and evade detection.\n";
                cout << "You find your way out and go home safely.\n";
            } else {
                sleep_for(milliseconds(100));
                cout << "You make a noise crawling through the ducts. Guards catch you.\n";
                player.injured = true;
            }
        }

        else {
            sleep_for(milliseconds(100));
            cout << "You hesitate and waste time. Guards notice your absence. You’re caught.\n";
            player.injured = true;
        }
    }

    else {
        sleep_for(milliseconds(100));
        cout << "You can’t decide and waste your chance. The opportunity is gone.\n";
        cout << "You go back to bed frustrated.\n";
    }

    if (!player.injured && !player.inIsolation) {
        sleep_for(milliseconds(100));
        cout << "\nYou return home and sleep in your own bed for the first time in ages...\n";
    }
}

int main() {
    Player player;
    player.Strength = 10;
    player.Dexterity = 8;
    player.Constitution = 10;
    player.Intelligence = 7;
    player.Wisdom = 6;
    player.Charisma = 9;
    player.reputation = 0;

    printStats(player);
    act2_day1(player);

    sleep_for(milliseconds(100));
    cout << "\nYou made it through Day 1!\n";
    act2_day2(player);

    if (player.injured) {
        sleep_for(milliseconds(100));
        cout << "\nYou are too injured to continue.\n";
        cout << "=============================================" << endl;
        cout << "\t\t\t\t Game Over." << endl;
        cout << "=============================================" << endl;
        return 0;
    }
    else if (player.inIsolation) {
        sleep_for(milliseconds(100));
        cout << "\nYou were sent to isolation. Game Over.\n";
        cout << "=============================================" << endl;
        cout << "\t\t\t\t Game Over." << endl;
        cout << "=============================================" << endl;
        return 0;
    }
    sleep_for(milliseconds(100));
    cout << "\nYou made it through Day 2!\n";
    act2_day3(player);

    if (player.injured) {
        sleep_for(milliseconds(100));
        cout << "\nYour escape failed due to injury.\n";
        cout << "=============================================" << endl;
        cout << "\t\t\t\t Game Over." << endl;
        cout << "=============================================" << endl;
    }
    else if (player.inIsolation) {
        sleep_for(milliseconds(100));
        cout << "\nYou were caught and placed in isolation.\n";
        cout << "=============================================" << endl;
        cout << "\t\t\t\t Game Over." << endl;
        cout << "=============================================" << endl;
    }
    else {
        sleep_for(milliseconds(100));
        cout << "\nCongratulations! You escaped and survived the journey.\n";
        cout << "=============================================" << endl;
        cout << "\t\t\t\t Victory!" << endl;
        cout << "=============================================" << endl;
    }

    return 0;
}