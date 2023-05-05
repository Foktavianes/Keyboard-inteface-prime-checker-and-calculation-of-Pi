#include <iostream>
#include <vector>

bool isPrime(int m){
    // prime number start from 2
    if (m <= 1){
        return false;
    }
    for (int i = 2; i < m/2; i++){ // check if int m is divisible by other number beside 1 and itself.
        if (m%i == 0){
            return false;
        }
    }
    return true;
}

void goldbach(int m){
    if (m == 2){ // exception to goldbach conjecture since 2 (positive even integer) cannot be expressed as sum of 2 primes
        throw std::invalid_argument("Found a counterexample for the conjecture.The number cannot be expressed as the sum of two prime numbers.");
    }else if(m > 0 && m%2 != 0){ // handle positive odd integer
        throw std::invalid_argument("Invalid input: Please input a positive even integer.");
    }else if(m<0){ // function requires positive even value
        throw std::invalid_argument("Invalid input: The input is not a positive even integer.");
    }else{
        for (int i = 2; i <= m; i++){
            if (isPrime(i) == true && isPrime(m-i) == true){ // checking if both the numbers from left and right are prime.
                std::cout << "The pair of numbers is " << i << " and " << m-i << " which result in " << m << std::endl;
                break; // if we found one pair, we return that pair
            }
        }
    }
}

int main(int argc, char *argv[]){
    if (argc < 2){ // handling empty argument
        std::cout << "Error: Empty argument. Please provide an input " <<std::endl;
    }else{
        try{
            int number = std::stoi(argv[1]); // converting string to integer
            goldbach(number);
        }catch(const std::invalid_argument& e){
            std::cerr << e.what() << std::endl; // handling invalid input
        }catch(const std::out_of_range& e){
            std::cerr << "Error: Out of range. " << std::endl; // handling out of range input
        }
    }
    return 0;
}







