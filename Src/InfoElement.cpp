#include <InfoElement.h>

InfoElement::InfoElement(std::string title, std::string description)
{
    this->title = title;
    this->description = description;
    this->creationDate = std::time(0);    
}

InfoElement::InfoElement(std::string title)
{
    this->title = title;
    this->description = DEFAULT_STRING_VALUE;
    this->creationDate = std::time(0);
}

InfoElement::~InfoElement() { }

std::string InfoElement::GetTitle(void)
{
    return this->title;
}

void InfoElement::SetTitle(std::string title)
{
    this->title = title;

    UpdateDate();
}

std::string InfoElement::GetDescription(void)
{
    return this->description;
}

void InfoElement::SetDescription(std::string description)
{
    this->description = description;

    UpdateDate();
}

time_t InfoElement::GetCreationDate(void)
{
    return this->creationDate;    
}

void InfoElement::UpdateDate(void)
{
    this->creationDate = std::time(0);
}



