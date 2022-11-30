#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

// shape structure that defines the dimensions
struct shape {
    int row;
    int col;
};

// inputs are stored in a 2d array using a pointer so memory can be dynamically allocated
// targets are stored in a 1d array
// shape is stored in the shape struct
struct data {
    double **inputs;
    int *targets;
    struct shape shape;
};

// weights are stored in a 1d array
// shape is stored in shape struct
// current x, y, target value stored in double, double, and int respectively
struct model {
    double *weights;
    struct shape shape;
    double curX;
    double curY;
    int curT;
};

Data new_Data(const char *fname)
{
    // need to calculate the number of rows in the file we have
    // this tells us the number of observations
    FILE *f = fopen(fname,"r");
    int lines = 0;
    int ch = 0;
    while ((ch = fgetc(f)) != EOF){
        if (ch == '\n') {
            lines++;
        }
    }
    lines++;

    // need to calculate the number of columns (i.e. how many spaces in first line)
    // this tells us the number of features
    fseek(f, 0, SEEK_SET);
    int columns = 0;
    while ((ch = fgetc(f)) != '\n'){
        if (ch == ' ') {
            columns++;
        }
    }

    Data data = (Data) malloc(sizeof(Data));
    Shape shape = (Shape) malloc(sizeof(Shape));

    // dynamically set the size of the 2d array that stores inputs
    data->inputs = (double **) malloc(columns * sizeof(double*));
    for(int i=0; i<2; i++){
        data->inputs[i] = (double *) malloc(lines * sizeof(double));
    }
    // dynamically set the size of the target array
    data->targets = (int*) malloc(lines * sizeof(int));

    // set the shape attributes
    data->shape.row = lines;
    data->shape.col = columns;

    fseek(f, 0, SEEK_SET);

    // these will be used in the fscanf loop to temp store the variables before assignment
    // this makes conversion of the target to integer easier
    int i = 0;
    double f1 = 0.0;
    double f2 = 0.0;
    double t = 0.0;

    while(fscanf(f, "%lf %lf %lf", &f1, &f2, &t) != EOF){
        data->inputs[0][i] = f1;
        data->inputs[1][i] = f2;
        data->targets[i] = (int) t;
        i++;
    }
    fclose(f);

    return data;
}

Model new_Model(const Data data)
{
    Model model = (Model) malloc(sizeof(Model));
    model->weights = (double*) malloc((data->shape.col + 1) * sizeof(double));
    model->shape.row = 1;
    model->shape.col = data->shape.col;

    return model;
}

static void sgd(Model model, Data data)
{
    model->weights[2] += model->curT * model->curX;
    model->weights[1] += model->curT * model->curY;
    model->weights[0] += model->curT * 1;
}

static int predict(Model model, Data data)
{
    double hypothesis = model->weights[2] * model->curX + model->weights[1] * model->curY + model->weights[0];
    return (hypothesis < 0) ? -1 : 1;
}

void fit_model(Model model, Data data)
{
    double hypothesis, target;

    for (int i = 0; i < (data->shape.col+1); i++)
        model->weights[i] = (double) rand() / RAND_MAX;

    bool misclassified = true;
    while (misclassified) {
        misclassified = false;
        for (int i = 0; i < data->shape.row; i++) {
            model->curX = data->inputs[0][i];
            model->curY = data->inputs[1][i];
            model->curT = data->targets[i];
            hypothesis = predict(model, data);
            target = data->targets[i];
            if ((hypothesis > 0 && target > 0) || (hypothesis < 0 && target < 0)) // TODO Handle 0
                continue;
            sgd(model, data);  // Update weights using misclassified point
            misclassified = true;
        }
    }
}

void run_scoring_engine(const Model model)
{
    double x, y;

    printf("Enter x: \n");
    scanf("%lf", &x);

    printf("Enter y: \n");
    scanf("%lf", &y);

    model->curX = x;
    model->curY = y;
    Data data;
    printf("Prediction = %d\n", predict(model, data));
}