#include <string>
#include <vector>

using namespace std;

void phaseOne(string& id) {
    for (char& ch : id) {
        if ('A' <= ch && ch <= 'Z') {
            ch = tolower(ch);
        }
    }
}

void phaseTwo(string& id) {
    auto it = id.begin();
    for (; it != id.end(); ) {
        char ch = *it;
        if (!(('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') || ch == '-' || ch == '_' || ch == '.')) {
            id.erase(it);
        } else {
            it++;
        }
    }
}

void phaseThree(string& id) {
    auto index = id.find("..");
    while (index != string::npos) {
        id.replace(index, 2, ".");
        index = id.find("..");
    }
}

void phaseFour(string& id) {
    if (id[0] == '.') {
        id.erase(0, 1);
    }
    if (id.back() == '.') {
        id.pop_back();
    }
}

void phaseFive(string& id) {
    if (id.empty()) {
        id = "a";
    }
}

void phaseSix(string& id) {
    if (id.size() >= 16) {
        id.erase(15);
        if (id.back() == '.') {
            id.pop_back();
        }
    }
}

void phaseSeven(string& id) {
    if (id.size() <= 2) {
        while (id.size() != 3) {
            id.push_back(id.back());
        }
    }
}

void checkAndRecommendNewId(string& id) {
    phaseOne(id);
    phaseTwo(id);
    phaseThree(id);
    phaseFour(id);
    phaseFive(id);
    phaseSix(id);
    phaseSeven(id);
}

string solution(string new_id) {
    checkAndRecommendNewId(new_id);
    return new_id;
}