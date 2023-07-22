#include "../headers/xlsx_worker.h"
#include <OpenXLSX.hpp>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <random>


std::string cellToString(const OpenXLSX::XLCellValue &cellToConvert);
std::map<std::string, std::map<std::string, std::vector<std::string>>> extract(const std::string &xlsxFileName);


std::map<std::string, std::unordered_map<std::string, std::vector<std::string>>> getWorkMap(const std::string &xlsxFileName)
{
    std::map<std::string, std::unordered_map<std::string, std::vector<std::string>>> workMap;

    std::random_device randomSeed;
    std::mt19937 quGenerator(randomSeed());
    std::mt19937 anGenerator(randomSeed());

    std::vector<std::string> questionsList;

    int nbr_questions;

    std::map<std::string, std::map<std::string, std::vector<std::string>>> xlsxMap = extract(xlsxFileName);

    for (const auto &sheet : xlsxMap)
    {
        questionsList.clear();

        std::cout << "Nombre de question pour " << sheet.first << ": ";
        std::cin >> nbr_questions;

        for (const auto &question : xlsxMap[sheet.first])
        {
            questionsList.push_back(question.first);
        }
        std::shuffle(questionsList.begin(), questionsList.end(), quGenerator);

        for (int i=0; i < nbr_questions; ++i)
        {
            std::shuffle(xlsxMap[sheet.first][questionsList[0]].begin(), xlsxMap[sheet.first][questionsList[0]].end(), anGenerator);
            workMap[sheet.first][questionsList[0]] = xlsxMap[sheet.first][questionsList[0]];
            questionsList.erase(questionsList.begin());
        }
    }

    return workMap;
}



std::map<std::string, std::map<std::string, std::vector<std::string>>> extract(const std::string &xlsxFileName)
{
    const OpenXLSX::XLDocument xlsxFile (xlsxFileName+".xlsx");

    std::map<std::string, std::map<std::string, std::vector<std::string>>> xlsxMap;

    std::map<std::string, std::vector<std::string>> sheetMap;
    std::vector<std::string> questionsVector;

    bool firstIteration;
    bool newQuestion;

    std::string question;

    const std::vector<std::string> sheetNameList = xlsxFile.workbook().worksheetNames();

    OpenXLSX::XLWorksheet currentWorksheet;
    OpenXLSX::XLCell cell;

    std::string stringCell;

    for (const auto &sheetName : sheetNameList)
    {
        firstIteration = true;
        newQuestion = true;

        currentWorksheet = xlsxFile.workbook().worksheet(sheetName);

        sheetMap.clear();

        for (int row=1; row<=currentWorksheet.rowCount(); ++row)
        {
            for (int column=1; column<=currentWorksheet.columnCount(); ++column)
            {
                cell = currentWorksheet.cell(row, column);
                stringCell = cellToString(cell.value());

                if (newQuestion)
                {
                    question = stringCell;
                    newQuestion = false;
                }

                if (firstIteration)
                {
                    firstIteration = false;
                    newQuestion = true;
                }
                else if (std::isdigit(stringCell[0]))
                {
                    newQuestion = true;

                    for (int i=0; i<=1; ++i)
                    {
                        questionsVector.erase(questionsVector.begin());
                    }

                    sheetMap[question] = questionsVector;
                    questionsVector.clear();
                }

                if (!std::empty(stringCell))
                {
                    questionsVector.push_back(stringCell);
                }
            }
        }

        newQuestion = true;

        for (int i=0; i<=1; ++i)
        {
            questionsVector.erase(questionsVector.begin());
        }

        sheetMap[question] = questionsVector;
        questionsVector.clear();

        xlsxMap[sheetName] = sheetMap;
    }

    return xlsxMap;
}



std::string cellToString(const OpenXLSX::XLCellValue &cellToConvert)
{
    switch (cellToConvert.type())
    {
        case OpenXLSX::XLValueType::String:
        {
            return cellToConvert;
        }

        case OpenXLSX::XLValueType::Boolean:
        {
            bool boolValue = cellToConvert;
            return boolValue ? "Vrai" : "Faux";
        }

        case OpenXLSX::XLValueType::Error:
        {
            return "Error !";
        }

        case OpenXLSX::XLValueType::Empty:
        {
            return "";
        }

        case OpenXLSX::XLValueType::Integer:
        {
            int intCell = cellToConvert;
            return std::to_string(intCell);;
        }

        case OpenXLSX::XLValueType::Float:
        {
            float floatCell = cellToConvert;
            return std::to_string(floatCell);
        }

        default:
        {
            return "Not Converted";
        }
    }
}
