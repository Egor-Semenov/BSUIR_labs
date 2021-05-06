#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

#pragma warning(disable: 4996);

using namespace std;
FILE* fl;

typedef struct {
    char surname[40];
    int ticket_number;
    double laggedge_weight;
} passengers;

passengers pas[15];


char FileName[30];
int n = 0;

int menu();
void vvodname();
void newfile();
void spisok();
void sortirovka();
void s_vst();
void s_qs();
void openfile();
void result();
void resultfile();

int main()
{
    setlocale(0, "");

    cout << "Пожалуйста, осуществляйте ввод латиницей!" << endl << endl;

    while (true) {
        switch (menu()) {
        case 1:vvodname(); break;
        case 2:newfile(); break;
        case 3:spisok(); break;
        case 4:sortirovka(); break;
        case 5:openfile(); break;
        case 6:result(); break;
        case 7:resultfile(); break;
        case 8:return 0;
        default:"Ошибка, выберите один из заданных вариантов";
        }

        getch();
        system("cls");
    } return 0;
}


int menu() {
    cout << "Выбери 1-8:" << endl;
    cout << "1-Ввод имени файла" << endl;
    cout << "2-Создание нового файла" << endl;
    cout << "3-Задание параметров" << endl;
    cout << "4-Сортировка" << endl;
    cout << "5-Вывод данных файла на данный момент" << endl;
    cout << "6-Вывод результата" << endl;
    cout << "7-Сохранить результат в файл" << endl;
    cout << "8-Выход" << endl;
    int i;
    cin >> i;
    return i;
}


void vvodname() {
    cout << "Введи имя файла" << endl;
    cin >> FileName;
}


void newfile() {
    if ((fl = fopen(FileName, "wb")) == NULL) {
        cout << "Ошибка при создании" << endl;
        exit(1);
    }
    cout << "Файл создан" << endl;
    fclose(fl);
}

void s_qs(passengers ps[], int n) {
    if ((fl = fopen(FileName, "rb+")) == NULL) {
        cout << "Ошибка при попытке сортировки" << endl;
        exit(1);
    }

    struct {
        int l;
        int r;
    } stack[20];

    int i, j, left, right, x, s = 0;
    passengers t;
    stack[s].l = 0; stack[s].r = n - 1;
    while (s != -1) {
        left = stack[s].l; right = stack[s].r;
        s--;
        while (left < right) {
            i = left; j = right; x = ps[(left + right) / 2].laggedge_weight;
            while (i <= j) {
                while (ps[i].laggedge_weight < x) i++;
                while (ps[j].laggedge_weight > x) j--;
                if (i <= j) {
                    t = ps[i]; ps[i] = ps[j]; ps[j] = t;
                    i++; j--;
                }
            }

            if ((j - left) < (right - i)) {
                if (i < right) { s++; stack[s].l = i; stack[s].r = right; }
                right = j;
            }
            else {
                if (left < j) { s++; stack[s].l = left; stack[s].r = j; }
                left = i;
            }
        }
    }

    for (int h = 0; h < n; h++) {
        fwrite(&pas[h], sizeof(passengers), 1, fl);
    }

    cout << "Сортировка выполнена успешно";

    fclose(fl);
}

void s_vst(passengers a[], int n)
{
    if ((fl = fopen(FileName, "rb+")) == NULL) {
        cout << "Ошибка при попытке сортировки" << endl;
        exit(1);
    }

    int i, j;
    passengers t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        for (j = i - 1; j >= 0 && t.laggedge_weight < a[j].laggedge_weight; j--)   a[j + 1] = a[j];
        a[j + 1] = t;
    }

    for (int h = 0; h < n; h++) {
        fwrite(&pas[h], sizeof(passengers), 1, fl);
    }

    cout << "Сортировка выполнена успешно";

    fclose(fl);
}

void sortirovka() {
    int h;
    cout << "Выбери метод сортировки" << endl << "1 - QuickSort    2 - Сортировка вставкой" << endl; cin >> h;
    switch (h) {
    case 1: s_qs(pas, n); break;
    case 2: s_vst(pas, n); break;
    default: cout << "Ошибка, выберите один из заданных вариантов";
    }
}


void spisok() {
    if ((fl = fopen(FileName, "rb+")) == NULL) {
        cout << "Ошибка при открытии" << endl;
        exit(1);
    }

    cout << "Введи количество пассажиров: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введи фамилию: ";
        cin >> pas[i].surname;
        cout << "Введи номер билета: ";
        cin >> pas[i].ticket_number;
        cout << "Введи вес багажа: ";
        cin >> pas[i].laggedge_weight;
        fwrite(&pas[i], sizeof(passengers), 1, fl);
        cout << endl;
    }

    fclose(fl);
}





void openfile() {
    if ((fl = fopen(FileName, "rb")) == NULL) {
        cout << "Ошибка при открытии" << endl;
        exit(1);
    }

    n = 0;
    passengers k;
    while (true) {
        int r = fread(&k, sizeof(passengers), 1, fl);
        if (r != 1)  break;
        pas[n] = k;
        cout << pas[n].surname << " " << pas[n].ticket_number << " " << pas[n].laggedge_weight << " " << endl;
        n++;
    }
    fclose(fl);
}


void result() {
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j < n - 1; j++)
        {
            char t[15];
            int k;
            int p;
            if (strcmp(pas[j].surname, pas[j + 1].surname) == 1)
            {
                strcpy_s(t, pas[j].surname);
                strcpy_s(pas[j].surname, pas[j + 1].surname);
                strcpy_s(pas[j + 1].surname, t);

                k = pas[j].laggedge_weight;
                pas[j].laggedge_weight = pas[j + 1].laggedge_weight;
                pas[j + 1].laggedge_weight = k;

                p = pas[j].ticket_number;
                pas[j].ticket_number = pas[j + 1].ticket_number;
                pas[j + 1].ticket_number = p;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (pas[i].laggedge_weight <= 15)
            cout << pas[i].surname << endl;
    }
}


void resultfile() {

    char namet[30];
    FILE* ft;
    cout << "Введите имя файла:" << endl;
    cin >> namet;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j < n - 1; j++)
        {
            char t[15];
            int k;
            int p;
            if (strcmp(pas[j].surname, pas[j + 1].surname) == 1)
            {
                strcpy_s(t, pas[j].surname);
                strcpy_s(pas[j].surname, pas[j + 1].surname);
                strcpy_s(pas[j + 1].surname, t);

                k = pas[j].laggedge_weight;
                pas[j].laggedge_weight = pas[j + 1].laggedge_weight;
                pas[j + 1].laggedge_weight = k;

                p = pas[j].ticket_number;
                pas[j].ticket_number = pas[j + 1].ticket_number;
                pas[j + 1].ticket_number = p;
            }
        }
    }


    if ((ft = fopen(namet, "w")) == NULL) {
        cout << "Ошибка при открытии" << endl;
        exit(1);
    }
    char s[100];

    for (int i = 0; i < n; i++)
        if (pas[i].laggedge_weight <= 15)
        {
            strcpy(s, pas[i].surname);
            strcat(s, " ");
            fputs(s, ft);
        }
    fclose(ft);
}