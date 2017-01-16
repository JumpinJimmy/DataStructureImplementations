#include <cassert> //NOLINT
#include <iostream>
#include <memory>
#include <algorithm>
#include "includes/chap_thirteen.h"
#include "includes/isbn_cache.h"

// Test Exercise 13.1
void PermuteToPalindrome(HashTableExercises* ht_exerciser) {
    std::vector<std::string> source_str_list {"Hello James", "raeccar", "acbba",
                                              "Hockenheim", "James", "staythesame", "AEIOUaeiou"};
    for (auto &test_str : source_str_list) {
        std::cout << "--->>--->> HashTables:: PermuteToPalindrome(\"" << test_str << "\"): "
                  << std::boolalpha << ht_exerciser->PermuteToPalindrome(test_str) << std::endl;
    }
}

// Test Exercise 13.2
void IsLetterConstructible(HashTableExercises* ht_exerciser) {
    std::vector<std::string> letter_list {"123", "123", "GATTACA", "a", "aa", "staythesame", ""};
    std::vector<std::string> magazine_list {"456", "12222222", "A AD FS GA T ACA TTT", "", "aa", "staythesame", "123"};
    std::vector<std::pair<std::string, std::string>> letter_mag_list;
    letter_mag_list.reserve(magazine_list.size());
    std::transform(letter_list.begin(), letter_list.end(), magazine_list.begin(),
                   std::back_inserter(letter_mag_list), [](std::string a, std::string b) {
                    return std::make_pair(a, b); });

    for (auto &test_iter : letter_mag_list) {
        std::cout << "--->>--->> HashTables:: ConstructibleLetter(letter: \"" << test_iter.first << "\", mag: \"" << test_iter.second << "\"): "
                  << std::boolalpha << ht_exerciser->ConstructibleLetter(test_iter.first, test_iter.second) << std::endl;
    }
    assert(!ht_exerciser->ConstructibleLetter("Bastian Schweinsteiger", "Thomas Muller"));
    assert(ht_exerciser->ConstructibleLetter("JumpinJimmy", "JumpinJimmy Is His Name"));
}

void RunTests(std::shared_ptr<HashTableExercises> ht_exerciser) {
    std::cout << "--->>--->> HashTables::RunTests <<---<<--- " << std::endl;
    PermuteToPalindrome(ht_exerciser.get());
    IsLetterConstructible(ht_exerciser.get());
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch13_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HashTableExercises> ht_exerciser(new HashTableExercises());
    RunTests(ht_exerciser);
    return 0;
}
