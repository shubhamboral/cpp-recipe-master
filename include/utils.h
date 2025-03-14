#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// Utility function to join a vector into a single string with a given separator
std::string join(const std::vector<std::string> &elements, const std::string &separator = ", ");

// Utility function to split a string into a vector based on a delimiter
std::vector<std::string> split(const std::string &str, char delimiter);

#endif // UTILS_H
