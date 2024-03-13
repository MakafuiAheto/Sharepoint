#include <iostream>
#include <memory>
#include <unordered_map>
#include <fstream>
#include <string>



std::unordered_map<int, std::string> read_file(std::ifstream& filestream){
    int key;
    std::string word_string;
    std::unordered_map<int, std::string> read_map;

    while(filestream>>key>>word_string){
        read_map.insert(std::pair<int, std::string>(key, word_string));
    }

    return read_map;
}

int main() {

    std::ifstream filestream("./text.txt");

    if(filestream.is_open()){
        auto read_map = std::make_shared<std::unordered_map<int , std::string>>(
                read_file(filestream)
                );

        for(auto & iterator : *read_map){
            std::cout<< "Key: " << iterator.first  << " Value: "<< iterator.second << std::endl;
        }
    }

    filestream.close();

    return 0;
}