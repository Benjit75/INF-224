#ifndef PHOTO_H
#define PHOTO_H

#include "Media.h"

using namespace std;

class Photo:public Media{
    private:
        //attributes
        int latitude, longitude;
    
    public:
        //constructors
        Photo():
            Media("default_photo_name", "default_photo_pathname"), latitude(0), longitude(0) {this->setType("Photo");};
        Photo(string const& name, string const& pathname, int const latitude, int const longitude):
            Media(name, pathname), latitude(latitude), longitude(longitude) {this->setType("Photo");};
        
        //destructor
        virtual ~Photo() {};

        //getters
        int getLatitude() const {
            return this->latitude;
        };
        int getLongitude() const {
            return this->longitude;
        };

        //setters
        void setLatitude(int const latitude) {
            this->latitude = latitude;
        };
        void setPathname(int const longitude) {
            this->longitude = longitude;
        };

        //display information
        void displayInfo(ostream& out) const override {
            Media::displayInfo(out);
            out << "latitude:" << this->getLatitude() << endl;
            out << "longitude:" << this->getLongitude() << endl;
        };

        //display the photo
        void openMedia() const override {
            system(("imagej " + this->getPathname() + " &").data());
        };

};

#endif // PHOTO_H
