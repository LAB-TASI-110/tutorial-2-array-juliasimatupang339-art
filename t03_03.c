#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk INT_MAX dan INT_MIN
#include <float.h>    // Untuk FLT_MAX dan FLT_MIN (meskipun kita akan pakai inisialisasi rata-rata pertama)
#include <stdbool.h>  // Untuk tipe data bool

int main() {
    int n; // Jumlah baris input
    int current_val;
    int previous_val;

    // Variabel untuk nilai min/max keseluruhan
    int overall_min = INT_MAX;
    int overall_max = INT_MIN;

    // Variabel untuk rata-rata min/max dari pasangan berurutan
    float min_avg_pair = FLT_MAX; // Inisialisasi dengan nilai float terbesar
    float max_avg_pair = FLT_MIN; // Inisialisasi dengan nilai float terkecil

    bool is_first_val = true; // Flag untuk nilai pertama yang dibaca
    bool is_first_pair = true; // Flag untuk pasangan pertama yang diproses

    // Baca jumlah N
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Input N harus integer positif.\n");
        return 1; // Keluar dengan kode error
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &current_val) != 1) {
            fprintf(stderr, "Error: Input harus integer valid.\n");
            return 1;
        }

        // Update overall min dan max
        if (current_val < overall_min) {
            overall_min = current_val;
        }
        if (current_val > overall_max) {
            overall_max = current_val;
        }

        // Proses untuk rata-rata pasangan berurutan
        if (!is_first_val) { // Jika ini bukan angka pertama (sudah ada previous_val)
            float current_pair_avg = (float)(previous_val + current_val) / 2.0f;

            if (is_first_pair) {
                // Inisialisasi min_avg_pair dan max_avg_pair dengan rata-rata pasangan pertama
                min_avg_pair = current_pair_avg;
                max_avg_pair = current_pair_avg;
                is_first_pair = false;
            } else {
                // Update min_avg_pair dan max_avg_pair untuk pasangan berikutnya
                if (current_pair_avg < min_avg_pair) {
                    min_avg_pair = current_pair_avg;
                }
                if (current_pair_avg > max_avg_pair) {
                    max_avg_pair = current_pair_avg;
                }
            }
        } else {
            is_first_val = false; // Angka pertama sudah dibaca
        }

        previous_val = current_val; // Simpan nilai saat ini sebagai nilai sebelumnya untuk iterasi berikutnya
    }

    // Output hasil
    printf("%d\n", overall_min);
    printf("%d\n", overall_max);
    
    // Pastikan setidaknya ada satu pasangan untuk rata-rata
    if (n >= 2) {
        printf("%.2f\n", min_avg_pair);
        printf("%.2f\n", max_avg_pair);
    } else {
        // Jika n < 2, tidak mungkin ada rata-rata pasangan
        // Sesuai contoh, output hanya berlaku jika ada pasangan
        // Namun, jika ada kebutuhan untuk output default, bisa ditambahkan
        printf("N/A\n"); // Atau berikan nilai default, misal 0.00
        printf("N/A\n"); // Atau berikan nilai default, misal 0.00
    }


    return 0; // Keluar tanpa error
}
