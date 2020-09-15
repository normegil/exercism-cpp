#include "protein_translation.h"

#include <map>

namespace protein_translation
{
    const std::map<std::string, std::string> TRANSCRIPTIONS{
        {"AUG", "Methionine"},
        {"UUC", "Phenylalanine"},
        {"UUU", "Phenylalanine"},
        {"UUG", "Leucine"},
        {"UUA", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"}};

    std::vector<std::string> proteins(std::string adn)
    {
        std::vector<std::string> splittedADN{};
        std::string tmp{};
        for (size_t i = 0; i < adn.length(); i++)
        {
            if (i != 0 && i % 3 == 0)
            {
                splittedADN.push_back(tmp);
                tmp = adn[i];
            }
            else
            {
                tmp += adn[i];
            }
        }
        splittedADN.push_back(tmp);

        std::vector<std::string> proteins{};
        for (auto &&section : splittedADN)
        {
            auto entry = TRANSCRIPTIONS.find(section);
            if ("STOP" == entry->second)
            {
                return proteins;
            }

            proteins.push_back(entry->second);
        }

        return proteins;
    }
} // namespace protein_translation
