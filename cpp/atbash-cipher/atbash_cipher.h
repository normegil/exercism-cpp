#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>

namespace atbash_cipher {
    std::string encode(std::string to_encode);
    std::string decode(std::string to_decode);
}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H