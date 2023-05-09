#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <memory>
#include "Media.h"
#include "Group.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

using namespace std;
typedef std::shared_ptr<Media> MediaPtr;
typedef std::shared_ptr<Group> GroupPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;

class Table
{
private:
    //map to store all the media objects
    map<string, MediaPtr> mediaMap;
    //map to store all the group objects
    map<string, GroupPtr> groupMap;

public:
    //constructor
    Table();

    //methods to create different media objects and groups
    PhotoPtr createPhoto();
    PhotoPtr createPhoto(string const& name, string const& pathname, int const latitude, int const longitude);
    VideoPtr createVideo();
    VideoPtr createVideo(string const& name, string const& pathname,int const duration);
    FilmPtr createFilm();
    FilmPtr createFilm(string const& name, string const& pathname, int const duration, int const* chapters, int const numberOfChapters);
    GroupPtr createGroup();
    GroupPtr createGroup(string const& name);

    //method to search and display media or group based on name
    void searchAndDisplayGroup(string const name, ostream& stream) const;
    void searchAndDisplayMedia(string const name, ostream& stream) const;


    //method to play media based on name
    void play(string const name) const;
};

#endif // TABLE_H
