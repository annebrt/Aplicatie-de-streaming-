#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>

// ================= STORAGE =================
template <typename T>
class Storage {
private:
    std::vector<T> data;

public:
    void add(const T& x) {
        data.push_back(x);
    }

    std::vector<T>& getAll() {
        return data;
    }

    const std::vector<T>& getAll() const {
        return data;
    }
};
// ===========================================

#include "Film.h"
#include "Serial.h"
#include "Episod.h"
#include "Client.h"

class App {
private:
    Storage<BaseVideo*> videos;
    Storage<Client*> utilizatori;

    // ---------- VIDEO ----------
    BaseVideo* findVideo(const std::string& denumire) {
        for (auto v : videos.getAll())
            if (v->getDenumire() == denumire)
                return v;
        return nullptr;
    }

    void introduFilm() {
        BaseVideo* f = new Film();
        std::cin >> *f;
        videos.add(f);
    }

    void introduSerial() {
        BaseVideo* s = new Serial();
        std::cin >> *s;
        videos.add(s);
    }

    // ---------- UTILIZATOR ----------
    void introduUtilizator() {
        std::cin.ignore(); // dummy cin (fix pentr new line)

        char nume[100];
        char prenume[100];
        char email[100];
        char telefon[50];

        int zi, luna, an;
        int tipCont;
        int nrPref;

        std::cout << "Nume: ";
        std::cin.getline(nume, 100);

        std::cout << "Prenume: ";
        std::cin.getline(prenume, 100);

        std::cout << "Email: ";
        std::cin.getline(email, 100);

        std::cout << "Telefon: ";
        std::cin.getline(telefon, 50);

        std::cout << "Data nasterii (zi luna an): ";
        std::cin >> zi >> luna >> an;
        std::cin.ignore();

        Data* dataNastere = new Data(zi, luna, an);

        // -------- PREFERINTE --------
        std::cout << "Numar preferinte: ";
        std::cin >> nrPref;
        std::cin.ignore();

        std::list<char*> preferinte;
        for (int i = 0; i < nrPref; i++) {
            char buffer[100];
            std::cout << "Preferinta " << i + 1 << ": ";
            std::cin.getline(buffer, 100);

            char* pref = new char[strlen(buffer) + 1];
            std::strcpy(pref, buffer);
            preferinte.push_back(pref);
        }

        // -------- CONT --------
        std::cout << "Tip cont:\n";
        std::cout << "1. Standard\n";
        std::cout << "2. Premium\n";
        std::cout << "Alegere: ";
        std::cin >> tipCont;
        std::cin.ignore();

        BaseCont* cont = nullptr;
        if (tipCont == 1)
            cont = new ContStandard(preferinte);
        else if (tipCont == 2)
            cont = new ContPremium(preferinte);
        else {
            std::cout << "Optiune invalida\n";
            return;
        }

        Client* c = Client::builder()
                        .Nume(nume)
                        .Prenume(prenume)
                        .Email(email)
                        .Telefon(telefon)
                        .DataNastere(dataNastere)
                        .Cont(cont)
                        .build();

        utilizatori.add(c);
    }

    // ---------- EPISOADE ----------
    void adaugaEpisod() {
        std::string nume;
        std::cout << "Denumire serial: ";
        std::getline(std::cin >> std::ws, nume);

        BaseVideo* v = findVideo(nume);
        if (!v) {
            std::cout << "Serial inexistent\n";
            return;
        }

        Serial* s = dynamic_cast<Serial*>(v);
        if (!s) {
            std::cout << "Video-ul nu este serial\n";
            return;
        }

        Episod* e = new Episod();
        std::cin >> *e;
        s->adaugaEpisod(e);
    }

    // ---------- RATE ----------
    void daNota() {
        if (utilizatori.getAll().empty() || videos.getAll().empty()) {
            std::cout << "Nu exista utilizatori sau videoclipuri\n";
            return;
        }

        std::cout << "\nSelecteaza utilizator:\n";
        for (size_t i = 0; i < utilizatori.getAll().size(); i++)
            std::cout << i << ". "
                      << utilizatori.getAll()[i]->getNume() << " "
                      << utilizatori.getAll()[i]->getPrenume() << "\n";

        size_t idxUser;
        std::cin >> idxUser;

        if (idxUser >= utilizatori.getAll().size()) {
            std::cout << "Index invalid\n";
            return;
        }

        Client* user = utilizatori.getAll()[idxUser];

        std::cout << "\nSelecteaza video:\n";
        for (size_t i = 0; i < videos.getAll().size(); i++)
            std::cout << i << ". " << videos.getAll()[i]->getDenumire() << "\n";

        size_t idxVideo;
        std::cin >> idxVideo;

        if (idxVideo >= videos.getAll().size()) {
            std::cout << "Index invalid\n";
            return;
        }

        int nota;
        std::cout << "Nota (1-10): ";
        std::cin >> nota;

        if (nota < 1 || nota > 10) {
            std::cout << "Nota invalida\n";
            return;
        }

        user->rateVideo(videos.getAll()[idxVideo], nota);
        std::cout << "Nota adaugata\n";
    }

    // ---------- WATCH ----------
    void watchVideo() {
        if (utilizatori.getAll().empty() || videos.getAll().empty()) {
            std::cout << "Nu exista utilizatori sau videoclipuri\n";
            return;
        }

        std::cout << "\nSelecteaza utilizator:\n";
        for (size_t i = 0; i < utilizatori.getAll().size(); i++)
            std::cout << i << ". "
                      << utilizatori.getAll()[i]->getNume() << " "
                      << utilizatori.getAll()[i]->getPrenume() << "\n";

        size_t idxUser;
        std::cin >> idxUser;

        if (idxUser >= utilizatori.getAll().size()) {
            std::cout << "Index invalid\n";
            return;
        }

        Client* user = utilizatori.getAll()[idxUser];

        std::cout << "\nSelecteaza video:\n";
        for (size_t i = 0; i < videos.getAll().size(); i++)
            std::cout << i << ". " << videos.getAll()[i]->getDenumire() << "\n";

        size_t idxVideo;
        std::cin >> idxVideo;

        if (idxVideo >= videos.getAll().size()) {
            std::cout << "Index invalid\n";
            return;
        }

        user->watchVideo(videos.getAll()[idxVideo]);
        std::cout << "Video adaugat in istoric\n";
    }

    // ---------- ISTORIC ----------
    void afiseazaIstoric() const {
        if (utilizatori.getAll().empty()) {
            std::cout << "Nu exista utilizatori\n";
            return;
        }

        std::cout << "\nSelecteaza utilizator:\n";
        for (size_t i = 0; i < utilizatori.getAll().size(); i++)
            std::cout << i << ". "
                      << utilizatori.getAll()[i]->getNume() << " "
                      << utilizatori.getAll()[i]->getPrenume() << "\n";

        size_t idxUser;
        std::cin >> idxUser;

        if (idxUser >= utilizatori.getAll().size()) {
            std::cout << "Index invalid\n";
            return;
        }

        const Client* user = utilizatori.getAll()[idxUser];
        const BaseCont* cont = user->getCont();
        std::list<const BaseVideo*> istoric = cont->getIstoric();

        std::cout << "\n===== ISTORIC =====\n";
        if (istoric.empty()) {
            std::cout << "Istoric gol\n";
            return;
        }

        int i = 1;
        for (const auto& v : istoric)
            std::cout << i++ << ". " << v->getDenumire() << "\n";
    }

    // ---------- AFISARE ----------
    void afisare() const {
        std::cout << "\n===== FILME & SERIALE =====\n";
        for (auto v : videos.getAll()) {
            std::cout << *v;
            std::cout << "Nota medie: " << v->getNota()
                      << " (" << v->getReviewCount() << " review-uri)\n";
            std::cout << "-----------------\n";
        }

        std::cout << "\n===== UTILIZATORI =====\n";
        for (const auto u : utilizatori.getAll()) {
            std::cout << "Nume: " << u->getNume() << " " << u->getPrenume() << "\n";
            std::cout << "Telefon: " << u->getTelefon() << "\n";
            std::cout << "Tip cont: "
                      << (dynamic_cast<const ContPremium*>(u->getCont()) ? "Premium" : "Standard")
                      << "\n-----------------\n";
        }
    }

public:
    void run() {
        int opt;
        do {
            std::cout
                << "\n1. Introdu film"
                << "\n2. Introdu serial"
                << "\n3. Introdu utilizator"
                << "\n4. Adauga episod la serial"
                << "\n5. Da nota"
                << "\n6. Afiseaza"
                << "\n7. Watch video"
                << "\n8. Afiseaza istoric"
                << "\n0. Iesire\nOptiune: ";

            std::cin >> opt;

            switch (opt) {
                case 1: introduFilm(); break;
                case 2: introduSerial(); break;
                case 3: introduUtilizator(); break;
                case 4: adaugaEpisod(); break;
                case 5: daNota(); break;
                case 6: afisare(); break;
                case 7: watchVideo(); break;
                case 8: afiseazaIstoric(); break;
                case 0: break;
                default: std::cout << "Optiune invalida\n";
            }
        } while (opt != 0);
    }

    ~App() {
        for (auto v : videos.getAll())
            delete v;
        for (auto u : utilizatori.getAll())
            delete u;
    }
};

#endif
