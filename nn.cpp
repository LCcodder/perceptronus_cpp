#include <iostream>
#include <cmath>
#include <string>


using namespace std;


double nn(double x[], double w[], int len) {

    double y = 0.0;

    for (int i = 0; i < len; ++i) {
        
        y += x[i] * w[i];

    }

    return y;


}

double sigmoid(double a) {
    const double e = 2.671;
    double exp = 1 + pow(e, -a);
    return 1 / exp;

}

int main(int argc, const char * argv[]) {

    double inputs[] = { 1, 0, 1 };
    /// weights matrix
    double weights[] = { 0.5, -0.5, 0.5 };
    double weights2[] = { 0.1, 0.1, -0.1 };
    double weights3[] = { 0.5, -0.5 };

    int number_el = sizeof(inputs) / sizeof(inputs[0]);

    double neuron1 = nn(inputs, weights, number_el);
    double neuron2 = nn(inputs, weights2, number_el);


    double inputs2[] = {neuron1, neuron2};

    int number_el2 = sizeof(inputs2) / sizeof(inputs2[0]);

    double output1 = nn(inputs2, weights3, number_el2);
    double fin_output = sigmoid(output1);

    cout << fin_output;



    return 0;

}



