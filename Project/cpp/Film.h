#ifndef FILM_H
#define FILM_H

#include "Video.h"

using namespace std;

class Film:public Video{
    private:
        //attributes
        int* chapters;
        int numberOfChapters;
    
    public:
        //constructors
        Film();
        Film(string const& name, string const& pathname, int const duration, int const* chapters, int const numberOfChapters);

        //destructor
        ~Film();

        //getters
        int* getChapters() const;
        int getNumberOfChapters() const;

        //setters
        void setChapters(int const* chapters, int numberOfChapters);

        //display the duration of each chapter
        void displayChapters(ostream& out) const;

        //constructor copy
        Film(Film const& film);
        //auto copy using =
        Film& operator=(Film const& film);
};

#endif // FILM_H
