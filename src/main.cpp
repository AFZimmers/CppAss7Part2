#include <iostream>
#include <vector>
#include <tgmath.h>

double errorFunction(std::vector<double> vector, double target);

//activation function
float sigmiod(double net){
    float o = 1/(1 +exp(-net));
    return o;
}
//function dealing with the hidden layer calculations
std::vector<double > hiddenLayerNodes(std::vector<double>inputs,std::vector<double >weights1,std::vector<double >weights2, std::vector<double> bias){

    std::vector<double > hiddenLayerNodes;
    for (int j = 0; j < bias.size(); ++j) {
        float o=0;
        float result;
        for (int i = 0; i < inputs.size(); ++i) {
            if (j == 0) {
                o += inputs[i] * weights1[i];
            } else {
                o += inputs[i] * weights2[i];
            }
        }
        o += bias.at(j);
        //std::cout<<o<<std::endl;
        result = sigmiod(o);
        hiddenLayerNodes.push_back(result);
    }
    return hiddenLayerNodes;
}
// output layer taking the values from the hidden layer
std::vector<double> outputLayer(std::vector<double>inputs,std::vector<double>weights,double bias){
    double o=0;
    double result;
    std::vector<double> outputLayer;

    for (int i = 0; i < inputs.size(); ++i) {
        o += inputs[i] * weights[i];
    }
    o += bias;
    result = sigmiod(o);
    outputLayer.push_back(result);

    return outputLayer;
}

int main() {
    //input data
    std::vector<double> inputsX ={1.3,2.7,0.8};
    std::vector<double> hiddenLayerNode1weights ={0.1,0.2,0.5};
    std::vector<double> hiddenLayerNode2weights ={-0.4,1.0,-0.6};
    std::vector<double> outputLayerWeights ={0.8,1.0};
    std::vector<double> biasHiddenLayerNodes ={0.1,-0.3};
    double outputBias = -0.3;
    double target = 0.36;
    //hidden layer function call
    std::vector<double > hiddenLayerNodesOutput=hiddenLayerNodes(inputsX,hiddenLayerNode1weights,hiddenLayerNode2weights,biasHiddenLayerNodes);
    for (int i = 0; i < hiddenLayerNodesOutput.size(); ++i) {
        std::cout << hiddenLayerNodesOutput.at(i) << std::endl;
    }
    // output layer function call
    std::vector<double> outputLayerOutput=outputLayer(hiddenLayerNodesOutput,outputLayerWeights,outputBias);
    for (int i = 0; i < outputLayerOutput.size(); ++i) {
        std::cout << outputLayerOutput.at(i) << std::endl;
    }
    // error function call
    double error=errorFunction(outputLayerOutput, target);
    std::cout << error << std::endl;
    return 0;
}
// error function
double errorFunction(std::vector<double> vector, double target) {
    double error = (pow((target-vector.at(0)),2));
    return error;
}
