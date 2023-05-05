#include <iostream>
#include <cmath>


double Pi1(int nTerm){
    if(nTerm < 0){
        throw std::invalid_argument("Invalid input: Please input a positive even integer for Pi1.");
    }else if(nTerm == 0){
        return 4.0;
    }else{
        double sign = (nTerm%2 == 0)?1.0:-1.0;
        double summation = sign * (1.0/(2.0*nTerm +1));
        return 4.0 * summation + Pi1(nTerm-1); // might results in stack overflow if the input is too large
    }
}

double Pi2(int nTerm){
    if(nTerm <= 0){
        throw std::invalid_argument("Invalid input: Please input a positive even integer for Pi2.");
    }
    double count = 0.0; // initialize variable to keep track of value in every iteration
    while (nTerm >= 1){ // exit conidition if nTerm < 1
        double sign = (nTerm%2 == 0)?-1.0:1.0;
        double summation = sign * (1.0/(2.0*nTerm * (2.0*nTerm + 1.0) * (2.0*nTerm + 2.0)));
        count += summation; // count will act as summation over the range of iteration
        nTerm--; // we going from upper limit to lower limit
    }
    return 3.0 + 4.0 * count;
}

double Pi3(int nTerm){
    if(nTerm < 0){
        throw std::invalid_argument("Invalid input: Please input a positive even integer for Pi3.");
    }
    double arctan_5, arctan_239 = 0.0;
    do{
        double sign = (nTerm%2 == 0)?1.0:-1.0;
        arctan_5 += (sign/(2*nTerm + 1)) * pow(1.0/5.0, 2*nTerm + 1); // summation over range of iteration for arctan_1/5
        arctan_239 += (sign/(2*nTerm + 1)) * pow(1.0/239.0, 2*nTerm + 1); // summation over range of iteration for arctan_1/239
        nTerm--;
    }while (nTerm >= 0);{ // exit condition if nTerm < 0
       return 4.0 * (4.0*arctan_5 - arctan_239);
    }
}

int main(int argc, char *argv[]){
    if (argc < 2){
        std::cout << "Error: Empty argument. Please provide an input " <<std::endl;
    }else{
        try{
            std::cout.precision(10);
            const double PI =  3.141592653589793238463;
            int nTerm = std::stoi(argv[1]);
            // this will catch invalid input if the input is negative (will show this since this will be the first one to be caught)
            double value_1 = Pi1(nTerm); 
            std::cout << "Error from Pi1 compared to const PI = " << (Pi1(nTerm) - PI) << std::endl;
            double value_2 = Pi2(nTerm); // this will catch invalid input if the input is negative
            std::cout << "Error from Pi2 compared to const PI = " << (Pi2(nTerm) - PI) << std::endl; 
            double value_3 = Pi3(nTerm); // this will catch invalid input if the input is negative
            std::cout << "Error from Pi3 compared to const PI = " << (Pi3(nTerm) - PI) << std::endl;
        }catch(const std::invalid_argument& e){
            std::cerr << e.what() << std::endl;
        }catch(const std::out_of_range& e){
            std::cerr << "Error: Out of range. " << std::endl;
        }
    }
    return 0;
}