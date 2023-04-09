#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include "Media.h"

using namespace std;
typedef std::shared_ptr<Media> MediaPtr;

class Group: public list<MediaPtr>
{
private:
    //attributes
    string* name;

public:
    //constructors
    Group();
    Group(string const& name);

    //getter
    string const& getName() const;

    //setter
    void setName(string const& name);

    //display group information
    void displayInfo(ostream& out) const;
};

#endif // GROUP_H
