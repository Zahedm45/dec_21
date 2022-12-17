#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include "vector"
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here

class SensorBuffer : public Buffer {
private:
    vector<int> stack;
    vector<int> all_writes;

    unsigned int val_for_avg;
    int write_count;


public:
    SensorBuffer(unsigned int a);

    void write(int v) override;
    int read() override;

    int readAvg();
    unsigned int writeCount();
};





#endif /* EX04_LIBRARY_H_ */
