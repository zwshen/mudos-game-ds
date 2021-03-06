// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// 任務名稱
string getName() {
    return "苗青守衛長的獎勵";
}

// 任務描述
string getDetail() {
        return "天壇守衛長苗青(Meo chen)非常感激你為苗家村做的一切
，不過他希望你能拾來巨魔的殘骸，好証明你的貢獻，他能給你一些高級的
卷軸，做為酬謝。
";
}

// 任務等級
int getLevel() {
    return 40;
}

int preCondition(object player) {
   if( player->query("level") < 40 ) return 0;
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q3.c") == -1) return 0;

    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/sky_leader.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/sky_leader.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：真是非常感謝你對苗家村的幫忙。\n",
        "$N對著$n說道：要是你能取來巨魔的遺駭，我可以給你一些卷軸當做報酬。\n",
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
        "/open/world1/tmr/north_forest/npc/obj/troll_blood.c": 10,
        "/open/world1/tmr/north_forest/npc/obj/troll_chest_bone.c": 5,
        "/open/world1/tmr/north_forest/npc/obj/troll_head_bone.c": 5,
        "/open/world1/tmr/north_forest/npc/obj/troll_spinal_bone.c": 2,
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
        "真是非常感謝你對苗家村的幫忙，這幾張卷軸就送給你了。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return "100%, 60%, 10% 力量、體質、智慧、敏捷卷軸隨機二張。";
}

string *items = ({
         "100_str.c",         "100_con.c",         "100_dex.c",         "100_int.c",
         "60_str.c",         "60_con.c",         "60_dex.c",         "60_int.c",
         "10_str.c",         "10_con.c",         "10_dex.c",         "10_int.c",
});

void reward(object player, object npc) {
    new("/open/enhance/" + items[random(9)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/" + items[random(9)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
}

