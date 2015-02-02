#pragma once

#include "Arm.h"
#include "stdafx.h"

class Run {
public:
    Run();
    Run(const vector<Arm>& arms);
    Run(double** vals, size_t armCount);

    friend ostream& operator<<(ostream& os, const Run& a);

private:
    vector<Arm> arms;
};

ostream& operator<<(ostream& os, const Run& a);
