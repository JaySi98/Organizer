#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <Config.h.in>
#include <InfoElement.h>

typedef enum
{
    COLLECTION_TYPE_ITEMS = 1,
    COLLECTION_TYPE_TASKS = 2,
    COLLECTION_TYPE_INFO  = 3,

}CollectionType;

class InfoCollection
{
private:
    std::string title;
    std::string description;
    std::vector<InfoElement> elements;
    CollectionType type;

public:
    InfoCollection(std::string title, std::string description, CollectionType type);
    InfoCollection(std::string title, CollectionType type);
    ~InfoCollection();

    std::string     GetTitle(void);
    std::string     GetDescription(void);

    CollectionType GetCollectionType();
    
    std::vector<InfoElement> GetAllElements(void);
    InfoElement GetElementByPosition(int position);
    void AddElement(InfoElement newElement);
    void RemoveElement(InfoElement targetElement);

};

