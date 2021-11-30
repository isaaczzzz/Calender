/*********************
 * 设置闹钟            *
 * *******************/
#include "connection.h"

void SetAlarm(void)
{
    time_t timep;
    struct tm *p;
    int hour, min, end = 0;

    system("cls");
    //边框
    PrintRows(44, 70, 7, UP);
    PrintColumns(8, 17, 44);
    PrintRows(44, 70, 18, DOWN);
    PrintColumns(8, 17, 70);
    go(56, 10);
    printf("闹钟");
    go(50, 13);
    printf("输入时间: __:__\b\b\b\b\b");
    scanf("%d%d", &hour, &min);

    while(!end) {
        time(&timep);
        p = gmtime(&timep);

        system("cls");
        //边框
        PrintRows(44, 70, 7, UP);
        PrintColumns(8, 17, 44);
        PrintRows(44, 70, 18, DOWN);
        PrintColumns(8, 17, 70);
        go(56, 10);
        printf("闹钟");
        go(55, 11);
        printf("%02d:%02d", hour, min);
        go(55, 13);
        printf("现在是");
        go(53, 14);
        printf("▇ %02d:%02d ▇", p -> tm_hour + 8, p -> tm_min);//时区

        CONSOLE_CURSOR_INFO cursor_info = {1, 0};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏光标
        Sleep(1000);
        if(p -> tm_hour + 8 == hour && p -> tm_min == min) {
            system("cls");
            go(52, 12);
            end = 1;
        }
    }

    end = 0;
    while(!end){
        int key = 0;
        if(kbhit()){
            key = getch();
        }
        if(key == ESC)
            main();
        Sleep(300);
        system("cls");
        go(54, 13);
        printf("\a▇ 时间到 ▇\a");
        go(50, 15);
        printf("按下ESC返回主界面...");
        key = 0;
        if(kbhit()){
            key = getch();
        }
        if(key == ESC) {
            end = 1;
            main();
        }
    }
    getchar();
    getchar();
    system("cls");
    main();
}