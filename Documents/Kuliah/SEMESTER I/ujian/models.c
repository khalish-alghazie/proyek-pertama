#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"

Buku *dataBuku = NULL;
int jumlahBuku = 0;

User *dataUser = NULL;
int jumlahUser = 0;

Peminjaman *dataPinjam = NULL;
int jumlahPinjam = 0;

/*
Mengambil satu kata dari baris.
Jika menggunakan tanda petik, ambil seluruh teks di dalamnya.
Return 0 jika tidak ada kata.
*/
static int ambilKata(char *teks, int *pos, char *hasil, int maks)
{
    int i = 0;

    // Lewati spasi dan tab
    while (teks[*pos] == ' ' || teks[*pos] == '\t')
    {
        (*pos)++;
    }

    // Periksa apakah teks sudah habis
    if (teks[*pos] == '\0' || teks[*pos] == '\n' || teks[*pos] == '\r')
    {
        return 0;
    }

    // Periksa apakah kata menggunakan tanda petik
    if (teks[*pos] == '"')
    {
        (*pos)++;

        // Ambil teks sampai menemukan tanda petik penutup
        while (teks[*pos] != '"' && teks[*pos] != '\0' &&
               teks[*pos] != '\n' && teks[*pos] != '\r')
        {

            if (i < maks - 1)
            {
                hasil[i++] = teks[*pos];
            }

            (*pos)++;
        }

        // Lewati tanda petik penutup
        if (teks[*pos] == '"')
        {
            (*pos)++;
        }
    }
    else
    {

        // Ambil kata biasa sampai menemukan spasi
        while (teks[*pos] != ' ' && teks[*pos] != '\t' &&
               teks[*pos] != '\0' && teks[*pos] != '\n' &&
               teks[*pos] != '\r')
        {

            if (i < maks - 1)
            {
                hasil[i++] = teks[*pos];
            }

            (*pos)++;
        }
    }

    // Akhiri string
    hasil[i] = '\0';

    return 1;
}

// Menambahkan buku ke dalam memori
int tambahBukuKeMemori(Buku b)
{
    Buku *baru = realloc(dataBuku, (jumlahBuku + 1) * sizeof(Buku)); // realloc(pointer, ukuran_baru); => digunakan untuk mengubah ukuran memori yang sebelumnya sudah dialokasikan secara dinamis.

    // jika null maka berarti gagal mendapatkan memori
    if (baru == NULL)
    {
        return 0;
    }

    // jika berhasil maka perbarui dataBuku
    dataBuku = baru;
    dataBuku[jumlahBuku] = b;
    jumlahBuku++;

    return 1;
}

// Menambahkan user ke dalam memori
static int tambahUserKeMemori(User u)
{
    User *baru = realloc(dataUser, (jumlahUser + 1) * sizeof(User));

    if (baru == NULL)
    {
        return 0;
    }

    dataUser = baru;
    dataUser[jumlahUser] = u;
    jumlahUser++;

    return 1;
}

// Menambahkan peminjaman ke dalam memori
int tambahPinjamKeMemori(Peminjaman p)
{
    Peminjaman *baru = realloc(dataPinjam, (jumlahPinjam + 1) * sizeof(Peminjaman));

    if (baru == NULL)
    {
        return 0;
    }

    dataPinjam = baru;
    dataPinjam[jumlahPinjam] = p;
    jumlahPinjam++;

    return 1;
}
