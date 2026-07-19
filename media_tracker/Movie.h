#pragma once
#include <string>
#include "Media.h"

class Movie : public Media {
    
    public:

        // Constructors

        Movie(const std::string& title, int personalRating, bool watched)
            : Media(title, personalRating, watched) {}

        Movie(const std::string& title, int personalRating)
            : Media(title, personalRating, false) {}

        Movie(const std::string& title, bool watched)
            : Media(title, 0, watched) {}

        Movie(const std::string& title)
            : Media(title, 0, false) {}

        // Copy constructor

        Movie(const Movie& other)
            : Media(other) {}

        // Getters

        std::string getType() const override {
            return "Movie";
        }
};