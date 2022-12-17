#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and writeCount()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of readAvg()

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}

SensorBuffer::SensorBuffer(unsigned int a) {
    val_for_avg = a;
}

void SensorBuffer::write(int v) {
    stack.push_back(v);
    write_count++;
    all_writes.push_back(v);

}

int SensorBuffer::read() {
    if (stack.empty()) return 0;

    int val = stack[stack.size() - 1];
    stack.pop_back();

    return val;
}

int SensorBuffer::readAvg() {

    if (all_writes.empty()) return 0;


    int total = 0, counter = 0;

    int i = all_writes.size()-1;

    while (i >= 0) {
        int k = all_writes.size() - i;
        if (k > val_for_avg) break;

        total = total + all_writes[i];

        i--;
        counter++;
    }




    int result = (int ) total / counter;

    return result;
}


unsigned int SensorBuffer::writeCount() {

    return write_count;
}
