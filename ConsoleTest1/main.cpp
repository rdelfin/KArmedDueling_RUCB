#include "stdafx.h"
#include "Run.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    double** arr = new double*[3];
    for(int i = 0; i < 3; i++)
        arr[i] = new double[3];

    arr[0][0] = 0.50;  arr[0][1] = 0.44;  arr[0][2] = 0.31;
    arr[1][0] = 0.56;  arr[1][1] = 0.50;  arr[1][2] = 0.26;
    arr[2][0] = 0.69;  arr[2][1] = 0.74;  arr[2][2] = 0.50;

    Run run(arr, (size_t)3);

    cout << run << endl;

    return 0;
}
