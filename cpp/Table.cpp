#include "Media.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Table.h"

#include <iostream>
#include <map>
#include <memory>

using namespace std;
typedef std::shared_ptr<Media> MediaPtr;
typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;

//constructor
Table::Table() {};

//methods to create different media objects and groups
PhotoPtr Table::createPhoto(){
    PhotoPtr newPhoto = make_shared<Photo>();
    this->mediaMap[newPhoto->getName()] = newPhoto;
    return newPhoto;
}

PhotoPtr Table::createPhoto(string const& name, string const& pathname, int const latitude, int const longitude){
    PhotoPtr newPhoto = make_shared<Photo>(name, pathname, latitude, longitude);
    this->mediaMap[newPhoto->getName()] = newPhoto;
    return newPhoto;
}

VideoPtr Table::createVideo(){
    VideoPtr newVideo = make_shared<Video>();
    this->mediaMap[newVideo->getName()] = newVideo;
    return newVideo;
}

VideoPtr Table::createVideo(string const& name, string const& pathname, int const duration){
    VideoPtr newVideo = make_shared<Video>(name, pathname, duration);
    this->mediaMap[newVideo->getName()] = newVideo;
    return newVideo;
}

FilmPtr Table::createFilm(){
    FilmPtr newFilm = make_shared<Film>();
    this->mediaMap[newFilm->getName()] = newFilm;
    return newFilm;
}

FilmPtr Table::createFilm(string const& name, string const& pathname, int const duration, int const* chapters, int const numberOfChapters){
    FilmPtr newFilm = make_shared<Film>(name, pathname, duration, chapters, numberOfChapters);
    this->mediaMap[newFilm->getName()] = newFilm;
    return newFilm;
}

GroupPtr Table::createGroup(){
    GroupPtr newGroup = make_shared<Group>();
    this->groupMap[newGroup->getName()] = newGroup;
    return newGroup;
}

GroupPtr Table::createGroup(string const& name){
    GroupPtr newGroup = make_shared<Group>(name);
    this->groupMap[newGroup->getName()] = newGroup;
    return newGroup;
}

void Table::searchAndDisplayGroup(string const name, ostream& out) const {
    auto groupIt = this->groupMap.find(name);
    if (groupIt != this->groupMap.end()){
        groupIt->second->displayInfo(out);
    } else {
        out << "No result for Group named : \"" << name << "\"." <<endl;
    }
}
void Table::searchAndDisplayMedia(string const name, ostream& out) const {
    auto mediaIt = this->mediaMap.find(name);
    if (mediaIt != this->mediaMap.end()){
        mediaIt->second->displayInfo(out);
    } else {
        out << "No result for Media named : \"" << name << "\"." <<endl;
    }
}

void Table::play(string const name) const {
    auto mediaIt = this->mediaMap.find(name);
    if (mediaIt != this->mediaMap.end()){
        mediaIt->second->openMedia();
    }
}