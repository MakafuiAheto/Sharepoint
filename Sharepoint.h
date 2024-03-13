//
// Created by profe on 12/03/2024.
//

#ifndef SHAREPOINT_SHAREPOINT_H
#define SHAREPOINT_SHAREPOINT_H

#endif //SHAREPOINT_SHAREPOINT_H

#include <iostream>
#include <string>
#include <tuple>
#include <exception>
#include <set>

namespace SharepointHandler{

    class Sharepoint {

    public:
        Sharepoint(std::string sharepoint_url, std::string username,
                   std::string password, std::string root_url);

        ~ Sharepoint();

        void download_file_type(const std::string &folder_name,
                                const std::tuple<std::string> &file_types);

        static void convert_text_files_to_excel(const std::string &folderPath,
                                           std::set<std::string> &extension_list);

    private:
        std::string sharepoint_url;
        std::string username;
        std::string password;
        std::string root_url;


    };


class Sharepoint_Exception: public std::exception{

public:
    explicit Sharepoint_Exception(char * error_message);
    virtual const char* what() noexcept;

private:
    char* error_message;

};



};
