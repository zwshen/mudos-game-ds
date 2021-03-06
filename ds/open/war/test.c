#include <ansi2.h>

private void create() { seteuid(getuid()); }

// 表示是一個戰爭檔
int isWar() { return 1; }

// 戰爭的持續時間
// 如果設為0, 表示戰爭的持續時間自行設定，不由系統控制
int getDuration() { return 10; }   // 持續 10 分鐘 (600秒)

// 開始戰爭所要執行的操作
// 傳回 1 表示戰爭啟動, 0 表示沒啟動
int doStartWar()
{
    message("world:world1:vision", HIW"    一陣天搖地動，你感覺你懷孕了，有點想吐！\n\n"NOR, users());
    return 1;
}

// 結束戰爭所要執行的操作
// 傳回 1 表示戰爭結束, 0 表示沒結束
int doEndWar()
{
    message("world:world1:vision", HIW"    突然之間，你拉出了一沱屎，再也沒有想吐的感覺！\n\n"NOR, users());
    return 1;
}

void doHeartBeat()
{
}

