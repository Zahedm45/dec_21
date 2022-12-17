#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    // Replace the following with your code

    Passenger *temp = q;
    while (temp != nullptr) {
        if (temp->ticket == ticket) {
            return temp;
        }
        temp = temp->next;
    }


    return nullptr;
}

// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    // Replace the following with your code

    Passenger *new_list_head = new Passenger;
    Passenger *new_list_trav = new_list_head;

    Passenger *temp = q;
    while (temp != nullptr) {

        if (temp->ticket != ticket) {
            Passenger *p = new Passenger();
            p->name = temp->name;
            p->ticket = temp->ticket;
            p->priority = temp->priority;
            p->next = nullptr;
            new_list_trav->next = p;
            new_list_trav = new_list_trav->next;

        }

        temp = temp->next;
    }

    Passenger *result = new_list_head->next;
    delete new_list_head;

    return result;
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    // Replace the following with your code

    if (q == nullptr) return nullptr;

    Passenger *new_list_head = new Passenger;
    Passenger *new_list_trav = new_list_head;

    Passenger *temp = q;
    while (temp != nullptr) {

        if (temp->priority) {
            Passenger *p = new Passenger();
            p->name = temp->name;
            p->ticket = temp->ticket;
            p->priority = temp->priority;
            p->next = nullptr;
            new_list_trav->next = p;
            new_list_trav = new_list_trav->next;

        }

        temp = temp->next;
    }

    Passenger *result = new_list_head->next;
    delete new_list_head;

    return result;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
