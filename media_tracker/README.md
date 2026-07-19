# Media Tracker
### Autor: Kacper Pisarek 
### 19.07.2026

## Opis
Konsolowy program do śledzenia obejrzanych filmów i seriali. Pozwala dodawać filmy i seriale, epizody i sezony do seriali i epizody do sezonów.

## Zawartość
main.cpp | Główny plik programu — interfejs konsolowy (menu)
Media.h | Abstrakcyjna klasa bazowa dla wszystkich mediów
Movie.h | Klasa reprezentująca film
Serial.h | Klasa reprezentująca serial z sezonami i epizodami
Season.h | Klasa reprezentująca sezon serialu
Episode.h | Klasa reprezentująca pojedynczy epizod
MediaList.h | Klasa zarządzająca listą mediów
Makefile | Skrypt kompilacji

### Komendy z Makefile
make - kompiluje program do pliku media_tracker
make clean - usuwa pliki wykonywalne
make tar - tworzy archiwum .tar.gz z całego katalogu

### Uruchomienie
./media_tracker - uruchamia program