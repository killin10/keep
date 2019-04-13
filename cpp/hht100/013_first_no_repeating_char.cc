//
// @file 013_first_no_repeating_char.cc
// @brief Find the first no repeating char.
// 
// @version 1.0 
// @date Thu Jun 13 11:38:52 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>
#include <tr1/unordered_map>

void FindFirstNoRepeatingChar(const char* str) {
  std::tr1::unordered_map<char, int> char_count_map;
  std::tr1::unordered_map<char, int>::iterator it;
  for (const char* pos = str; *pos != '\0'; ++pos) {
    it = char_count_map.find(*pos);
    if (char_count_map.end() == it) {
      char_count_map.insert(std::make_pair(*pos, 1));
    } else {
      ++char_count_map[*pos];
    }
  }

  for (const char* pos = str; *pos != '\0'; ++pos) {
    it = char_count_map.find(*pos);
    if (1 == it->second) {
      std::cout << "first no-repeating char: " << it->first << std::endl;
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  const char* str = "abaccdeff";
  std::cout << str << std::endl;
  FindFirstNoRepeatingChar(str);
  return 0;
}


