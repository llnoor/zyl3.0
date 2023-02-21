// Полное решение
#include <iostream>
#include <fstream>
#include <map>

void fun() {
    std::map <char, int> mp;
    int max_count=0;
    char char_temp;
    std::ifstream fin("input.txt");
    while (fin.get(char_temp)){
        if (char_temp != ' ' && char_temp != '\n') {
            if (mp.find(char_temp) != mp.end()) {
                mp[char_temp] = mp[char_temp] + 1;
                if (mp[char_temp] > max_count) max_count = mp[char_temp];
            } else {
                mp[char_temp] = 1;
                if (mp[char_temp] > max_count) max_count = mp[char_temp];
            }
        }
    }
    fin.close();
    std::map <char, int> :: iterator it = mp.begin();
    for (int k=max_count; k>0; k--) {
        it = mp.begin();
        for (int i = 0; it != mp.end(); it++, i++) {
            if (it->second >=k) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    it = mp.begin();
    for (int i = 0; it != mp.end(); it++, i++) {
        std::cout << it->first;
    }
    std::cout << std::endl;
}

int main() {
    fun();
    return 0;
}