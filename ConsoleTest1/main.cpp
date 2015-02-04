#include "stdafx.h"
#include "Run.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    mat pVals = mat(3, 3);

    pVals(0, 0) = 0.50;  pVals(0, 1) = 0.44;  pVals(0, 2) = 0.31;
    pVals(1, 0) = 0.56;  pVals(1, 1) = 0.50;  pVals(1, 2) = 0.26;
    pVals(2, 0) = 0.69;  pVals(2, 1) = 0.74;  pVals(2, 2) = 0.50;

    Run run(pVals, 1);
    run.timestep();

    cout << run << endl;

    return 0;
}
