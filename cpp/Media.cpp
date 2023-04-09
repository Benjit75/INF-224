#include "Media.h"

using namespace std;

//constructors
Media::Media(){
    this->setName("default_media_name");
    this->setPathname("default_path/default_media_name");
}
Media::Media(string const& name, string const& pathname) {
    this->setName(name);
    this->setPathname(pathname);
}
Media::Media(Media const& media) {
    this->setName(media.getName());
    this->setPathname(media.getPathname());
}

//destructor
Media::~Media(){};

//getters
string const& Media::getName() const {
    return *(this->name);
}
string const& Media::getPathname() const{
    return *(this->pathname);
}
string const& Media::getType() const{
    return *(this->type);
}

//setters
void Media::setName(const string& name){
    this->name = new string(name);
}
void Media::setPathname(const string& pathname) {
    this->pathname = new string(pathname);
}
void Media::setType(const string& type){
    this->type = new string(type);
}

//display media information
void Media::displayInfo(ostream & out) const{
    out << "type: " << this->getType() << endl;
    out << "name: " << this->getName() << endl;
    out <<"pathname: " << this->getPathname() << endl;
}

//overloading the display for <<
ostream& operator<<(ostream& out, Media const& media) {
    media.displayInfo(out);
    return out;
}
