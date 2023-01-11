/* main.cpp – Листинг главного файла проекта                                                                   */
/***************************************************************************************************************/
/* Filename : main.cpp                                                                                         */
/* Abstract : Это с++ программа, которая главным образом, является "архитектурой" игры крестики-нолики 5x5     */
/* Description :  Данный программный модуль дает возможность игрокам/игроку выбрать тип игры в крестики нолики:*/
/*'человек vs человек'-нажмите 1; 'человек vs компьютер'-нажмите 2', внести имена игроков, выбор "X" или "0",  */
/*реализация ходов в конктерные ячейки игровго поля                                                            */
/* Creation Date : 2022 / 05 / 21                                                                              */
/* Author : Еричев Денис                                                                                       */
/* Notes / Platform / Copyrights : OS Linux, FreeWare                                                          */
/***************************************************************************************************************/
#include <iostream>
#include "ai.h"
#include "funcs.h"
int main(){
    int choice=0;
    int move_count=0;
    int position=0;
    cout<<"Игра крестики нолики.\n";
    /*************************************************************************************************/
    /* Блок выбора типа игры                                                                         */
    /*************************************************************************************************/
    cout<<"Выберите вариант игры: 'человек vs человек'-нажмите 1; 'человек vs компьютер'-нажмите 2': ";
    /* Ввод целочисленного значения: 1 или 2                                                         */
    choice=check_input();
    cout<<"Игра началась:\n";
    /*************************************************************************************************/
    switch(choice){
        /*************************************************************************************************/
        /* Блок типа игры - 'человек vs человек'                                                         */
        case 1:
        cout<<"Игрок 1: ";
        /* Ввод имени/никнейма первого игрока                                                            */
        cin>>first_player;
        cin.ignore(32767,'\n');
        /*************************************************************************************************/
        /* Выбор для первого игрока выбрать "X" или "0", путем ввода целочисленногго значения - 1 или 2  */
        /*************************************************************************************************/
        cout<<"Выберите если  X:нажмите 1, 0-нажмите 2: ";
        choice=check_input();
        /* Если первый игрок выбрал значение - 1, то первый игрок играет крестиками                       */
        if(choice==1){
            first_choice=crosses;
        }/* Конец else- if оператора                                                                     */
        /* Иначе если первый игрок выбрал значение - 2, то первый игрок играет ноликами                  */
        else if(choice==2){
            first_choice=zeros;
        }/* Конец else- if оператора                                                                     */
        /*************************************************************************************************/
        /* Ввод имени/никнейма второгго игрока                                                           */
        /*************************************************************************************************/
        cout<<"Игрок 2: ";
        cin>>second_player;
        /*************************************************************************************************/
        /* Если первый игрок играет крестиками, то второй игрок играет ноликами                          */
        if(first_choice==crosses){
            second_choice=zeros;
        } /* Конец if оператора                                                                          */
        /* Иначе если первый игрок игграет ноликами, то второй игрок играет крестиками                   */
        else if(first_choice==zeros){
            second_choice=crosses;
        }/* Конец else- if оператора                                                                     */
        /* Вывод игрового поля                                                                           */
        play_field();
        /* Перебор целочисленного массива на 25 ячеек                                                    */
        /* который является игровым полем 5x5.                                                           */
        for(int i=0;i<25;i++){
            /*Счетчик ходов, чтобы понимать чей конкретный ход*/
            move_count+=1;
            /*Если ход нечетный, то ходит первый игрок*/
            if(move_count%2!=0){
                /*Вызов функции реализации хода*/
                move(first_player,position,first_choice);
                /*Проверка на выигрыш первого игрока*/
                check_win(first_player);
            }/* Конец if оператора                                                                       */
            /*Если ход четный, то ходит второй игрок*/
            if(move_count%2==0){
                /*Вызов функции реализации хода*/
                move(second_player,position,second_choice);
                /*Проверка на выигрыш второго игрока*/
                check_win(second_player);
            }/* Конец if оператора                                                                       */
            /* Вывод игрового поля                                                                       */
            play_field();
        }/* Конец for оператора                                                                          */
        /* Вызов функции проверки на ничью                                                               */
        tie_game();
        /*************************************************************************************************/
        case 2:
        /* Блок типа игры - 'человек vs компьютер'                                                        */
            cout<<"Игрок 1: ";
            /* Ввод имени/никнейма второго игрока                                                            */
            cin>>first_player;
            cin.ignore(32767,'\n');
            /*************************************************************************************************/
            /* Выбор для первого игрока выбрать "X" или "0", путем ввода целочисленногго значения - 1 или 2  */
            cout<<"Выберите если  X:нажмите 1, 0-нажмите 2: ";
            choice=check_input();
            /* Если первый игрок выбрал значение - 1, то первый игрок играет крестиками                       */
            if(choice==1){
                first_choice=crosses;
            }/* Конец if оператора                                                                              */
            /* Иначе если первый игрок выбрал значение - 2, то первый игрок играет ноликами                     */
            else if(choice==2){
                first_choice=zeros;
            }/* Конец else- if оператора                                                                     */
            cout<<"Игрок 2: Computer"<<endl;
            /* Если первый игрок играет крестиками, то компьютер игрок играет ноликами                          */
            if(first_choice==crosses){
                second_choice=zeros;
            }/* Конец if оператора                                                                              */
            /* Иначе если первый игрок играет ноликами, то компьютер игрок играет крестиками                          */
            else if(first_choice==zeros){
                second_choice=crosses;
            }/* Конец else- if оператора                                                                     */
            /* Вывод игрового поля                                                                           */
            play_field();
            /* Перебор целочисленного массива на 25 ячеек                                                    */
            /* который является игровым полем 5x5.                                                           */
            for(int i=0;i<25;i++){
                /*Счетчик ходов, чтобы понимать чей конкретный ход*/
                move_count+=1;
                /*Если ход нечетный, то ходит первый игрок*/
                if(move_count%2!=0){
                    /*Вызов функции реализации хода*/
                    move(first_player,position,first_choice);
                    /*Проверка на выигрыш первого игрока*/
                    check_win(first_player);
                }/* Конец if оператора                                                                              */
                /*Если ход четный, то ходит компьютер*/
                if(move_count%2==0){
                    cout<<"Ходит Computer."<<endl;
                    /*Вызов функции реализации хода-компьютера*/
                    computerMove(second_choice);
                    /* Вывод игрового поля                                                                           */
                    play_field();
                    /*************************************************************************************************/
                    /*Отдельный блок проверки на выигрыш компьютера, исходя из расстановки на игровом поле*/
                    if(win(second_choice)){
                        /* Вывод игрового поля                                                                           */
                        play_field();
                        cout<<"Выиграл Computer!"<<endl;
                        /*Если компьютер выиграл, завершаем программу                                                  */
                        exit(1);
                    }/* Конец if оператора                                                                              */
                }/* Конец if оператора                                                                              */
            }/* Конец for оператора                                                                          */
        /* В том случае, если все 25 ячеек перебраны, то вызов функции проверки на ничью                             */
        tie_game();
        break;
    }
    return 0;
}
