#include "Film.h"

using namespace std;

//constructors
Film::Film(){
    Video("default_film_name", "default_film_pathname", 0);
    this->setChapters(nullptr, 0);
    this->setType("Film");
}
Film::Film(string const& name, string const& pathname, int const duration, int const* chapters, int const numberOfChapters){
    Video(name, pathname, duration);
    this->setChapters(chapters, numberOfChapters);
    this->setType("Film");
}

//destructor
Film::~Film(){
    delete chapters;
}

//getters
int* Film::getChapters() const{
    int* chaptersCopy = new int [this->getNumberOfChapters()];
    for (int i = 0; i < this->getNumberOfChapters(); i++){
        chaptersCopy[i] = this->chapters[i];
    }
    return chaptersCopy;
}
int Film::getNumberOfChapters() const{
    return this->numberOfChapters;
}

//setter
void Film::setChapters(int const* chapters, int const numberOfChapters){
    delete this->chapters;
    this->numberOfChapters = numberOfChapters;
    this->chapters = new int[this->getNumberOfChapters()];
    for (int i = 0; i < this->getNumberOfChapters(); i++){
        this->chapters[i] = chapters[i];
    }
}

//display the duration of each chapter
void Film::displayChapters(ostream& out) const{
    int* chaptersCopy = this->getChapters(); //we prefer to not access directly to this->chapters
    for (int i = 0; i < this->getNumberOfChapters(); i++){
        out << "Chapter " + to_string(i) + ":" + to_string(chaptersCopy[i]) << endl;
    }
}

//constructor copy
Film::Film(Film const& film) : Video(film), chapters(nullptr), numberOfChapters(0) {
    this->setChapters(film.getChapters(), film.getNumberOfChapters());
}