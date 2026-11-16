#include <stdio.h>
#include <string.h>

// Prototipe fungsi sesuai soal
char ganti_karakter(char* data, char find, char replace);

int main() {
    char string_input[100];
    char cari, ganti;

    // Ambil input dari user
    printf("Masukkan sebuah string: ");
    fgets(string_input, sizeof(string_input), stdin);
    // Hapus karakter enter/newline bawaan dari fgets
    string_input[strcspn(string_input, "\n")] = 0;

    printf("Karakter yang dicari: ");
    scanf(" %c", &cari);

    printf("Karakter pengganti: ");
    scanf(" %c", &ganti);

    // Panggil fungsi dengan pass by reference untuk array string
    ganti_karakter(string_input, cari, ganti);

    printf("String hasil subsitutisi: %s\n", string_input);

    return 0;
}

char ganti_karakter(char* data, char find, char replace) {
    int i = 0;
    char found = 0;
    
    // Looping tiap karakter dalam string sampai ketemu Null terminator
    while (data[i] != '\0') {
        if (data[i] == find) {
            data[i] = replace;
            found = 1; 
        }
        i++;
    }
    return found; 
}