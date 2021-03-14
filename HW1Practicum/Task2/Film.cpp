#include "Film.h"

void Film::copy(const Film& otherFilm)
{
    this->title = new char[strlen(otherFilm.title) + 1];
    strcpy_s(this->title, strlen(otherFilm.title) + 1, otherFilm.title);
    this->directorName = new char[strlen(otherFilm.directorName) + 1];
    strcpy_s(this->directorName, strlen(otherFilm.directorName) + 1, otherFilm.directorName);
    this->awardAmount = otherFilm.awardAmount;
}

void Film::erase()
{
    delete[] this->title;
    delete[] this->directorName;
}

Film::Film()
{
    this->title = new char[6];
    strcpy_s(this->title, 6, "Empty");
    this->directorName = new char[6];
    strcpy_s(this->directorName, 6, "Empty");
    this->awardAmount = 0;
}

Film& Film::operator=(const Film& otherFilm)
{
    if (this != &otherFilm)
    {
        this->erase();
        this->copy(otherFilm);
    }
    return *this;
}

Film::Film(const Film& otherFilm)
{
    this->copy(otherFilm);
}

Film::~Film()
{
    this->erase();
}

void Film::setTitle(const char* _title)
{
    delete[] this->title;
    this->title = new char [strlen(_title) + 1];
    strcpy_s(this->title, strlen(_title) + 1, _title);
}

void Film::setDirectorName(const char* _name)
{
    delete[] this->directorName;
    this->directorName = new char [strlen(_name) + 1];
    strcpy_s(this->directorName, strlen(_name) + 1, _name);
}

void Film::setAwardAmount(int amount)
{
    this->awardAmount = amount;
}

const char* Film::getTitle() const
{
    return this->title;
}

const char* Film::getDirectorName() const
{
    return this->directorName;
}

int Film::getAwardAmount() const
{
    return this->awardAmount;
}

void Film::print() const
{
    std::cout << title << std::endl;
    std::cout << directorName << std::endl;
    std::cout << awardAmount << std::endl;
}