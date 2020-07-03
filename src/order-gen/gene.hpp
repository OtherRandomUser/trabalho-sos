#pragma once

#include <string>

struct Gene
{
    std::string organism;
    std::string gene;
    std::string type;
    std::string family;
    std::string role;
    std::string pos_ini;
    std::string pos_fin;
    std::string genome;

    bool operator < (const Gene& other) const;
    bool operator > (const Gene& other) const;
};

Gene parse_gene(const std::string& str);
std::string serialize_gene(const Gene& gene);
