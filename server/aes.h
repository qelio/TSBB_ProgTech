#ifndef AES_H
#define AES_H

#include <QString>
#include <QByteArray>

class AES
{
public:
    AES(unsigned char* key);
    ~AES();

    QByteArray encrypt(const QString& plainText);
    QString decrypt(const QByteArray& cipherText);

private:
    void SubBytes(unsigned char state[][4]);
    void ShiftRows(unsigned char state[][4]);
    void MixColumns(unsigned char state[][4]);
    void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);
    void InvSubBytes(unsigned char state[][4]);
    void InvShiftRows(unsigned char state[][4]);
    void InvMixColumns(unsigned char state[][4]);
    unsigned char FFmul(unsigned char a, unsigned char b);
    void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
    unsigned char* CipherBlock(unsigned char* input);
    unsigned char* InvCipherBlock(unsigned char* input);
    void* Cipher(void* input, int length);
    void* InvCipher(void* input, int length);

    unsigned char Sbox[256];
    unsigned char InvSbox[256];
    unsigned char w[11][4][4];
};

#endif // AES_H
