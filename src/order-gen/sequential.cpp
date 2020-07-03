#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <order-gen/gene.hpp>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage:" << std::endl;
        std::cout << argv[0] << " <input-file>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream input_file(argv[1]);

    if (!input_file.is_open())
    {
        std::cout << "Could not open file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Gene> genes;

    std::string line;
    while (std::getline(input_file, line))
    {
        auto gene = parse_gene(line);
        genes.push_back(std::move(gene));
    }

    std::sort(genes.begin(), genes.end());

    std::ofstream output_file("output.csv");

    for (const auto& gene: genes)
    {
        output_file << serialize_gene(gene);
    }

    return EXIT_SUCCESS;
}