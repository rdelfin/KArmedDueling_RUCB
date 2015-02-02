#include "stdafx.h"
#include "Arm.h"

Arm::Arm() : Arm(vector<double>())
{

}

Arm::Arm(const vector<double>& probabilities)
    : probabilities(probabilities)
{

}

ostream& operator<<(ostream& os, const Arm& a)
{
    os << "Arm p-values: {";

    for(size_t i = 0; i < a.probabilities.size(); i++) {
        os << fixed << setprecision(2) << a.probabilities[i];
        if(i < a.probabilities.size() - 1)
            os << ", ";
    }

    os << "}";

    return os;
}

bool Arm::compareWithArm(size_t index)
{
    /*if(index >= probabilities.size() && index < 0)
        throw exception;*/

    double prob = probabilities[index];
    double randVal = (double)rand() / (double)RAND_MAX;

    return randVal <= prob;
}

Arm::~Arm()
{

}
