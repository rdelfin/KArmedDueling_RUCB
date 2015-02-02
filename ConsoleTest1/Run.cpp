#include "Run.h"
#include "stdafx.h"


Run::Run(const vector<Arm>& arms)
    : arms(arms)
{

}

Run::Run(double** vals, size_t armCount)
    : arms(armCount)
{
    for(size_t i = 0; i < armCount; i++) {
        vector<double> pVals;

        for(size_t j = 0; j < armCount; j++) {
            pVals.push_back(vals[i][j]);
        }
        arms[i] = Arm(pVals);
    }
}

ostream& operator<<(ostream& os, const Run& a)
{
    os << "Run arms: " << endl;
    for(size_t i = 0; i < a.arms.size(); i++) {
        os << "\t[" << i << "]: " << a.arms[i] << endl;
    }

    return os;
}
