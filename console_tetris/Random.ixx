module;

#include "pch.h"

export module Random;

//random number generation option #1
//std::random_device seeder; // True random number generator to obtain a seed (slow)
//std::default_random_engine generator{ seeder() }; // Efficient pseudo-random generator
//std::uniform_int_distribution distribution{ 1, 2 }; // Generate in [1, 2] interval
//return std::bind(distribution, generator);

//random number generation option #2
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen{ rd() }; //Standard mersenne_twister_engine seeded with rd()

export int getRandomNumT()
{
    static std::uniform_int_distribution<> distrib{ 1, 7 };
    return distrib(gen);
}

export int getRandomNumE()
{
    static std::uniform_int_distribution<> distrib{ 0x1F354, 0x1F37A };
    return distrib(gen);
}