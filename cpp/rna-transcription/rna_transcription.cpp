#include "rna_transcription.h"

#include <map>

namespace rna_transcription
{
    std::map<char, char> TRANSCRIPTION_MATRIX = {
        {'G', 'C'},
        {'C', 'G'},
        {'T', 'A'},
        {'A', 'U'},
    };

    char to_rna(char dna)
    {
        return TRANSCRIPTION_MATRIX.at(dna);
    }

    std::string to_rna(std::string dna)
    {
        std::string rna{""};
        for (auto &&c : dna)
        {
            rna.push_back(to_rna(c));
        }
        return rna;
    }
} // namespace rna_transcription
