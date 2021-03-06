// tmr 2007/03/02
#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "寒澈道觀四靈神獸";
}

// 任務描述
string getDetail() {
    string msg;

    msg = "寒澈道觀的藏經閣一直是道教聖地，傳聞藏經閣七樓藏有奇書，\n";
    msg += "研讀此書有望能勘破天道。但是藏經閣五樓被四靈神獸保護著，\n";
    msg += "不讓人上去，所以你受蕭日山之託，希望能誅殺這四獸。\n";

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
        if( player->query("level") < 35 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/acme/area/npc/advmaster.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/acme/area/npc/advmaster.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：寒澈道觀的藏經閣一直是道教聖地，傳聞藏經閣七樓藏有奇書。\n",
        "$N對著$n說道：研讀此書有望能勘破天道。但是藏經閣五樓被四靈神獸保護著，不讓人上去。\n",
        "$N對著$n說道：不知道這位英雄是否願意幫我清除這四獸？\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
         "/open/world1/tmr/frost/npc/dragon-elephant.c" : 1,
         "/open/world1/tmr/frost/npc/bird-elephant.c" : 1,
         "/open/world1/tmr/frost/npc/tiger-elephant.c" : 1,
         "/open/world1/tmr/frost/npc/turtle-elephant.c" : 1,
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
    msg = "經驗 100,000 點。\n";
    msg += "聲望 10 點。\n";
    msg += "戰鬥藝術 20 點。\n";
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

    message("world:world1:vision",
                HIG"\n【道派消息】" + HIM "寒澈道觀四靈神獸龍象、虎象、鳥象及龜象，竟然全被"+player->name(1)+HIM "給誅殺了！！\n"+NOR, users());

    player->add("exp", 100000);
    tell_object(player, HIY"(你獲得了 100,000 點經驗值。)\n"NOR);
    player->add("popularity", 10);
    tell_object(player, HIY"(你獲得了 10 點聲望。)\n"NOR);
    player->add("war_art", 20);
    tell_object(player, HIY"(你獲得了 20 點戰鬥藝術。)\n"NOR);
}

