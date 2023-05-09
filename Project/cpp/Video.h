#ifndef VIDEO_H
#define VIDEO_H

#include "Media.h"

using namespace std;

class Video:public Media{
    private:
        //atributes
        int duration;
    
    public:
        //constructors
        Video():
            Media("default_video_name", "default_video_pathname"), duration(0) {this->setType("Video");};
        Video(string const& name, string const& pathname, int const duration):
            Media(name, pathname), duration(duration) {this->setType("Video");};
        
        Video(Video const& video):
            Media(video), duration(0) {
                this->setType("Video");
                this->setDuration(video.getDuration());
            };
        
        //destructor
        virtual ~Video(){};

        //getters
        int getDuration() const {
            return this->duration;
        };

        //setters
        void setDuration(int const duration){
            this->duration = duration;
        };

        //display information
        void displayInfo(ostream& out) const override {
            Media::displayInfo(out);
            out << "duration:" << this->getDuration() << endl;
        };
    
        //play the video
        void openMedia() const override {
            system(("mpv " + this->getPathname() + " &").data());
        };
};

#endif // VIDEO_H
