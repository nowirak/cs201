/**
 * @file     rangeBasedForLoop.hpp
 * @author   Student Name
 * @version  Feb 14, 2019
 * John Quan
 * @brief  Manipulate elements in vectors
 */

#ifndef VECTOR_MANIP_HPP_
#define VECTOR_MANIP_HPP_

#include <string>
#include <vector>

 /**
  * ADDITIONAL 1
  * Change the first character of each string in the vector using
  * a range-based for-loop:
  *
  *   for ( range_declaration : range_expression ) {
  *       loop_statement
  *   }
  *
  * To actually change the string, the range declaration can also
  * be an alias to the string in the vector.
  *
  * @param strVec vector of strings to change
  * @param c new first letter character.
  */
  //void firstLetterChange(std::vector<std::string> & strVec, const char & c);

  /**
   * ADDITIONAL 2
   * Add strings that user enters from the terminal.  This function
   * separates strings by whitespace by using std::cin.
   *
   * @param strVec vector of strings
   * @param sentinel string to stop on (e.g., "end" or "done")
   */
   //void addUserStrings(std::vector<std::string> & strVec,
   //		const std::string sentinel);

#endif /* VECTOR_MANIP_HPP_ */
