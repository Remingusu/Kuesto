#include "src/headers/docx_generator.h"
#include "src/headers/xlsx_worker.h"
#include "src/headers/interface.h"
#include <iostream>
#include <string>

int main()
{
    std::string xlsxFileName;
    int nbrFiles;
    std::cout << "Nom du fichier: ";
    std::cin >> xlsxFileName;
    std::cout << "Nombre de fichier: ";
    std::cin >> nbrFiles;

    const auto workMap = getWorkMap(xlsxFileName);

    for (const auto &sheetKey : workMap)
    {
        std::cout << std::endl << sheetKey.first;
        for (const auto &questionKey : sheetKey.second)
        {
            std::cout << std::endl << questionKey.first;
            for (const auto &element : questionKey.second)
            {
                std::cout << " --- " << element;
            }
        }
    }

    createDocxFiles(workMap, nbrFiles);

    return 0;
}
