//
// Created by profe on 12/03/2024.
//

#ifndef SHAREPOINT_SHAREPOINT_H
#define SHAREPOINT_SHAREPOINT_H

#endif //SHAREPOINT_SHAREPOINT_H

#include <iostream>
#include <string>
#include <tuple>

class Sharepoint{

public:
    Sharepoint(const std::string& sharepoint_url, const std::string& username,
               const std::string& password, const std::string& root_url);

    ~ Sharepoint();

    void download_file_type(const std::string& folder_name,
                            const std::tuple<std::string>& file_types);

    void convert_files_to_excel(const std::string& folderPath,
                                const std::tuple<std::string>& extension_list);

private:
    std::string sharepoint_url;
    std::string username;
    std::string password;
    std::string root_url;





};
