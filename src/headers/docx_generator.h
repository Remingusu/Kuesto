#ifndef NEWKUESTO_DOCX_GENERATOR_H
#define NEWKUESTO_DOCX_GENERATOR_H

#include <unordered_map>
#include <map>
#include <vector>
#include <string>

void createDocxFiles(const std::map<std::string, std::unordered_map<std::string, std::vector<std::string>>> & workMap, const int &nbrFiles);

#endif //NEWKUESTO_DOCX_GENERATOR_H
