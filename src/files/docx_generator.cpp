#include "../headers/docx_generator.h"
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include "../../external/DuckX/include/duckx.hpp"

void createDocxFiles(const std::map<std::string, std::unordered_map<std::string, std::vector<std::string>>> & workMap, const int &nbrFiles)
{
    for (int i=0; i<nbrFiles; ++i)
    {

        duckx::Document docxFile ("QCM.docx");
        docxFile.open();
        std::cout << "Create !" << std::endl;
    }
}
