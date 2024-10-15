#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

// Функція для рекурсивного пошуку індексу мінімального елемента
int findMinInd(int a[], int n, int i = 0, int minIdx = 0) 
{
    if (i == n) return minIdx;  // Базовий випадок
    if (a[i] < a[minIdx]) minIdx = i;
    return findMinInd(a, n, i + 1, minIdx);  // Рекурсія
}

// Функція для рекурсивного пошуку індексу максимального елемента
int findMaxInd(int a[], int n, int i = 0, int maxIdx = 0) 
{
    if (i == n) return maxIdx;  // Базовий випадок
    if (a[i] > a[maxIdx]) maxIdx = i;
    return findMaxInd(a, n, i + 1, maxIdx);  // Рекурсія
}

// Функція для обміну максимального і мінімального елементів
void swapMaxMin(int a[], int minIdx, int maxIdx) 
{
    int temp = a[minIdx];
    a[minIdx] = a[maxIdx];
    a[maxIdx] = temp;
}

// Рекурсивна функція для виведення масиву
void printArray(int a[], int n, int i = 0) 
{
    if (i == n) 
    {
        cout << endl;
        return;  // Базовий випадок
    }
    cout << a[i] << " ";
    printArray(a, n, i + 1);  // Рекурсія
}

// Рекурсивна функція для обчислення суми та кількості елементів за критерієм
void processArray(int a[], int n, int& sum, int& count, int i = 0) 
{
    if (i == n) return;  // Базовий випадок
    if (a[i] > 0 && !(i % 5 == 0))
    {
        sum += a[i];
        count++;
        a[i] = 0;  // Заміна на нуль
    }
    processArray(a, n, sum, count, i + 1);  // Рекурсія
}

// Основна функція
int main() 
{
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    const int n = 20;
    int a[n];

    // Генерація масиву випадкових чисел у діапазоні від -20 до 50
    for (int i = 0; i < n; i++) 
    {
        a[i] = rand() % 71 - 20;
    }

    // Виведення згенерованого масиву
    cout << "Initial array: ";
    printArray(a, n);

    // Пошук індексів мінімального і максимального елементів
    int minIdx = findMinInd(a, n);
    int maxIdx = findMaxInd(a, n);

    // Обмін максимального і мінімального елементів
    swapMaxMin(a, minIdx, maxIdx);

    // Обчислення суми і кількості елементів за критерієм, і заміна їх на нулі
    int sum = 0, count = 0;
    processArray(a, n, sum, count);

    // Виведення результатів
    cout << "Array after processing: ";
    printArray(a, n);

    cout << "Number of elements: " << count << endl;
    cout << "Sum of elements: " << sum << endl;

    return 0;
}