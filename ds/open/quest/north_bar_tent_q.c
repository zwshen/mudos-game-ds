// tmr 2007/03/06

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "龍皮帳篷的材料";
}

// 任務描述
string getDetail() {
    string msg;
        msg  = "為了感謝你幫忙北蠻村解決掉千年古洞的問題，只要收集五個龍皮及一個脊骨給李按，\n";
        msg += "，李按就能幫你做出一個好用的龍皮帳篷。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 35;
}

/* 接受任務的前置條件，可能是
        1. 等級需求
        2. 職業需求
        3. 種族需求
        4. 已完成某些任務需求
    等等，應可以自由發揮才是。
    回傳非零值表示符合條件。
 */
int preCondition(object player) {
    if( player->isSolved("/open/quest/north_bar_q1.c") == -1 ) return 0;
    if( player->isSolved("/open/quest/north_bar_q2.c") == -1 ) return 0;
    if( player->isSolved("/open/quest/north_bar_q3.c") == -1 ) return 0;

    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/north_bar/npc/lee_an.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/north_bar/npc/lee_an.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：聽說你幫我們村解決掉千年古洞的問題，真是太感謝你了。\n",
        "$N對著$n說道：你可以收集五個龍皮及一個脊骨給我，我就能幫你做一個好用的帳篷。。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
          return ([]);
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/open/world1/tmr/north_bar/npc/obj/dinosaur-chine.c": 1,
        "/open/world1/tmr/north_bar/npc/obj/dinosaur-skin.c": 5,
    ]);
    return item;
}


// 完成任務的條件除了系統提供的
// 1. 搜集物品
// 2. 殺了足夠數量的怪物之外
// 有需要的話，還可以自訂完成任務條件
// return 1, 為滿足條件, return 0;為失敗
int postCondition(object player, object npc)
{
    return 1;
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：不錯不錯，等我一下子，我馬上就做帳篷。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg = "";
    msg += "一頂龍皮帳篷。\n";
    return msg;
}

void reward(object player, object npc) {

        new("/open/world1/tmr/obj/dragon-tent.c")->move(player);
        tell_object(player, HIY"(你獲得了一頂龍皮帳篷。)\n"NOR);
}

