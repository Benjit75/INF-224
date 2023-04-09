#include "Group.h"

//constructors
Group::Group(){
    this->setName("default_group_name");
}
Group::Group(string const& name){
    this->setName(name);
}

//getter
string const& Group::getName() const {
    return *(this->name);
}

//seter
void Group::setName(string const& name) {
    this->name = new string(name);
}

//display group information
void Group::displayInfo(ostream& out) const {
    out << "Group:" << this->getName() << endl;
    out << "Medias:" << endl;
    int i = 1;
    for (MediaPtr media : *this) {
        out << "\t" << "¤" << i << ": " << endl;
        out << "\t";
        media->displayInfo(out);
        i++;
    }
}
