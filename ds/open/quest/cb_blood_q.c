// tmr 2007/03/10

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "碎骨血塊";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "取來半獸人血液跟肋骨吧，桃盛可以幫你提煉出碎骨血塊。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 40;
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
    if( player->isSolved("/open/quest/cb_q1.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/dragoncity/npc/tao-sheng.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/tao-sheng.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：碎骨寨的半獸人血液具有奇異的毒效。\n",
        "$N對著$n說道：如果你覺得自已臂力太大，我倒是可以幫你一個忙。\n",
        "$N對著$n說道：取來半獸人血液跟肋骨吧，我可以提煉出碎骨血塊。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
        return ([ ]);
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
//        return ([]);

    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/orc_blood.c": 1,
        "/open/world1/tmr/crush_bone/npc/obj/orc_rib.c": 1,

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
        "$N對著$n說道：嗯，我馬上就做給你，請稍等一下。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "一塊碎骨血塊(crush-bone blood)。\n";
    msg  += "經驗值 1,000 點。\n";
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
        new("/open/world1/tmr/crush_bone/npc/obj/blood.c")->move(player);
        tell_object(player, HIY"(你獲得一塊碎骨血塊。)\n"NOR);
    player->add("exp", 1000);
    tell_object(player, HIY"(你獲得了 1,000 點經驗值。)\n"NOR);
}

