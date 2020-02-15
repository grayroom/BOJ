#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class House {
    public:
    int posX{};
    int posY{};
    vector<House*> childHosue{};

    House(int posX, int posY) {this->posX = posX; this->posY = posY;}
};

int main() {
    int N{};
    scanf("%d", &N);

    vector<House> houseList{};
    int posX{}, posY{};
    for(int i = 0; i < N; ++i) {
        scanf("%d, %d", &posX, &posY);
        houseList.emplace_back(House(posX, posY));
    }

    return 0;
}

void init(vector<House>& houseList) {
    for(House houseMain : houseList) {
        for(House houseSub : houseList) {
            if(sqrt(3) * (houseMain.posY - houseSub.posY) <= abs(houseMain.posX - houseSub.posX))
        }
    }
}