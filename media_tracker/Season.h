#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include "Episode.h"

class Season {

    protected:
    
        int number;
        std::string title;
        std::vector<Episode> episodes;
    
    public:

    // Constructors

    Season(int number, const std::string& title)
        : number(number), title(title) {}

    Season(int number)
        : number(number), title("") {}

    // Copy constructor

    Season(const Season& other)
        : number(other.number), title(other.title), episodes(other.episodes) {}

    // Setters

    void addEpisode(const Episode& episode) {
        for (const auto& ep : episodes) {
            if (ep.getNumber() == episode.getNumber()) {
                std::cerr << "Episode " << episode.getNumber() << " already exists in season " << number << ".\n";
                return;
            }
        }
        episodes.push_back(episode);
    }

    void removeEpisode(int episodeNumber) {
        for (auto it = episodes.begin(); it != episodes.end(); ++it) {
            if (it->getNumber() == episodeNumber) {
                episodes.erase(it);
                break;
            }
        }
    }

    // Getters

    int getNumber() const {
        return number;
    }

    std::string getTitle() const {
        return title;
    }

    const std::vector<Episode>& getEpisodes() const {
        return episodes;
    }

    friend std::ostream& operator<<(std::ostream& os, const Season& s) {
        os << "    \033[2mSeason " << s.getNumber() << "\033[0m"
           << (s.getTitle().empty() ? "" : " - " + s.getTitle())
           << "\n";
        return os;
    }
};