#pragma once
#include <string>
#include <ostream>

class Episode {
    
    protected:
        int number;
        std::string title;
        bool watched;
        int personalRating;

    public:

    // Constructors

    Episode(int number, const std::string& title, bool watched, int personalRating)
    : number(number), title(title), watched(watched), personalRating(personalRating) {}

    Episode(int number, const std::string& title, bool watched)
    : number(number), title(title), watched(watched), personalRating(0) {}

    Episode(int number, const std::string& title, int personalRating)
    : number(number), title(title), watched(false), personalRating(personalRating) {}

    Episode(int number, const std::string& title)
    : number(number), title(title), watched(false), personalRating(0) {}

    // Copy constructor

    Episode(const Episode& other)
    : number(other.number), title(other.title),
      watched(other.watched), personalRating(other.personalRating) {}

    // Setters

    void markAsWatched() {
        watched = true;
    }

    void markAsUnwatched() {
        watched = false;
    }

    void setPersonalRating(int rating) {
        personalRating = rating;
    }

    // Getters

    bool isWatched() const {
        return watched;
    }

    int getNumber() const {
        return number;
    }

    std::string getTitle() const {
        return title;
    }

    int getPersonalRating() const {
        return personalRating;
    }

    friend std::ostream& operator<<(std::ostream& os, const Episode& ep) {
        os << "    \033[2mEp." << ep.getNumber() 
           << "\033[0m"
           << "\033[1m"
           << " " << ep.getTitle()
           << "\033[0m"
           << " | watched: " << (ep.isWatched() ? "Yes" : "No")
           << " | rating: " << ep.getPersonalRating()
           << "\n";
        return os;
    }
};