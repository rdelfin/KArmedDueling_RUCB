#include "Run.h"
#include "stdafx.h"

/*******************************************************************************
 *************************** CONSTRUCTORS **************************************
 *******************************************************************************/
Run::Run(const vector<Arm>& arms, double learningRate)
    : arms(arms), wins(arms.size(), arms.size(), fill::zeros),
    ucb(arms.size(), arms.size(), fill::ones), learningRate(learningRate),
      t(0)
{

}

Run::Run(const mat& vals, double learningRate)
    : arms(vals.n_rows), wins(arms.size(), arms.size(), fill::zeros),
      learningRate(learningRate), t(0)

{
    assert(vals.n_rows == vals.n_cols);

    for(size_t i = 0; i < vals.n_rows; i++) {
        vec pVals = trans(vals.row(i));
        arms[i] = Arm(pVals);
    }
}


/*******************************************************************************
 ********************************* ACTIONS *************************************
 *******************************************************************************/
void Run::timestep()
{
    t++;

    updateUCB();
}

void Run::updateUCB()
{
    mat totalWins = wins + trans(wins);

    ucb = wins / totalWins + sqrt(learningRate * log(t) / totalWins);

    //Something tells me this kills all the optimization but ok...
    //Also, THERE IS PROBABLY A VECTORIZATION FOR THIS CODE
    //TODO: Find vectorization
    for(size_t i = 0; i < ucb.n_rows; i++) {
        for(size_t j = 0; j < ucb.n_cols; j++) {
            if(totalWins(i, j) == 0)
                ucb(i, j) = 1;
        }
    }
}


ostream& operator<<(ostream& os, const Run& r)
{
    os << "Run arms: " << endl;
    for(size_t i = 0; i < r.arms.size(); i++) {
        os << "\t[" << i << "]: " << r.arms[i] << endl;
    }

    os << endl << "UCB: " << endl;
    os << r.ucb << endl;

    return os;
}
