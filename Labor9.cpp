//22. Заданий рядок, що містить розділені пробілами слова. Визначити всі наявні в рядку слова-паліндроми і їхню кількість
#include <iostream>
#include <cstring>

using namespace std;
char myL[100];     //Виділення пям'яті під рядок
void spliting();   //розділення на слова
bool palyndrom(char[], int);   //Чи виконується умова паліндрому?
int main() {
    puts("Space for your line:");
    gets_s(myL);    //введення рядка
    spliting();     // розділення на слова, в ній викликатимуться паліндроми
    return 0;
}
void spliting() {
    int length;
    char c[20];   //додатковий масив для слова, що перевіряється на паліндромність
    int Num = 0;   //кількість паліндромів
    char* p;     
    char* np = NULL;
    const char* del = " ";
    p = strtok_s(myL, del, &np);   //виділення в пям'ять p з myL частини до пробілу
    while (p != NULL) {
        strcpy_s(c, sizeof c, p);   //копіювання слова в додатковий масив
        length = strlen(c);
        if (palyndrom(c, length)) {   //перевірка паліндрому
            puts(p);                  //виведення паліндрому
            Num++;                    //підрахунок паліндромів
        }
        p = strtok_s(NULL, del, &np);   //пошук нового слова
    }
    cout << "Num is: " << Num << endl;   //виведення кількості
}
bool palyndrom(char line[],  int l) {
    bool pal = true;
    for (int i = 0; i < l/2; i++) {     //перевірка до половини слова
        if (line[i] != line[l - (1 + i)])  //перевірка однакових символів на початку та вкінці слова
            pal = false;
    }
    return pal;
}
