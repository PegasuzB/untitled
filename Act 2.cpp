#include "Act 1.cpp"
using namespace std;
using namespace chrono;
using namespace this_thread;

struct Player {
    int Strength;
    int Dexterity;
    int Constitution;
    int Intelligence;
    int Wisdom;
    int Charisma;
    bool injured;
    bool inIsolation;
    int reputation;
};

void printStats(const Player& p);
void goToLibrary(Player& player);
void goToGym(Player& player);
void dayOne(Player& player);
void dayTwo(Player& player);

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


void dayOne(Player& player) {
    sleep_for(milliseconds(100));
    cout << "\n\n=======================================================================================================================\n";
    cout << "\t\t Day 1: You wake up on a mattress so thin you can feel every crack in the concrete beneath it.\n";
    sleep_for(milliseconds(100));
    cout << "\t\t\t\t The air is stale, heavy with bleach and something metallic, like rusted hope.\n";
    sleep_for(milliseconds(100));
    cout << "\tA weak strip of light buzzes overhead, and for a second, you forget where you are—until the silence reminds you.\n";
    cout << "=======================================================================================================================\n";
    sleep_for(milliseconds(100));
    cout << "A tray is slid through the slot. You're told you can choose today’s breakfast: cereal or toast.\n";

    string breakfast1;
    cout << "Choose your breakfast: (cereal / toast): ";
    cin >> breakfast1;

    sleep_for(milliseconds(100));
    cout << "\nYou unwrap the foil. It’s plain cereal. It was always going to be cereal.\n";
    cout << "Maybe the toast machine's been broken since the '90s.\n";

    string location;
    cout << "Where do you want to go? (yard/library): ";
    cin >> location;

    if (location == "library") {
        goToLibrary(player);
        return;
    }

    else if (location == "yard") {
        sleep_for(milliseconds(100));
        cout << "\nYou go to the yard. You meet some people and ask around about others.\n";
        string choice;
        cout << "A big guy insults you. Do you want to fight him? (yes/no): ";
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

void dayTwo(Player& player) {
    sleep_for(milliseconds(100));
    cout << "\n\n============================================================================================================================\n";
    cout << "\t\t\t\t\t\tDay 2: You wake to the sound of boots echoing down the hall, ";
    cout<<" each step sharp and deliberate, reverberating through the stillness of the early morning.";
    cout << "=================================================================================================================================\n";

    sleep_for(milliseconds(100));
    cout << "\nThe guard offers a cheerful, \"Pancakes or porridge today?\"\n";

    string breakfast2;
    cout << "Choose your breakfast: (pancakes / porridge): ";
    cin >> breakfast2;

    sleep_for(milliseconds(100));
    cout << "\nYou lift the lid. It's porridge. Cold, lumpy, and familiar.\n";
    cout << "You wonder if pancakes were ever really on the table.\n";


    sleep_for(milliseconds(100));
    cout << "\nA clipboard is passed around, asking if you'd like 'yard time' or 'room rest'.\n";
    cout << "You tick a box. Doesn’t matter.\n";

    string fakeChoice;
    cout << "Choose your preference: (yard / room): ";
    cin >> fakeChoice;

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

void dayThree(Player& player) {
    sleep_for(milliseconds(100));
    cout << "\n\n============================================================================\n";
    cout << "Day 3: You wake up feeling the weight of the week settle into your bones.\n";
    cout << "===========================================================================\n";

    sleep_for(milliseconds(100));
    cout << "\nThey ask, just like always: \"Want eggs or oatmeal?\"\n";

    string breakfast3;
    cout << "Choose your breakfast: (eggs / oatmeal): ";
    cin >> breakfast3;

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

