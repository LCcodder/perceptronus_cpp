#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Weights {

    /// weights structure
    int size;
    int index;
    double radius;

};

double nn(double x[], double w[], int len) {

    /// function returns multipled value of weights and inputs with "len" size
    double y = 0.0;

    for (int i = 0; i < len; ++i) {

        y += x[i] * w[i];

    }

    return y;

}

double sigmoid(double a) {

    /// sigmoid function retuns value from 0.5 to 1
    const double e = 2.671;
    double exp = 1 + pow(e, -a);
    return 1 / exp;

}

int main(int argc, const char* argv[]) {

    /// weights initialization
    Weights frst_weight = { 3, 1, 1.0 };
    Weights scnd_weight = { 3, 2, 0.2 };
    Weights thrd_weight = { 2, 3, 1.0 };
    Weights frth_weight = { 2, 4, 1.0 };
    Weights fift_weight = { 2, 5, 1.0 };
    Weights sixt_weight = { 2, 6, 0.5 };
    Weights final_weight = { 4, 7, 1.0 };

    

    /// weights dynamic matrix
    double *weights1 = new double [frst_weight.size] { 0.5, -0.5, 0.5 };
    double *weights2 = new double [scnd_weight.size] { 0.1, 0.1, -0.1 };
    double *weights3 = new double [thrd_weight.size] { 0.5, -0.5 };
    double *weights4 = new double [frth_weight.size] { 0.8, -0.8 };
    double *weights5 = new double [fift_weight.size] { 0.7, -0.7 };
    double *weights6 = new double [sixt_weight.size] { 0.3, -0.2 };
    double *fin_weights = new double [final_weight.size] { 0.5, 0.3, 0.1, -0.5 };



    /// binary input values
    double inputs[] = { 1, 0, 1 };
    /// initializing size of array
    int *number_el = new int (sizeof(inputs) / sizeof(inputs[0]));


    /// first hidden layer
    double neuron1 = nn(inputs, weights1, *number_el);
    double neuron2 = nn(inputs, weights2, *number_el);
    delete number_el, weights1, weights2;
    double inputs2[] = { neuron1, neuron2 };
    /// initializing size of array
    int *number_el2 = new int (sizeof(inputs2) / sizeof(inputs2[0]));


    /// second hidden layer
    double output1 = nn(inputs2, weights3, *number_el2);
    double output2 = nn(inputs2, weights4, *number_el2);
    double output3 = nn(inputs2, weights5, *number_el2);
    double output4 = nn(inputs2, weights6, *number_el2);
    delete number_el2, weights3, weights4, weights5, weights6;
    double inputs3[] = { output1, output2, output3, output4 };
    /// initializing size of array
    int *number_el3 = new int (sizeof(inputs3) / sizeof(inputs3[0]));


    /// getting output submited with activation sigmoid function
    double fin_output = sigmoid(nn(inputs3, fin_weights, *number_el3));
    delete number_el3, fin_weights;

    /// rounding output after activation function
    cout << round(fin_output*100)/100;

    return 0;

}
