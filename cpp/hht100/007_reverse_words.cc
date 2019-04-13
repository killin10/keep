//
// @file 007_reverse_words.cc
// @brief Reverse all the words in the given sentence.
//   e.g. "I am a student.", after processing, "student. a am I".
// 
// @version 1.0
// @date Sun Jun  9 18:19:27 2013
// 
// @copyright Copyright (C) 2013
// @author weishih<shiwei2012@gmail.com>
//

#include <iostream>

#include <assert.h>

void Reverse(char* left, char* right) {
  assert(left != NULL && right != NULL);
  assert(left <= right);

  char tmp = '\0';
  for (; left < right; ++left, --right) {
    tmp = *left;
    *left = *right;
    *right = tmp;
  }
}

void ReverseSentence(char* left, char* right) {
  // Reverse the whole string.
  Reverse(left, right);

  // Reverse each word.
  const char kBlankChar = ' ';
  //const char kNullChar = '\0';
  char* word_begin = left;
  char* word_end = left;
  for (char* blank_pos = left; blank_pos <= right; ++blank_pos) {
    if (kBlankChar == *blank_pos) {
      word_end = blank_pos - 1;
      Reverse(word_begin, word_end);
      word_begin = blank_pos + 1;
    }
  }

  // Reverse the last word back.
  word_end = right;
  Reverse(word_begin, word_end);
}

int main(int argc, char* argv[]) {
  char sentence[] = "You are a student.";
  std::cout << sentence << std::endl;

  int size = sizeof(sentence) / sizeof(char);
  ReverseSentence(sentence, sentence + size - 2);
  std::cout << sentence << std::endl;

  return 0;
}

