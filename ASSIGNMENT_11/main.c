#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

int main(int argc, char *argv[])
{
    char *fname = argv[1];

    // Inputting data
    Data data = new_Data(fname);

    // Initializing model
    Model model = new_Model(data);

    // Fit the model
    fit_model(model, data);

    // Scoring
    run_scoring_engine(model);

    // cleaning up
    free(data);
    free(model);

    return 0;
}