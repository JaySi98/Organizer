#include <InfoCollection.h>

InfoCollection::InfoCollection(std::string title, std::string description, CollectionType type)
{
    this->title = title;
    this->description = description;
    this->type = type;
}

InfoCollection::InfoCollection(std::string title, CollectionType type)
{
    this->title = title;
    this->description = DEFAULT_STRING_VALUE;
    this->type = type;
}

InfoCollection::~InfoCollection() { }

std::string InfoCollection::GetTitle(void)
{
    return this->title;
}

std::string InfoCollection::GetDescription(void)
{
    return this->description;
}

CollectionType InfoCollection::GetCollectionType()
{
    return this->type;
}

std::vector<InfoElement> InfoCollection::GetAllElements(void)
{
    return this->elements;
}

InfoElement InfoCollection::GetElementByPosition(int position)
{
    try
    {
        InfoElement element = this->elements[position];
        return element;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
}

void InfoCollection::AddElement(InfoElement newElement)
{
    this->elements.push_back(newElement);
}

void InfoCollection::RemoveElement(InfoElement targetElement)
{
    try
    {
        // for (std::vector<InfoElement>::iterator it = this->elements.begin(); it != this->elements.end(); ) 
        // {
        //     if (it == targetElement) 
        //     {
        //         it = this->elements.erase(it);
        //     } else 
        //     {
        //         ++it;
        //     }
        // }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }   
}
