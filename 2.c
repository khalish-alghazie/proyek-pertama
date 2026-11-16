#include <stdio.h>
#include <string.h>

// Prototipe fungsi sesuai soal
void enkripsi_baru(char* data, char arah, int pergeseran);

int main(void) {
    char string_input[100];
    char string_arah[10];
    int geser;
    char kode_arah;

    // Ambil input string
    printf("Masukkan sebuah string: ");
    fgets(string_input, sizeof(string_input), stdin);
    string_input[strcspn(string_input, "\n")] = 0; // Hapus enter

    // Ambil nilai pergeseran
    printf("Besar pergeseran karakter: ");
    scanf("%d", &geser);

    // Ambil input string untuk arah (kanan/kiri)
    printf("Arah pergeseran: ");
    scanf("%s", string_arah);

    // Cek input arah untuk diubah jadi 1 karakter agar cocok dengan prototipe fungsi
    if (strcmp(string_arah, "kiri") == 0) {
        kode_arah = 'l'; // left
    } else {
        kode_arah = 'r'; // right
    }

    // Panggil fungsi enkripsi
    enkripsi_baru(string_input, kode_arah, geser);

    printf("Hasil enkripsi: %s\n", string_input);

    return 0;
}

void enkripsi_baru(char* data, char arah, int pergeseran) {
    int i = 0;
    
    // Biar kalau input pergeseran > 26 tetap aman perputarannya
    pergeseran = pergeseran % 26;
    
    while (data[i] != '\0') {
        // Skip kalau karakter spasi
        if (data[i] == ' ') {
            i++;
            continue;
        }
        
        // Ubah huruf besar ke huruf kecil (ASCII 'A' ditambah 32 jadi 'a')
        if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = data[i] + 32;
        }
        
        // Proses enkripsi pergeseran huruf
        if (data[i] >= 'a' && data[i] <= 'z') {
            if (arah == 'r') { // Geser ke kanan
                data[i] = data[i] + pergeseran;
                // Balik ke 'a' kalau ngelewatin 'z'
                if (data[i] > 'z') {
                    data[i] = data[i] - 26;
                }
            } else if (arah == 'l') { // Geser ke kiri
                data[i] = data[i] - pergeseran;
                // Balik ke 'z' kalau ngelewatin 'a'
                if (data[i] < 'a') {
                    data[i] = data[i] + 26;
                }
            }
        }
        i++;
    }
}