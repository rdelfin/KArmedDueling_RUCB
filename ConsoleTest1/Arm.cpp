#include "stdafx.h"
#include "Arm.h"

Arm::Arm() : Arm(mat())
{

}

Arm::Arm(const vec& probabilities)
    : probabilities(probabilities)
{

}

double Arm::getProbability(size_t index) {
    return ((index >= 0 && index < probabilities.n_elem) ? probabilities(index) : -1);
}

ostream& operator<<(ostream& os, const Arm& a)
{
    os << "Arm p-values: ";/*{";

    for(size_t i = 0; i < a.probabilities.n_elem; i++) {
        os << fixed << setprecision(2) << a.probabilities[i];
        if(i < a.probabilities.size() - 1)
            os << ", ";
    }

    os << "}";*/

    os << trans(a.probabilities);

    return os;
}

bool Arm::compareWithArm(size_t index)
{
    /*if(index >= probabilities.size() && index < 0)
        throw exception;*/

    double prob = probabilities(index);
    double randVal = (double)rand() / (double)RAND_MAX;

    return randVal <= prob;
}

Arm::~Arm()
{

}
