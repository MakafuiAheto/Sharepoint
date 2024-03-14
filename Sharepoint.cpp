//
// Created by profe on 12/03/2024.
//

#include "Sharepoint.h"
#include <utility>
#include <filesystem>
#include <fstream>
#include <cmath>

template<typename T, class Lambda>
constexpr bool any_of_impl(std::vector<T> &&tup, Lambda lambda, int iterator=0){
    return lambda(tup.at(iterator))||
                    any_of_impl(std::forward<std::vector<std::string>>(tup),lambda, iterator+1);
}


SharepointHandler::Sharepoint_Exception::Sharepoint_Exception(char *error_message): error_message(error_message){}

const char *SharepointHandler::Sharepoint_Exception::what() noexcept {
    return this->error_message;
}

SharepointHandler::Sharepoint::Sharepoint(std::string sharepoint_url, std::string username,
                            std::string password,
                            std::string  root_url): sharepoint_url(std::move(sharepoint_url)),
                            username(std::move(username)), password(std::move(password)),
                            root_url(std::move(root_url)){}


[[maybe_unused]] void SharepointHandler::Sharepoint::write_to_new_sheet(const std::string &sheet_name, char delimiter,
                                                       OpenXLSX::XLDocument &excel_document, std::ifstream& stream) {

    int iterator = 1;
    std::string line;
    excel_document.workbook().addWorksheet(sheet_name);
    OpenXLSX::XLWorksheet worksheet = excel_document.workbook().worksheet(sheet_name);

    while(std::getline(stream, line )){

        std::vector<std::string> row_values;
        std::stringstream shared_stream(line);

        while( std::getline(shared_stream, line , delimiter)){
            row_values.push_back(std::move(line));
        }
        worksheet.row(iterator).values() = row_values;
        ++iterator;
    }

}

void SharepointHandler::Sharepoint::convert_text_files_to_excel(const std::string &folderPath,
                                        std::set<std::string> &extension_list, char delimiter) {

    std::srand(std::time(nullptr));
    int randomNumber = std::rand();

    OpenXLSX::XLDocument excelDocument;
    excelDocument.create(folderPath + "/Data" + std::to_string(randomNumber)  + ".xlsx" );

    std::vector<std::filesystem::directory_entry> fileEntries;
    
    for(const auto & entry: std::filesystem::directory_iterator(folderPath)){

        auto file_path = std::make_unique<std::string>(entry.path().string());
        auto file_extension = std::make_unique<std::string>(entry.path().extension().string());

        if(!entry.is_directory() &&
        extension_list.find(*std::move(file_extension)) != extension_list.end()){
            std::ifstream filestream(*std::move(file_path));

            if(filestream.is_open()){
                write_to_new_sheet(entry.path().stem().string(), delimiter, excelDocument, filestream);
            }

        }
    }

    excelDocument.save();
    excelDocument.close();

}

void SharepointHandler::Sharepoint::download_file_type(const std::string &folder_name,
                                    const std::tuple<std::string> &file_types) {

}

SharepointHandler::Sharepoint::~Sharepoint() = default;


