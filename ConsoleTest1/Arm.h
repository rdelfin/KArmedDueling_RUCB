#pragma once

#include "stdafx.h"

class Arm {
public:
    Arm();
    Arm(const vector<double>& probabilities);

    friend ostream& operator<<(ostream& os, const Arm& a);

    //Will return true if this arm won
    bool compareWithArm(size_t index);

    ~Arm();


private:
    //Defined as the probability that THIS arm will win against the arm in the index
    vector<double> probabilities;
};


ostream& operator<<(ostream& os, const Arm& a);
