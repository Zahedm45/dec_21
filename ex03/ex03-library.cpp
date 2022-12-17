#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    // Write your code here

    for (auto room: roomNames) {
        if (room == name) {
            return;
        }
    }

    roomNames.push_back(name);
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {
    // Write your code here

    bool room_name_found = false;

    for (auto room: roomNames) {
        if (room == roomName) {
            room_name_found = true;
        }
    }
    if (!room_name_found) return;


    if (roomOccupancy.find(roomName) == roomOccupancy.end()) {

        for (auto room_occ: roomOccupancy) {
            if (room_occ.second.id == guestId) {
                return;
            }

        }

        Guest new_guest;
        new_guest.id = guestId;
        new_guest.name = guestName;
        roomOccupancy[roomName] = new_guest;
    }

}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    // Write your code here


    for (auto room_n: roomNames) {

        for (auto room_occu: roomOccupancy) {

            if (room_n == room_occu.first) {
                if (room_occu.second.id == guestId && room_occu.second.name == guestName) {
                    cout << room_n << endl;


                } else if (guestName == "*" && guestId == "*"){
                    cout << room_n << endl;

                }else if (guestId == "*" && guestName == room_occu.second.name){
                    cout << room_n << endl;

                }else if (guestId == room_occu.second.id && guestName == "*"){
                    cout << room_n << endl;
                }
            }
        }
    }



}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
