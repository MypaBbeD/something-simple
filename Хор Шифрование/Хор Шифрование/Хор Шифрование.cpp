#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;
int GetPossitiveInt();
int main(){
	cout << "Здесь был илья " << endl;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    fstream File;
    fstream Key;
    int fsize,ksize;
    char FName[100],KName[100];
    for(;;){
        cout<<"1 - Для указания файла для шифрования/дешифрования"<<endl<<"2 - Для указания файла с ключом шифрования"<<endl<<"3 - Для генерации ключа шифрования"<<endl<<"4 - Для шифрования файла"<<endl<<"5 - Для дешифрования файла"<<endl<<"6 - Для выхода"<<endl<<endl<<"Введите: ";
        int n=GetPossitiveInt();
        switch(n){
            case 0:
                system("cls");
                cout<<"Ошибка ввода"<<endl;
                system("pause");
                system("cls");
                break;
            case 1:
                system("cls");
                cout << "Введите расположение файла: ";
                cin>>FName;
                File.open(FName);
                if(!File.is_open()) {
                    system("cls");
                    cout<<"Файл не найден, Датвиданья"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
                system("cls");
                cout<<"Успешно, Файл найден"<<endl;
                system("pause");
                system("cls");
                File.seekg(0,ios_base::end);
                fsize=File.tellg();
                File.close();
                break;
            case 2:
                system("cls");
                cout << "Введите расположение файла: ";
                cin>>KName;
                Key.open(KName);
                if(!Key.is_open()) {
                    cout<<"Файл не найден, Датвиданья"<<endl;
                    break;
                }
                system("cls");
                cout<<"Файл найден"<<endl;
                system("pause");
                system("cls");
                Key.seekg(0,ios_base::end);
                ksize=Key.tellg();
                Key.close();
                break;
            case 3:
                system("cls");
                cout<<"Укажите директорию для записи ключа: ";
                cin>>KName;
                Key.open(KName,ios_base::binary|ios_base::out);
                srand(time(NULL));
                for(int t=0;t!=fsize;t++){
                    byte a=rand();
                    Key.put(a);
                }
                Key.seekg(0,ios_base::end);
                ksize=Key.tellg();
                Key.close();
                Key.close();
                system("cls");
                cout<<"Ключ сгенерирован"<<endl;
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                if(fsize!=ksize){
                    cout<<"Размер файла и ключа различаются"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
                File.open(FName,ios_base::binary|ios_base::in|ios_base::out);
                Key.open(KName,ios_base::binary|ios_base::in);
                for(int t=0;t!=fsize;t++){
                    byte a,b;
                    File.seekg(t);
                    a=File.get();
                    Key.seekg(t);
                    b=Key.get();
                    a^=b;
                    File.seekg(t);
                    File.put(a);
                }
                File.close();
                Key.close();
                cout<<"Файл успешно зашифрован"<<endl;
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                if(fsize!=ksize){
                    cout<<"Размер файла и ключа различаются"<<endl;
                    break;
                }
                File.open(FName,ios_base::binary|ios_base::in|ios_base::out);
                Key.open(KName,ios_base::binary|ios_base::in);
                for(int t=0;t!=fsize;t++){
                    byte a,b;
                    File.seekg(t);
                    a=File.get();
                    Key.seekg(t);
                    b=Key.get();
                    a^=b;
                    File.seekg(t);
                    File.put(a);
                }
                File.close();
                Key.close();
                cout<<"Файл успешно расшифрован"<<endl;
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                return 0;
            default:
                system("cls");
                cout<<"Ошибка ввода"<<endl;
                system("pause");
                system("cls");
        }
    }
    return 0;
}
int GetPossitiveInt(){
        int n;
        cin >> n;
        if (cin.good()){
            return n;
        }
        else{
            cin.clear();
            _flushall();
            return 0;
    }
}



