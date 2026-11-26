#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/md5.h>
#include <openssl/des.h>

void test_weak_hash(const unsigned char *data, size_t len) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(data, len, digest);
}

void test_weak_cipher() {
    DES_cblock key;
    DES_key_schedule schedule;
    DES_random_key(&key);
    DES_set_key_checked(&key, &schedule);
}

void test_short_rsa() {
    RSA *rsa = RSA_new();
    BIGNUM *bne = BN_new();
    BN_set_word(bne, RSA_F4);
    RSA_generate_key_ex(rsa, 1024, bne, NULL);
    RSA_free(rsa);
    BN_free(bne);
}

void test_strong_aes() {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    unsigned char key[32] = {0};
    unsigned char iv[12] = {0};
    EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, key, iv);
    EVP_CIPHER_CTX_free(ctx);
}
