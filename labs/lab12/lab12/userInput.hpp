/**
 * @file     userInput.hpp
 * @author   Student Name
 * @version  Feb 12, 2019
 * John Quan
 *
 * Library of string manipulation functions.
 */

#ifndef USERINPUT_HPP_
#define USERINPUT_HPP_

#include <vector>
#include <string>

 /**
  * REQUIRED
  * Add user strings to a string vector until the user types "end".
  * @param words string vector
  */
void getUserStrings(std::vector<std::string>& words);

/**
 * ADDITIONAL
 * Determine whether a string contains a certain character.
 * @param str string to check
 * @param c character to find
 * @return True if the string contains the character.
 */
 //bool hasChar(const std::string & str, const char & c);

#endif /* USERINPUT_HPP_ */
