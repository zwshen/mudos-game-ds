// tmr 2007/02/28

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "義助萬斧莊";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "萬斧莊的弟子被困寒日洞出不來，你受周瑛之託，希望能去洞內\n";
    msg += "清掉行屍走肉、瘋漢跟瘋婆子，好救出她的兩位師兄。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 20;
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
        if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/bagi/npc/zhou-ying.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
     return "/open/world1/tmr/bagi/npc/zhou-ying.c";

}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N高興的跳了起來。\n"NOR,
        "$N對著$n說道：真是謝謝這位大俠的幫助。\n",
        "$N對著$n說道：我聽說寒日洞內都是會吃人的行屍走肉，還有亂殺人的瘋漢跟瘋婆子！\n",
        "$N對著$n說道：我那兩位師兄困在裡面出不來，希望你能幫我清掉那些駭人的怪物。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/bagi/area/2f/npc/corpse.c": 10,
        "/open/world1/tmr/bagi/area/2f/npc/madman.c": 2,
        "/open/world1/tmr/bagi/area/2f/npc/madwoman.c": 2,
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
        "$N對著$n說道：真是感謝你呀！\n",
        "$N對著$n說道：希望人傑跟英傑兩位師兄能趕快出洞來。\n",
        CYN"$N又開始焦急地等待著。\n"NOR,
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "經驗值 50,000 點。\n";
    msg += "聲望 5 點。\n";
    msg += "戰鬥藝術 2 點。\n";
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
        player->add("exp", 50000);
    tell_object(player, HIY"(你獲得了 50000 點經驗值。)\n"NOR);
        player->add("popularity", 5);
    tell_object(player, HIY"(你獲得了 5 點聲望。)\n"NOR);
        player->add("war_art", 2);
    tell_object(player, HIY"(你獲得了 2 點戰鬥藝術。)\n"NOR);

}

