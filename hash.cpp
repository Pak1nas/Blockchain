#include "hash.h"
#include <cstdint>
#include <bits/stdc++.h>

using namespace std;

string ihex(uint64_t n){

    char hexnum[100];
    int i = 0;

    while(n != 0){

        int likutis = n % 16;

        if(likutis < 10)
            hexnum[i] = '0' + likutis;
        else
            hexnum[i] = 'A' + (likutis - 10);

        i++;
        n /= 16;
    }

    while(i < 16){
        hexnum[i] = '0';
        i++;
    }

    string rezultatas = "";

    for(int j = i - 1; j >= 0; j--){
        rezultatas += hexnum[j];
    }

    return rezultatas;
}

uint64_t rotl(uint64_t n, unsigned int kiek){

    kiek %= 64;

    if(kiek == 0)
        return n;

    return (n << kiek) | (n >> (64 - kiek));
}

string generateHash(const string& ivedimas){

    uint64_t rez1 = 10;
    uint64_t rez2 = 21;
    uint64_t rez3 = 15;
    uint64_t rez4 = 145;

    uint64_t pozicija = 0;

    // Ivesties simboliu apdorojimas

    for(unsigned char c : ivedimas){

        pozicija++;

        rez1 = rez1 + c;
        rez1 = rez1 * 3;
        rez1 = ~rez1;
        rez1 = rez1 - c;
        rez1 = rez1 ^ rez4;
        rez1 = rotl(rez1, 13);

        rez2 = rez2 - c;
        rez2 = rez2 ^ 2;
        rez2 = rez2 - rez1;
        rez2 = rotl(rez2, 29);

        rez3 = rez3 ^ c;
        rez3 = rez3 - c;
        rez3 = rez3 + rez1;
        rez3 = rotl(rez3, 41);

        rez4 = rez4 ^ rez2;
        rez4 = rez4 - c;
        rez4 = rez4 * 19;
        rez4 = rotl(rez4, 53);

        rez1 ^= pozicija;
        rez3 ^= rez4;
    }

    // Ivesties ilgio itraukimas

    uint64_t ilgis = ivedimas.size();

    rez1 ^= ilgis;
    rez2 += rotl(ilgis, 17);
    rez3 ^= rotl(ilgis, 31);
    rez4 += rotl(ilgis, 47);

    for(uint64_t i = 0; i < 12; i++){

        rez1 += rez2;
        rez1 = rotl(rez1, 17);
        rez1 ^= rez4;

        rez2 += rez3;
        rez2 = rotl(rez2, 31);
        rez2 ^= rez1;

        rez3 += rez4;
        rez3 = rotl(rez3, 43);
        rez3 ^= rez2;

        rez4 += rez1;
        rez4 = rotl(rez4, 11);
        rez4 ^= rez3;

        rez1 *= 31;
        rez2 *= 47;
        rez3 *= 61;
        rez4 *= 73;

        rez1 ^= i + 1;
        rez4 += i + 1;
    }

    return ihex(rez1) +
           ihex(rez2) +
           ihex(rez3) +
           ihex(rez4);
}
