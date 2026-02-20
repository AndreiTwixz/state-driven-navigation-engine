#include <iostream>
#include <string>
#include <vector>
#include <map>

class Pagina {
public:
    std::string url;
    std::string titlu;
    std::string continut;

    Pagina() {
    }

    Pagina(std::string u, std::string t, std::string c) : url(u), titlu(t), continut(c) {
    }
};

class Browser {
private:
    std::map<std::string, Pagina> baza_date;
    std::vector<std::string> istoric;
    int index_curent;

public:
    Browser() {
        index_curent = -1;
    }

    void adauga_pagina(std::string u, std::string t, std::string c) {
        Pagina p(u, t, c);
        
        baza_date[u] = p;
    }

    void link(std::string u) {
        if (index_curent >= 0) {
            istoric.resize(index_curent + 1);
        }
        
        istoric.push_back(u);
        
        index_curent = istoric.size() - 1;
    }

    void back() {
        if (index_curent > 0) {
            index_curent--;
        }
    }

    void forward() {
        if (index_curent >= 0) {
            if (index_curent < istoric.size() - 1) {
                index_curent++;
            }
        }
    }

    void afisare() {
        if (index_curent >= 0) {
            std::string url_curent;
            
            url_curent = istoric[index_curent];
            
            Pagina p;
            
            p = baza_date[url_curent];
            
            std::cout << p.url << std::endl;
            
            std::cout << p.titlu << std::endl;
            
            std::cout << p.continut << std::endl;
        }
    }
};

int main() {
    Browser browser;
    
    int comanda;
    
    while (std::cin >> comanda) {
        if (comanda == 6) {
            break;
        }
        
        if (comanda == 1) {
            std::string u;
            std::string t;
            std::string c;
            
            std::cin >> u >> t >> c;
            
            browser.adauga_pagina(u, t, c);
        } else if (comanda == 2) {
            std::string u;
            
            std::cin >> u;
            
            browser.link(u);
        } else if (comanda == 3) {
            browser.afisare();
        } else if (comanda == 4) {
            browser.back();
        } else if (comanda == 5) {
            browser.forward();
        }
    }
    
    return 0;
}