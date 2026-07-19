#pragma once
#include <string>
#include <ostream>

class Media {

    protected:
        std::string title;
        int personalRating;
        bool watched;

    public:
        virtual std::string getType() const = 0;
        virtual ~Media() = default;

    // Constructors

    Media(const std::string& title, int personalRating, bool watched)
        : title(title), personalRating(personalRating), watched(watched) {}

    // Copy constructor

    Media(const Media& other)
        : title(other.title), personalRating(other.personalRating), watched(other.watched) {}

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
    
    std::string getTitle() const {
        return title;
    }

    int getPersonalRating() const {
        return personalRating;
    }

    bool isWatched() const {
        return watched;
    }

    friend std::ostream& operator<<(std::ostream& os, const Media& m) {
        os << "  \033[2;1m[" << m.getType() << "]\033[0m "
           << "\033[1m" << m.getTitle() << "\033[0m"
           << " | watched: " << (m.isWatched() ? "Yes" : "No")
           << " | rating: " << m.getPersonalRating()
           << "\n";
        return os;
    }
};