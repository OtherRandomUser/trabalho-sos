#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <algorithm>

#include <order-gen/gene.hpp>

void thread_function(std::string filename, std::streampos start, int total_records, std::vector<Gene> *out_array)
{
    std::ifstream input_file(filename);
    out_array->reserve(total_records);

    if (!input_file.is_open())
    {
        std::cout << "Could not open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    int records_read = 0;

    while (std::getline(input_file, line))
    {
        if (records_read == total_records)
            break;

        auto gene = parse_gene(line);
        out_array->push_back(std::move(gene));
        records_read++;
    }

    std::sort(out_array->begin(), out_array->end());
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Usage:" << std::endl;
        std::cout << argv[0] << " <input-file> <worker-threads>" << std::endl;
        return EXIT_FAILURE;
    }

    int number_of_threads = std::stoi(argv[2]);
    std::string input_filename = argv[1];

    // passe para calcular os offsets
    std::ifstream input_file(input_filename);

    if (!input_file.is_open())
    {
        std::cout << "Could not open file " << input_filename << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::streampos> offsets;
    offsets.reserve(90000);

    std::string line;
    while (std::getline(input_file, line))
    {
        offsets.push_back(input_file.tellg());
    }

    int records_per_thread = offsets.size() / number_of_threads;

    // inicialização das threads
    std::vector<std::thread> threads;
    threads.reserve(number_of_threads);

    std::vector<std::vector<Gene>> thread_genes(number_of_threads);

    for (int i = 0; i < number_of_threads; i++)
    {
        auto record_offset = offsets[i * records_per_thread];
        threads.emplace_back(&thread_function, input_filename, record_offset, records_per_thread, &thread_genes[i]);
    }

    std::vector<std::vector<Gene>::iterator> begins;
    std::vector<std::vector<Gene>::iterator> ends;

    // wait
    for (int i = 0; i < number_of_threads; i++)
    {
        threads[i].join();
        begins.push_back(thread_genes[i].begin());
        ends.push_back(thread_genes[i].end());
    }

    // merge
    int total_records = offsets.size();
    std::ofstream output_file("output.csv");

    for (int i = 0; i < total_records; i++)
    {
        int k = -1;

        for (int j = 0; j < number_of_threads; j++)
        {
            if (begins[j] == ends[j])
                continue;

            if (k == -1 || *begins[j] < *begins[k])
                k = j;
        }

        output_file << serialize_gene(*begins[k]);
        begins[k]++;
    }


    return EXIT_SUCCESS;
}