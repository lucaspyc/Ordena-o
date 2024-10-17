#include <iostream>
#include <vector>
#include <cstdlib>    // Para rand() e srand()
#include <ctime>      // Para time() e medir tempo

using namespace std;

// Estrutura para armazenar as estatísticas de ordenação
struct SortStats {
    int comparacoes = 0;
    int trocas = 0;
};

// Função Bubble Sort
void bubbleSort(vector<int>& arr, SortStats& stats) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            stats.comparacoes++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                stats.trocas++;
            }
        }
    }
}

// Função Selection Sort
void selectionSort(vector<int>& arr, SortStats& stats) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            stats.comparacoes++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        stats.trocas++;
    }
}

// Função Insertion Sort
void insertionSort(vector<int>& arr, SortStats& stats) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        stats.comparacoes++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            stats.trocas++;
            stats.comparacoes++;
        }
        arr[j + 1] = key;
    }
}

// Função para exibir o vetor
void exibirVetor(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função principal que organiza o menu e chama as funções de ordenação
int main() {
    int n, opcao;
    vector<int> arr;
    SortStats stats;

    // Definir o número de elementos
    cout << "Escolha o número de elementos (10, 100, 1000, 10000): ";
    cin >> n;

    arr.resize(n);

    // Preencher o vetor com números aleatórios
    srand(time(0));  // Inicializar o gerador de números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  // Gera números de 0 a 9999
    }

    // Escolher a disposição inicial dos valores
    cout << "Escolha a disposição inicial dos valores:\n1. Aleatório\n2. Ordenado Descendente\nEscolha: ";
    cin >> opcao;
    if (opcao == 2) {
        // Ordenar em ordem descendente manualmente
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Mostrar o vetor antes da ordenação
    cout << "Vetor antes da ordenação:\n";
    exibirVetor(arr);

    // Escolher o algoritmo de ordenação
    cout << "Escolha o algoritmo de ordenação:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n";
    cin >> opcao;

    // Medir o tempo de execução
    clock_t inicio = clock();

    switch (opcao) {
        case 1:
            bubbleSort(arr, stats);
            break;
        case 2:
            selectionSort(arr, stats);
            break;
        case 3:
            insertionSort(arr, stats);
            break;
        default:
            cout << "Opção inválida!\n";
            return 1;
    }

    clock_t fim = clock();
    double duracao = double(fim - inicio) / CLOCKS_PER_SEC;

    // Mostrar o vetor após a ordenação
    cout << "Vetor após a ordenação:\n";
    exibirVetor(arr);

    // Mostrar as estatísticas de ordenação
    cout << "Número de comparações: " << stats.comparacoes << endl;
    cout << "Número de trocas: " << stats.trocas << endl;
    cout << "Tempo de execução: " << duracao << " segundos" << endl;

    return 0;
}
