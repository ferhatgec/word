// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include <fstream>
#include "../include/word.hpp"

void Word::read(std::string const filename) noexcept {
    std::ifstream file(filename);

    for(std::string temporary; std::getline(file, temporary);
        this->file_data.append(temporary + "\n"))
        ; file.close();

    this->replaced_data = this->file_data;
}

void Word::replace(std::vector<std::string> words) noexcept {
    for(auto& word : words) {
        if(this->file_data.find(word) != std::string::npos) {
            this->replaced_data = this->replace_word(this->replaced_data, word, word);
        }
    }
}

void Word::print() noexcept {
    std::cout << this->replaced_data;

    if(this->replaced_data.back() != '\n') {
        std::cout << '\n';
    }
}

std::string Word::replace_word(
        std::string const word,
        std::string& from,
        std::string to) noexcept {
    std::string __word = word;
    std::size_t start = 0; to = "\x1b[1;94m" + to + "\x1b[0m";

    while((start = __word.find(from, start)) != std::string::npos) {
        __word.replace(start, from.length(), to); start += to.length();
    }

    return __word;
}

int main(int argc, char** argv) noexcept {
    if(argc < 3) {
        return 1;
    }

    Word init;

    std::string file(argv[1]);
    std::vector<std::string> words;

    for(std::size_t i = 2; i < argc; i++) {
        words.push_back(std::string(argv[i]));
    }

    init.read   (file);
    init.replace(words );
    init.print  (            );
}