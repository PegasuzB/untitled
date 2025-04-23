#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;

string input;
bool hasGear = false, alliesMet = false, crackedSafe = false;

void pressEnter() {
    cout << "\n[Press ENTER to continue]";
    cin.ignore(); cin.get();
}

void Act3_day1() {
    cout << "\n--- DAY 1 ---\n";
    cout << "You wake up. Morning light hits your face. You stretch and head to the kitchen.\n";
    cout << "The smell of breakfast is heavenly – fried eggs, toast, and coffee.\n";
    pressEnter();

    cout << "You stare out the window and decide... maybe it's time. Time to rob that bank.\n";
    pressEnter();

    cout << "You start planning. You recall things you know: the guard shifts, the vault location.\n";
    cout << "You scribble notes, draw maps, think like a thief.\n";
    pressEnter();

    cout << "You double-check all information. Do you really know enough?\n";
    if (intelligence + wisdom > 5) {
        cout << "Yes. Everything checks out. You’re sharp.\n";
    } else {
        cout << "Not really. You may have missed something, but you're moving forward anyway.\n";
    }
    pressEnter();

    cout << "You spend the evening playing a puzzle game to relax (minigame).\n";
    pressEnter();

    cout << "You call up old friends – allies. They agree to meet tomorrow.\n";
    alliesMet = true;
    pressEnter();

    cout << "Night falls. You drift into sleep with thoughts of riches.\n";
    pressEnter();
}

void Act3_day2() {
    cout << "\n--- DAY 2 ---\n";
    cout << "You wake up refreshed. Another breakfast – not as good as yesterday.\n";
    pressEnter();

    cout << "You play a small challenge to warm up (minigame).\n";
    pressEnter();

    if (alliesMet) {
        cout << "You meet your allies at the café. Faces from the past, willing to help.\n";
    } else {
        cout << "You are alone. Riskier, but doable.\n";
    }
    pressEnter();

    cout << "You decide to go to a shady bar downtown. You know it has an underground market.\n";
    pressEnter();

    cout << "You ask the bartender quietly for some... special gear.\n";
    if (charisma >= 3) {
        cout << "He nods. Tells you to prove your worth: a game of Russian Roulette.\n";
        cout << "You sit down, nerves steel.\n";
        if (constitution >= 3) {
            cout << "You survive the game. He slides you a bag – masks, weapons, smoke bombs.\n";
            hasGear = true;
        } else {
            cout << "You pass out before the first click. You wake up back home, gearless.\n";
        }
    } else {
        cout << "He laughs. 'Get lost.' You leave empty-handed.\n";
    }
    pressEnter();
    cout << "You go home and sleep. Tomorrow is the big day.\n";
    pressEnter();
}

void Act3_day3() {
    cout << "\n--- DAY 3 ---\n";
    cout << "You wake up. No turning back now.\n";
    pressEnter();

    if (alliesMet) {
        cout << "You meet with your allies. Everyone’s tense but ready.\n";
    } else {
        cout << "You're alone.\n";
    }
    pressEnter();

    cout << "You arrive at the bank. Midday. It’s quiet.\n";
    pressEnter();

    cout << "Time for the minigame – cracking the vault.\n";
    if ((intelligence + dexterity) >= 6) {
        cout << "You bypass the security. The safe opens. You're in.\n";
        crackedSafe = true;
    } else {
        cout << "You fail. The alarm blares. It’s over.\n";
        cout << "GAME OVER – You’ve been caught.\n";
        return;
    }
    pressEnter();

    cout << "You take the money, run out the back. Everything is a blur.\n";
    pressEnter();

    cout << "You make it home. No police. No problems.\n";
    cout << "You’re rich now.\n";
    cout << "GAME OVER – Happy Ending!\n";
}
