#ifndef NEWKUESTO_XLSX_WORKER_H
#define NEWKUESTO_XLSX_WORKER_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

std::map<std::string, std::unordered_map<std::string, std::vector<std::string>>> getWorkMap(const std::string &xlsxFileName);

#endif //NEWKUESTO_XLSX_WORKER_H
