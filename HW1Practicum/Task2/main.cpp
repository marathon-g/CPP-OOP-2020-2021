#include <iostream>
#include "Film.h"

int main()
{
    Film film;
    film.setTitle("My film");
    film.setDirectorName("Me");
    film.setAwardAmount(200);
    film.print();
}