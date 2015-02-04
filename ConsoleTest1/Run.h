#pragma once

#include "Arm.h"
#include "stdafx.h"

class Run {
public:
    Run();
    Run(const vector<Arm>& arms, double learningRate = 1);
    Run(const mat& vals, double learningRate = 1);

    void timestep();

    void updateUCB();

    friend ostream& operator<<(ostream& os, const Run& a);

private:
    vector<Arm> arms;

    mat wins;
    mat ucb;

    double learningRate;

    long t;
};

ostream& operator<<(ostream& os, const Run& a);
