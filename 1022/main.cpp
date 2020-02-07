#include <iostream>

int getLayer(int num);

int main() {
    int r1{},
        c1{},
        r2{},
        c2{};


}

int getLayer(int num) {
    for(int i = 0; num <= (2*i + 1) * (2*i + 1); i++) {
        return i;
    }
}