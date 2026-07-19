#include "MediaList.h"
#include "Movie.h"
#include "Serial.h"
#include <iostream>
#include <limits>

int main() {
    MediaList mediaList;

    auto readInt = [](int& val) -> bool {
        if (!(std::cin >> val)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return true;
    };

    while(true) {
        std::cout << "---------------------\n1. Add Movie\n";
        std::cout << "2. Add Serial\n";
        std::cout << "3. Add Season to Serial\n";
        std::cout << "4. Add Episode to Serial\n";
        std::cout << "5. Remove Season from Serial\n";
        std::cout << "6. Remove Episode from Serial\n";
        std::cout << "7. Add Episode to Season\n";
        std::cout << "8. Remove Episode from Season\n";
        std::cout << "9. Remove Media\n";
        std::cout << "10. Edit Media\n";
        std::cout << "11. Print Media List\n";
        std::cout << "12. Exit\n";
        int choice;
        std::cout << "\nChoose an option: ";
        if (!readInt(choice)) {
            std::cerr << "Expected a number.\n";
            continue;
        }
        std::cout << "---------------------\n";

        if (choice == 1) {
            std::string title;
            int rating;
            bool watched;

            std::cout << "Enter movie title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Have you watched the movie? (1-yes, 0-no): ";
            int watchedVal1;
            if (!readInt(watchedVal1)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            watched = watchedVal1 != 0;
            if (watched) {
                std::cout << "Enter your personal rating (1-10): ";
                if (!readInt(rating)) {
                    std::cerr << "Expected a number.\n";
                    continue;
                }
            } else {
                rating = 0;
            }
            mediaList.addMedia(std::make_unique<Movie>(title, rating, watched));
        }

        if (choice == 2) {
            std::string title;
            int rating;
            bool watched;

            std::cout << "Enter serial title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Have you watched the serial? (1-yes, 0-no): ";
            int watchedVal2;
            if (!readInt(watchedVal2)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            watched = watchedVal2 != 0;
            if (watched) {
                std::cout << "Enter your personal rating (1-10): ";
                if (!readInt(rating)) {
                    std::cerr << "Expected a number.\n";
                    continue;
                }
            } else {
                rating = 0;
            }
            mediaList.addMedia(std::make_unique<Serial>(title, rating, watched));
        }

        if (choice == 3) {
            std::string serialTitle;
            int seasonNumber;
            std::string seasonTitle;

            std::cout << "Enter serial title to add a season: ";
            std::cin.ignore();
            std::getline(std::cin, serialTitle);
            std::cout << "Enter season number: ";
            if (!readInt(seasonNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            std::cin.ignore();
            std::cout << "Enter season title (optional): ";
            std::getline(std::cin, seasonTitle);

            try {
                Media* mediaItem = mediaList.findMediaByTitle(serialTitle);
                Serial* serial = dynamic_cast<Serial*>(mediaItem);
                if (serial) {
                    serial->addSeason(Season(seasonNumber, seasonTitle));
                } else {
                    throw std::runtime_error("Media with title '" + serialTitle + "' is not a Serial.");
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 4) {
            std::string serialTitle;
            int episodeNumber;
            std::string episodeTitle;
            bool watched;
            int rating;

            std::cout << "Enter serial title to add an episode: ";
            std::cin.ignore();
            std::getline(std::cin, serialTitle);
            std::cout << "Enter episode number: ";
            if (!readInt(episodeNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            std::cin.ignore();
            std::cout << "Enter episode title: ";
            std::getline(std::cin, episodeTitle);
            std::cout << "Have you watched the episode? (1-yes, 0-no): ";
            int watchedVal4;
            if (!readInt(watchedVal4)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            watched = watchedVal4 != 0;
            if (watched) {
                std::cout << "Enter your personal rating (1-10): ";
                if (!readInt(rating)) {
                    std::cerr << "Expected a number.\n";
                    continue;
                }
            } else {
                rating = 0;
            }

            try {
                Media* mediaItem = mediaList.findMediaByTitle(serialTitle);
                Serial* serial = dynamic_cast<Serial*>(mediaItem);
                if (serial) {
                    serial->addEpisode(Episode(episodeNumber, episodeTitle, watched, rating));
                } else {
                    throw std::runtime_error("Media with title '" + serialTitle + "' is not a Serial.");
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 5) {
            std::string serialTitle;
            int seasonNumber;

            std::cout << "Enter serial title to remove a season: ";
            std::cin.ignore();
            std::getline(std::cin, serialTitle);
            std::cout << "Enter season number to remove: ";
            if (!readInt(seasonNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }

            try {
                Media* mediaItem = mediaList.findMediaByTitle(serialTitle);
                Serial* serial = dynamic_cast<Serial*>(mediaItem);
                if (serial) {
                    serial->removeSeason(seasonNumber);
                } else {
                    throw std::runtime_error("Media with title '" + serialTitle + "' is not a Serial.");
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 6) {
            std::string serialTitle;
            int episodeNumber;

            std::cout << "Enter serial title to remove an episode: ";
            std::cin.ignore();
            std::getline(std::cin, serialTitle);
            std::cout << "Enter episode number to remove: ";
            if (!readInt(episodeNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }

            try {
                Media* mediaItem = mediaList.findMediaByTitle(serialTitle);
                Serial* serial = dynamic_cast<Serial*>(mediaItem);
                if (serial) {
                    serial->removeEpisode(episodeNumber);
                } else {
                    throw std::runtime_error("Media with title '" + serialTitle + "' is not a Serial.");
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 7) {
            std::string serialTitle;
            int seasonNumber;
            int episodeNumber;
            std::string episodeTitle;
            bool watched;
            int rating;

            std::cout << "Enter serial title to add an episode to a season: ";
            std::cin.ignore();
            std::getline(std::cin, serialTitle);
            std::cout << "Enter season number: ";
            if (!readInt(seasonNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            std::cout << "Enter episode number: ";
            if (!readInt(episodeNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            std::cin.ignore();
            std::cout << "Enter episode title: ";
            std::getline(std::cin, episodeTitle);
            std::cout << "Have you watched the episode? (1-yes, 0-no): ";
            int watchedVal7;
            if (!readInt(watchedVal7)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            watched = watchedVal7 != 0;
            if (watched) {
                std::cout << "Enter your personal rating (1-10): ";
                if (!readInt(rating)) {
                    std::cerr << "Expected a number.\n";
                    continue;
                }
            } else {
                rating = 0;
            }

            try {
                Media* mediaItem = mediaList.findMediaByTitle(serialTitle);
                Serial* serial = dynamic_cast<Serial*>(mediaItem);
                if (serial) {
                    bool seasonFound = false;
                    for (auto& season : serial->getSeasons()) {
                        if (season.getNumber() == seasonNumber) {
                            season.addEpisode(Episode(episodeNumber, episodeTitle, watched, rating));
                            seasonFound = true;
                            break;
                        }
                    }
                    if (!seasonFound) {
                        throw std::runtime_error("Season number '" + std::to_string(seasonNumber) + "' not found in serial '" + serialTitle + "'.");
                    }
                } else {
                    throw std::runtime_error("Media with title '" + serialTitle + "' is not a Serial.");
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 8) {
            std::string serialTitle;
            int seasonNumber;
            int episodeNumber;

            std::cout << "Enter serial title to remove an episode from a season: ";
            std::cin.ignore();
            std::getline(std::cin, serialTitle);
            std::cout << "Enter season number: ";
            if (!readInt(seasonNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            std::cout << "Enter episode number to remove: ";
            if (!readInt(episodeNumber)) {
                std::cerr << "Expected a number.\n";
                continue;
            }

            try {
                Media* mediaItem = mediaList.findMediaByTitle(serialTitle);
                Serial* serial = dynamic_cast<Serial*>(mediaItem);
                if (serial) {
                    bool seasonFound = false;
                    for (auto& season : serial->getSeasons()) {
                        if (season.getNumber() == seasonNumber) {
                            season.removeEpisode(episodeNumber);
                            seasonFound = true;
                            break;
                        }
                    }
                    if (!seasonFound) {
                        throw std::runtime_error("Season number '" + std::to_string(seasonNumber) + "' not found in serial '" + serialTitle + "'.");
                    }
                } else {
                    throw std::runtime_error("Media with title '" + serialTitle + "' is not a Serial.");
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 9) {
            std::string title;
            std::cout << "Enter the title of the media to remove: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            try {
                mediaList.removeMedia(title);
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }

        if (choice == 10) {
            std::string title;
            std::cout << "Enter the title of the media to edit: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "0 - Personal rating / 1 - Watched status\n";
            int editChoice;
            std::cout << "Choose an option to edit: ";
            if (!readInt(editChoice)) {
                std::cerr << "Expected a number.\n";
                continue;
            }
            try {
                Media* mediaItem = mediaList.findMediaByTitle(title);
                if (editChoice == 0) {
                    int newRating;
                    std::cout << "Enter new personal rating (1-10): ";
                    if (!readInt(newRating)) {
                        std::cerr << "Expected a number.\n";
                        continue;
                    }
                    mediaItem->setPersonalRating(newRating);
                } else if (editChoice == 1) {
                    int newWatchedVal;
                    std::cout << "Have you watched the media? (1-yes, 0-no): ";
                    if (!readInt(newWatchedVal)) {
                        std::cerr << "Expected a number.\n";
                        continue;
                    }
                    bool newWatchedStatus = newWatchedVal != 0;
                    if (newWatchedStatus) {
                        mediaItem->markAsWatched();
                    } else {
                        mediaItem->markAsUnwatched();
                    }
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }
        }
        
        if (choice == 11) {
            mediaList.printMediaList();
        }

        if (choice == 12) {
            break;
        }
    }

}