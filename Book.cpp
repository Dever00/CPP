#include <Windows.h>
#include <iostream>
#include <cstring>
#include <clocale>
#include <cstdio>
using namespace std;

class Book {
    char Autor[40];
    char Title[40];
    char Publish[40];
    int Year;
    int Sheet_num;
public:
    Book (const char *a,const char *b,const char *c, int i, int n)
    {
        strcpy(Autor, a);
        strcpy(Title, b);
        strcpy(Publish, c);
        Year = i;
        Sheet_num = n;
    }

    char *get_aut() {return Autor;}
    char *get_tit() {return Title;}
    char *get_pub() {return Publish;}
    int get_year() {return Year;}
    int get_num() {return Sheet_num;}

    void set_aut(char *aut) {strcpy(Autor, aut);}
    void set_tit(char *tit) {strcpy(Title, tit);}
    void set_pub(char *pub) {strcpy(Publish, pub);}
    void set_year(int y) {Year = y;}
    void set_num(int num) {Sheet_num = num;}

    void show() {
        cout << "Автор: " << Autor<<'\t';
        cout << "Название книги: " << Title <<'\t';
        cout << "Издательство: " << '\"'<< Publish <<'\"'<< '\t';
        cout << "Год издания: " << Year <<'\t';
        cout << "Количество страниц: " << Sheet_num<<"\n\n";
    }

};

void SeekOnAutor(const char *str, Book *ob) {
    cout << "Список книг автора " << str << ": ";
    for(int i=0; i<6; i++) {

        if(!strcmp((ob[i].get_aut()), str)) ob[i].show();
    }
    cout << '\n';
}

void SeekOnPublish(const char *str, Book *ob) {
    cout << "Список книг издательства " << str << ": ";
    for(int i=0; i<6; i++) {

        if(!strcmp((ob[i].get_pub()), str)) ob[i].show();
    }
    cout << '\n';
}

void SeekOnYear(int h, Book *ob) {
    cout << "Список книг после указанного года издания " << h << ": ";
    for(int i=0; i<6; i++) {

        if(ob[i].get_year() >= h) ob[i].show();
    }
    cout << '\n';
}

int main()

{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Book ob[] = {
        Book("Верн","20 000 лье под водой","Extremo",1995,125),
        Book("Достоевский", "Преступление и наказание", "Extremo", 2000, 350),
        Book("Достоевский", "Белые ночи", "Piter", 1998, 200),
        Book("Шекспир", "Гамлет", "Extremo", 1999, 100),
        Book("Шекспир", "Король Лир", "Piter", 1996, 150),
        Book("Верн", "Вокруг света за 80 дней", "Piter", 1997, 150)
    };
    ob[1].show();
    ob[2].show();
    ob[3].show();
    ob[4].show();
    ob[5].show();
    ob[6].show();

    char choice, str[40];
    int h;

        for (;;) {
        do {
            cout<< "Выберите пункт меню:" << '\n'
            << " 1. Список книг по автору" << '\n'
            << " 2. Список книг по наименованию издательства" << '\n'
            << " 3. Список книг после указанного года издания" << '\n'
            << "Выберите вариант справки (q для выхода): ";
            cin>> choice;
        } while (choice<'1' || choice>'3'&& choice!='q');
        if (choice=='q') break;
        cout<<"\n\n";
        switch(choice) {
            case '1':
                cout << "Введите имя автора: ";
                cin >> str;
                SeekOnAutor(str, ob);
                break;
            case '2':
                cout << "Введите наименование издательства: ";
                cin >> str;
                SeekOnPublish(str, ob);

                break;
            case '3':
                cout << "Введите отправной год: ";
                cin >> h;
                SeekOnYear(h, ob);
                break;
        }
        cout<<"\n";
        }

    return 0;
}
