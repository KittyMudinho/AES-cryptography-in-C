#include <stdio.h>
unsigned char mix[9] = {
    2,3,1,
    1,2,3,
    1,1,2
};
unsigned char sbox[256] = {
    // 0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,  // 0
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,  // 1
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,  // 2
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,  // 3
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,  // 4
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,  // 5
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,  // 6
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,  // 7
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,  // 8
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,  // 9
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,  // A
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,  // B
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,  // C
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,  // D
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,  // E
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }; // F
unsigned char rsbox[256] =
{
    // 0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,//0
    0x7c, 0xe3, 0x21, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,//1
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,//2
    0x08, 0x2e, 0xa1, 0x66, 0x64, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,//3
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,//4
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,//5
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,//6
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,//7
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0x6f, 0xce, 0xf0, 0xb4, 0xe6, 0x73,//8
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x69,//9
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,//A
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,//B
    0x1f, 0xdd, 0x42, 0xb7, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,//C
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,//D
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,//E
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d//F
};
    unsigned char mensagemEmHexa[9] = { 0x42,0x6f,0x6d,0x20,0x64,0x69,0x61,0x21,0x21 };
    unsigned char valorDoSub[9];
    unsigned char valorDoShift[9];
    unsigned char valorDoMix[9];
    unsigned char invValorDoSub[9];
    unsigned char invValorDoShift[9];
    unsigned char invValorDoMix[9];
    unsigned char valorDoRound[9];
    unsigned char chave[9];
    unsigned char roundKey[9] = { 0x45, 0xf3, 0x9f, 0xde ,0x6c, 0x33, 0x22, 0x17, 0x26 };
void SubBytes() {
    for (int i = 0; i < 9; i++) {
        valorDoSub[i] = sbox[mensagemEmHexa[i]];
    }
}
void ShiftRows() {
    for (int i = 0; i < 3; i++) {
        switch (i)
        {
        case 0:
            valorDoShift[0] = valorDoSub[0];
            valorDoShift[1] = valorDoSub[1];
            valorDoShift[2] = valorDoSub[2];
        case 1:
            valorDoShift[3] = valorDoSub[4];
            valorDoShift[4] = valorDoSub[5];
            valorDoShift[5] = valorDoSub[3];
        case 2:
            valorDoShift[6] = valorDoSub[7];
            valorDoShift[7] = valorDoSub[6];
            valorDoShift[8] = valorDoSub[8];
        }
    }
}
unsigned char galois_multiplication(unsigned char a, unsigned char b)
{
    unsigned char p = 0;
    unsigned char counter;
    unsigned char hi_bit_set;
    for (counter = 0; counter < 8; counter++)
    {
        if ((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}
void mixColumn(unsigned char* column)
{
    unsigned char cpy[4];
    int i;
    for (i = 0; i < 3; i++)
    {
        cpy[i] = column[i];
    }
    column[0] = galois_multiplication(cpy[0], 2) ^
        galois_multiplication(cpy[3], 1) ^
        galois_multiplication(cpy[2], 1) ^
        galois_multiplication(cpy[1], 3);

    column[1] = galois_multiplication(cpy[1], 2) ^
        galois_multiplication(cpy[0], 1) ^
        galois_multiplication(cpy[3], 1) ^
        galois_multiplication(cpy[2], 3);

    column[2] = galois_multiplication(cpy[2], 2) ^
        galois_multiplication(cpy[1], 1) ^
        galois_multiplication(cpy[0], 1) ^
        galois_multiplication(cpy[3], 3);

    column[3] = galois_multiplication(cpy[3], 2) ^
        galois_multiplication(cpy[2], 1) ^
        galois_multiplication(cpy[1], 1) ^
        galois_multiplication(cpy[0], 3);
}
void mixColumns(unsigned char* state)
{
    int i, j;
    unsigned char column[4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            column[j] = valorDoMix[(j * 4) + i];
        }
        mixColumn(column);
        for (j = 0; j < 3; j++)
        {
            valorDoMix[(j * 4) + i] = column[j];
        }
    }
}

void addRoundKey() {
    for (int i = 0; i < 9; i++) {
        valorDoRound[i] = valorDoMix[i] ^ roundKey[i];
    }
}
void encriptacao() {
    SubBytes();
    ShiftRows();
    mixColumns(valorDoShift);
    addRoundKey();
}
void invAddRoundKey() {
    for (int i = 0; i < 9; i++) {
        valorDoMix[i] = valorDoRound[i] ^ roundKey[i];
    }
}
void descobrirChave() {
    for (int i = 0; i < 9; i++) {
        chave[i] = valorDoMix[i] ^ valorDoShift[i];
    }
}
void InvMixColumns() {
    for (int i = 0; i < 9; i++) {
        invValorDoMix[i] = valorDoMix[i] ^ chave[i];
    }
}
void invShiftRows() {
    for (int i = 0; i < 3; i++) {
        switch (i)
        {
        case 0:
            invValorDoShift[0] = invValorDoMix[0];
            invValorDoShift[1] = invValorDoMix[1];
            invValorDoShift[2] = invValorDoMix[2];
        case 1:
            invValorDoShift[3] = invValorDoMix[5];
            invValorDoShift[4] = invValorDoMix[3];
            invValorDoShift[5] = invValorDoMix[4];
        case 2:
            invValorDoShift[6] = invValorDoMix[7];
            invValorDoShift[7] = invValorDoMix[6];
            invValorDoShift[8] = invValorDoMix[8];
        }
    }
}
void invSubBytes() {
    for (int i = 0; i < 9; i++) {
        invValorDoSub[i] = rsbox[invValorDoShift[i]];
    }
}
void desencriptar() {
    descobrirChave();
    invAddRoundKey();
    InvMixColumns();
    invShiftRows();
    invSubBytes();
}
void printarTexto(unsigned char variavel[]) {
    for (int i = 0; i < 9; i++) {
        printf("%c", variavel[i]);
    }
}
void printarHexa(unsigned char variavel[]) {
    for (int i = 0; i < 9; i++) {
        printf("%x ", variavel[i]);
    }
}
void criarArquivo() {
    FILE* file = fopen("bomdia.txt", "wb");
    if (!file) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "Bom dia!!");
    char arr[] = "Bom dia!!";
    char temp[3];
    for (int i = 0; arr[i] != '\0'; i++) {
        sprintf(temp, "%02x", arr[i]);
    }
}
void criarArquivoCriptografado() {
    FILE* file1 = fopen("bomdiaCriptografado.txt", "wb");
    if (!file1) {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < 9; i++) {
        fprintf(file1, "%c", valorDoMix[i]);
    }
}
void criarArquivoDescriptografado() {
    FILE* file2 = fopen("bomdiaDescriptografado.txt", "wb");
    if (!file2) {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < 9; i++) {
        fprintf(file2, "%c", invValorDoSub[i]);
    }
}
int main() {
    encriptacao();
    criarArquivo();
    printf("Criptografia AES.\n");
    printf("Texto original:\n");
    printarTexto(mensagemEmHexa);
    printf("\nTexto original(hexa):\n");
    printarHexa(mensagemEmHexa);
    printf("\nTexto criptografado:\n");
    printarTexto(valorDoRound);
    printf("\nTexto criptografado(hexa):\n");
    printarHexa(valorDoRound);
    criarArquivoCriptografado();
    desencriptar();
    criarArquivoDescriptografado();
    printf("\nTexto descriptografado:\n");
    printarTexto(invValorDoSub);
    printf("\nTexto descriptografado(hexa):\n");
    printarHexa(chave);
	return 0;
}