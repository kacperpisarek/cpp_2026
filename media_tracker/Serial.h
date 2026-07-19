#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Episode.h"
#include "Season.h"
#include "Media.h"

class Serial : public Media {
    
    protected:
    
        std::vector<Season> seasons;
        std::vector<Episode> episodes;

    public:

    // Constructors

    Serial(const std::string& title, int personalRating, bool watched)
        : Media(title, personalRating, watched) {}

    Serial(const std::string& title, int personalRating)
        : Media(title, personalRating, false) {}

    Serial(const std::string& title, bool watched)
        : Media(title, 0, watched) {}

    Serial(const std::string& title)
        : Media(title, 0, false) {}

    // Copy constructor

    Serial(const Serial& other)
        : Media(other), seasons(other.seasons), episodes(other.episodes) {}

    // Setters

    void addSeason(const Season& season) {
        for (const auto& s : seasons) {
            if (s.getNumber() == season.getNumber()) {
                std::cerr << "Season " << season.getNumber() << " already exists in serial '" << getTitle() << "'.\n";
                return;
            }
        }
        seasons.push_back(season);
    }

    void removeSeason(int seasonNumber) {
        for (auto it = seasons.begin(); it != seasons.end(); ++it) {
            if (it->getNumber() == seasonNumber) {
                seasons.erase(it);
                break;
            }
        }
    }

    void addEpisode(const Episode& episode) {
        for (const auto& ep : episodes) {
            if (ep.getNumber() == episode.getNumber()) {
                std::cerr << "Episode " << episode.getNumber() << " already exists in serial '" << getTitle() << "'.\n";
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
    
    std::string getType() const override {
        return "Serial";
    }

    const std::vector<Season>& getSeasons() const {
        return seasons;
    }

    const std::vector<Episode>& getEpisodes() const {
        return episodes;
    }

    std::vector<Season>& getSeasons() {
        return seasons;
    }

    std::vector<Episode>& getEpisodes() {
        return episodes;
    }
};