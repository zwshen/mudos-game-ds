// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "清除黑暗及恐怖巨魔";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "苗家村座落在北方大森林旁，由於森林中住著食人肉的巨魔，村民整天\n";
    msg += "過著提心吊膽的生活，宗族長希望你能進一步幫忙清除更兇猛的黑暗巨魔。\n";
    msg += "及恐怖巨魔。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 30;
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
   if( player->query("level") < 30 ) return 0;
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：森林深處住著更兇猛的黑暗巨魔跟恐怖巨魔。\n",
        "$N對著$n說道：為了苗家村的安全，一定要將巨魔消滅掉！！\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/north_forest/npc/troll4.c": 3, 
        "/open/world1/tmr/north_forest/npc/troll5.c": 3, 
        ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
return ([]);
/*
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // 猴牙
    ]);
    return item;
*/
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
        "$N對著$n說道：真是太謝謝你的幫忙！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg = "五萬枚銅板。\n";
    msg += "經驗值 100,000 點。\n";
    msg += "聲望 3 點。\n";
    msg += "戰鬥藝術 6 點。\n";
    return msg;
}


void reward(object player, object npc) {
    player->add("bank/past", 50000);
    tell_object(player, HIY"(你獲得了 五萬枚銅板。)\n"NOR);
    player->add("exp", 100000);
    tell_object(player, HIY"(你獲得了 100,000 點經驗值。)\n"NOR);
    player->add("popularity", 3);
    tell_object(player, HIY"(你獲得了 3 點聲望。)\n"NOR);
    player->add("war_art", 6);
    tell_object(player, HIY"(你獲得了 6 點戰鬥藝術。)\n"NOR);
}

