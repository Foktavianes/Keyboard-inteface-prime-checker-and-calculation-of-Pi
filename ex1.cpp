#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>

std::vector<std::string> konno(int argc, char** argv){
    //initialize keyboard interface as one liner
    std::string keys = "qwertyuiopasdfghjklzxcvbnm";
    std::vector<char> keyboard(keys.begin(), keys.end());
    std::vector<std::string> dots(26, "."); // initialize with 26 dots
    std::vector<char> unique; // empty vector to keep unique value 
    for (int y = 1; y < argc; y++){ // loop for every inputs
        for (int z = 0; z < strlen(argv[y]); z++){ // loop for every elements in every inputs
            char ch = tolower(argv[y][z]); // convert to lowercase
            // if the element is not inside unique vector, add the element into vector. Else, do nothing
            if(std::find(unique.begin(), unique.end(), ch) == unique.end()){ 
                unique.push_back(ch);
                auto checker = std::find(keyboard.begin(), keyboard.end(), ch); // finding index of the element in vector keyboard
                if (checker != keyboard.end()){ 
                    int index = std::distance(keyboard.begin(), checker);
                    dots[index] = "o"; // use the index from vector keyboard to change the value for vector dots
                }
            }
        }
    }
    return dots; // return vector dots
}

int main(int argc, char *argv[]) {
    // If there is no argument, return error
    if (argc < 2){
        std::cout << "Error: Empty argument. Please provide an input " <<std::endl;
    }else{
    std::vector<std::string> result = konno(argc, argv);
    for (int i = 0; i <26; i++){ // loop to output keyboard looking interface
        if (i == 9){
            std::cout << result[i] <<"\n";
        }else if(i == 10){
            std::cout << " "<< result[i] << " ";
        }else if(i == 18){
            std::cout << result[i] <<"\n";
        }else if(i == 19){
            std::cout << "  " << result[i] << " ";
        }else{
            std::cout << result[i] << " ";
        }
    }
    std::cout << "\n";
    }
    return 0;
}