// tmr 2007/03/10

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "消滅無寧屍仙";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "無寧屍仙是無寧莊園的統治者，這一次，了塵希望你能滅滅屍仙。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 45;
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
    if( player->query("level") < 40 ) return 0;
    if( player->isSolved("/open/quest/un_q1.c") == -1) return 0;
      if( player->isSolved("/open/quest/un_q2.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
         return "/open/world1/manto/pudu_mountain/npc/bonze.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
         return "/open/world1/manto/pudu_mountain/npc/bonze.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：無寧屍仙是無寧莊園的統治者，殺的生實在太多了，天理難容。\n",
        "$N對著$n說道：無寧屍仙平常是深居在血池之中，你必須要準備幾塊生血肉，才能引他出來。\n",
        "$N對著$n說道：施主是蒼生的救世主，老納再拜託你一次了。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping item = ([
       "/open/world1/tmr/unquiet_manor/npc/corpse_king.c": 1,
     ]);
    return item;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
        return ([]);
/*
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/war_plan.c": 1,
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
        "$N對著$n說道：阿彌陀佛，施主功\德無量，佛祖保佑你。\n",    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
      msg  = "經驗值 300,000 點。\n";
    msg += "戰爭藝術 30 點。\n";
    return msg;
}

/*  任務獎勵
    獎勵應該能自由發揮，如：
        1. 獲得經驗
        2. 獲得物品
        3. 獲得短暫Buff
        4. 習得某技能
        5. 更改玩家狀態, ex: 轉職
 */
void reward(object player, object npc) {
     player->add("exp", 300000);
     tell_object(player, HIY"(你獲得了 300,000 點經驗值。)\n"NOR);
    player->add("war_art", 30);
    tell_object(player, HIY"(你獲得了 30 點戰爭藝術。)\n"NOR);
}



