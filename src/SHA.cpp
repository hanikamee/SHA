// This project forges a secure Hashing Alogrithm while appending salt to it

#include <iostream>
#include <fstream>


// A function to return the hash only

size_t sha(std::string input, std::string salt){
    std::hash<std::string> hash;
    return hash(salt + input);
}


// A function to generate a salt. The salt will completely random every time
std::string salt(){
    std::string chars= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012"
                        "3456789";
    std::string s;

    // The size of the salt will be 6
    for (int i = 0; i < 6; i++){
        int index = rand() % chars.size();
        s += chars[index];
    }
    return s;
}


int main()
{
    srand(time(NULL)); // The seed of the randomness will change every time


    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;

    std::string s = salt();

    size_t hash = sha(password, s);

    std:: cout << username << ":" << s << ":" << hash << std::endl;



    return 0;
}
