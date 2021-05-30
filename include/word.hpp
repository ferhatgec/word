// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef WORD_WORD_HPP
#define WORD_WORD_HPP

#include <iostream>
#include <string>
#include <vector>

class Word {
    std::string file_data,
                replaced_data;
public:
    Word() = default;
    ~Word()= default;

    void read        (std::string  const filename   ) noexcept;
    void replace     (std::vector<std::string> words) noexcept;
    void print       (                              ) noexcept;

    std::string
         replace_word(std::string const word,
                      std::string& from,
                      std::string  to               ) noexcept;
};

#endif // WORD_WORD_HPP
