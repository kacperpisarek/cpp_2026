#pragma once
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "Media.h"
#include "Serial.h"

class MediaList {

    protected:
        std::vector<std::unique_ptr<Media>> media;

    public:

        MediaList() 
            : media() {}

        // Setters

        void addMedia(std::unique_ptr<Media> mediaItem) {
            auto it = std::find_if(media.begin(), media.end(),
                [&mediaItem](const std::unique_ptr<Media>& m) {
                    return m->getTitle() == mediaItem->getTitle();
                });
            if (it != media.end()) {
                std::cerr << "Error: Media with title '" << mediaItem->getTitle() << "' already exists.\n";
                return;
            }
            media.push_back(std::move(mediaItem));
        }

        void removeMedia(const std::string& title) {

            // Use std::remove_if to find the media item by title
            auto it = std::remove_if(media.begin(), media.end(),
                [&title](const std::unique_ptr<Media>& mediaItem) {
                    return mediaItem->getTitle() == title;
                });
            if (it != media.end()) {
                media.erase(it, media.end());
            } else {
                std::cerr << "Error: Media with title '" << title << "' not found.\n";
                return;
            }
        }

        // Getters

        int countWatched() const {
            int count = 0;
            for (const auto& mediaItem : media) {
                if (mediaItem->isWatched()) {
                    count++;
                }
            }
            return count;
        }

        const std::vector<std::unique_ptr<Media>>& getMedia() const {
            return media;
        }

        Media* findMediaByTitle(const std::string& title) const {

            // Use std::find_if to find the media item by title
            auto it = std::find_if(media.begin(), media.end(),
                [&title](const std::unique_ptr<Media>& mediaItem) {
                    return mediaItem->getTitle() == title;
                });
            if (it != media.end()) {
                return it->get();
            } else {
                std::cerr << "Error: Media with title '" << title << "' not found.\n";
                return nullptr;
            }
        }

        void printMediaList() const {
            
            // Check if the media list is empty
            if (media.empty()) {
                std::cout << ">>> No media in the list.\n";
                return;
            }

            // Print the media list
            for (const auto& mediaItem : media) {

                // Print media information
                std::cout << *mediaItem;

                Serial* serial = dynamic_cast<Serial*>(mediaItem.get());
                
                // If media is Serial print its episodes and seasons
                if (serial) {
                    // Print seasons and episodes for serials
                    for (const auto& season : serial->getSeasons()) {
                        std::cout << season;
                        for (const auto& ep : season.getEpisodes()) {
                            std::cout << "  " << ep;
                        }
                    }
                    // Print episodes that are not part of any season
                    for (const auto& ep : serial->getEpisodes()) {
                        std::cout << ep;
                    }
                }
            }
        }
};