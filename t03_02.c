#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk FLT_MAX atau DBL_MAX, meskipun 1e38 juga bisa

int main() {
    int n;
    int current_num;
    int prev_num;
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer terbesar
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer terkecil
    float min_avg = FLT_MAX; // Inisialisasi min_avg dengan nilai float terbesar
    float current_avg;
    int i;

    // Membaca jumlah data n
    scanf("%d", &n);

    // Memastikan n cukup untuk setidaknya satu pasangan rata-rata
    if (n < 1) {
        printf("Jumlah data harus minimal 1.\n");
        return 1; // Keluar dengan kode error
    }

    // Memproses angka pertama secara terpisah untuk inisialisasi prev_num
    scanf("%d", &prev_num);
    min_val = prev_num;
    max_val = prev_num;

    // Loop untuk sisa (n-1) angka
    for (i = 1; i < n; i++) {
        scanf("%d", &current_num);

        // Update nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Hitung rata-rata pasangan dan perbarui min_avg
        current_avg = (float)(prev_num + current_num) / 2.0;
        if (current_avg < min_avg) {
            min_avg = current_avg;
        }

        // Simpan current_num menjadi prev_num untuk iterasi berikutnya
        prev_num = current_num;
    }

    // Output hasil
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    // Jika n < 2, tidak ada pasangan yang terbentuk, jadi min_avg mungkin masih FLT_MAX.
    // Asumsi prompt n >= 2 untuk average. Jika n=1, maka rata-rata tidak valid.
    if (n >= 2) {
        printf("%.2f\n", min_avg);
    } else {
        printf("Tidak cukup data untuk menghitung rata-rata pasangan.\n");
    }

    return 0;
}