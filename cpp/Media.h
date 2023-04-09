#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

using namespace std;

class Media
{
private:
    //attributes
    string* name;
    string* pathname;

protected:
    //protected type because it's not instantiated at base class
    string* type;

    //protected constructors because we don't want to instantiate from the base class
    Media();
    Media(string const& name, string const& pathname);
    Media(Media const& media);


public:
    //destructor
    virtual ~Media();

    //getters
    string const& getName() const;
    string const& getPathname() const;
    string const& getType() const;

    //setters
    void setName(string const& name);
    void setPathname(string const& pathname);
    virtual void setType(string const& type);

    //display media information
    virtual void displayInfo(ostream& out) const;

    //overloading the display for <<
    friend ostream& operator<<(ostream& out, Media const& media);

    //open the media
    virtual void openMedia() const = 0;

    friend class Table;
};

#endif // MEDIA_H
