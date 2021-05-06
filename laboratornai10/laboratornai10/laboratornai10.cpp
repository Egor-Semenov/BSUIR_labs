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
        case 4:openfile(); break;
        case 5:result(); break;
        case 6:resultfile(); break;
        case 7:return 0;
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
    cout << "4-Вывод данных файла на данный момент" << endl;
    cout << "5-Вывод результата" << endl;
    cout << "6-Сохранить результат в файл" << endl;
    cout << "7-Выход" << endl;
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
        cout << pas[n].surname << " " << pas[n].ticket_number << " " << pas[n].laggedge_weight << " "  << endl;
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


