#include <Note.h>

Note::Note(std::string title, std::string description)
{
    this->title = title;
    this->description = description;
}

Note::~Note(void){ }

std::string Note::GetTitle(void)
{
    return this->title;
}

std::string Note::GetDescription(void)
{
    return this->description;
}


std::vector<InfoCollection> Note::GetAllCollections(void)
{
    return this->lists;
}

InfoCollection Note::GetCollectionByPosition(int position)
{
    try
    {
        InfoCollection collection = this->lists[position];
        return collection;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
}