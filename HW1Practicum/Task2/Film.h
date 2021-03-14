#pragma once
#include <iostream>
#include <cstring>

class Film
{
private:
    char* title;
    char* directorName;
    int awardAmount;
public:
    Film();
    Film& operator=(const Film& otherFilm);
    Film(const Film& otherFilm);
    ~Film();

    void setTitle(const char* _title);
    void setDirectorName(const char* _name);
    void setAwardAmount(int amount);

    const char* getTitle() const;
    const char* getDirectorName() const;
    int getAwardAmount() const;

    void print() const;

private:
    void copy(const Film& otherFilm);
    void erase();
};