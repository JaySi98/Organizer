#pragma once

#include <string>
#include <vector>
#include <Config.h.in>
#include <InfoCollection.h>

class Note
{
private:
    std::string title;
    std::string description;

    std::vector<InfoCollection> lists;

public:
    Note(std::string title, std::string description);
    ~Note(void);

    std::string GetTitle(void);
    std::string GetDescription(void);

    std::vector<InfoCollection> GetAllCollections(void);

    InfoCollection GetCollectionByPosition(int position);
};
