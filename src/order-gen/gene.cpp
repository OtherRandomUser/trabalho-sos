#include <order-gen/gene.hpp>

bool Gene::operator < (const Gene& other) const
{
    if (gene < other.gene)
        return true;

    if (gene > other.gene)
        return false;

    return organism < other.organism;
}

bool Gene::operator > (const Gene& other) const
{
    if (gene > other.gene)
        return true;

    if (gene < other.gene)
        return false;

    return organism > other.organism;
}

Gene parse_gene(const std::string& str)
{
    std::string delimiter = ";";
    Gene res;

    int ini = 0;
    int fin = str.find(delimiter);
    res.organism = str.substr(ini, fin);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.gene = str.substr(ini, fin - ini);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.type = str.substr(ini, fin - ini);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.family = str.substr(ini, fin - ini);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.role = str.substr(ini, fin - ini);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.pos_ini = str.substr(ini, fin - ini);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.pos_fin = str.substr(ini, fin - ini);

    ini = fin + 1;
    fin = str.find(delimiter, ini);
    res.genome = str.substr(ini, fin - ini);

    return res;
}

std::string serialize_gene(const Gene& gene)
{
    std::string res;

    int size = gene.organism.size()
        + gene.gene.size()
        + gene.type.size()
        + gene.family.size()
        + gene.role.size()
        + gene.pos_ini.size()
        + gene.pos_fin.size()
        + gene.genome.size()
        + 10; // delimiters

    res.reserve(size);
    res.append(gene.organism);
    res.append(";");
    res.append(gene.gene);
    res.append(";");
    res.append(gene.type);
    res.append(";");
    res.append(gene.family);
    res.append(";");
    res.append(gene.role);
    res.append(";");
    res.append(gene.pos_ini);
    res.append(";");
    res.append(gene.pos_fin);
    res.append(";");
    res.append(gene.genome);
    res.append("\n");

    return res;
}
