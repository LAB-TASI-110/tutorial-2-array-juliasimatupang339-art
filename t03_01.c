#include <stdio.h> // Untuk fungsi printf, scanf, fprintf
#include <stdlib.h> // Untuk fungsi EXIT_FAILURE

int main() {
    int n; // Variabel untuk menyimpan jumlah elemen
    int current_num; // Variabel untuk menyimpan bilangan bulat yang sedang dibaca
    int min_val; // Variabel untuk menyimpan nilai minimum
    int max_val; // Variabel untuk menyimpan nilai maksimum

    // Membaca nilai n (jumlah elemen)
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Input untuk n tidak valid.\n");
        return EXIT_FAILURE;
    }

    // Penanganan kondisi jika n tidak valid (n <= 0)
    if (n <= 0) {
        fprintf(stderr, "Error: Jumlah elemen (n) harus bilangan bulat positif.\n");
        return EXIT_FAILURE;
    }

    // Membaca bilangan pertama untuk inisialisasi min_val dan max_val
    if (scanf("%d", &current_num) != 1) {
        fprintf(stderr, "Error: Input bilangan pertama tidak valid.\n");
        return EXIT_FAILURE;
    }
    // Inisialisasi min_val dan max_val dengan bilangan pertama
    min_val = current_num;
    max_val = current_num;

    // Iterasi untuk membaca n-1 bilangan berikutnya dan mencari min/max
    for (int i = 1; i < n; i++) {
        if (scanf("%d", &current_num) != 1) {
            fprintf(stderr, "Error: Input bilangan ke-%d tidak valid.\n", i + 1);
            return EXIT_FAILURE;
        }

        // Membandingkan dengan nilai minimum saat ini
        if (current_num < min_val) {
            min_val = current_num;
        }

        // Membandingkan dengan nilai maksimum saat ini
        if (current_num > max_val) {
            max_val = current_num;
        }
    }

    // Menampilkan nilai terkecil dan terbesar sesuai format
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Mengembalikan 0 sebagai indikasi sukses
}