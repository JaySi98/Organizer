#pragma once

#include <string>
#include <ctime>
#include <Config.h.in>

class InfoElement
{
private:
    std::string title;
    std::string description;
    time_t creationDate;

    void UpdateDate(void);

public:
    InfoElement(std::string title, std::string description);
    InfoElement(std::string title);
    ~InfoElement();

    std::string GetTitle(void);
    std::string GetDescription(void);
    time_t      GetCreationDate(void);

    void SetTitle(std::string title);
    void SetDescription(std::string description);
};

