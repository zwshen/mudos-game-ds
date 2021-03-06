// tmr 2008/07/22
#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "太陰凝精";
}

// 任務描述
string getDetail() {
    string msg;

    msg = "你必須除去四害，才能學習到太陰凝精。\n";
    msg += "這四害分別是天妖、天魔、貓妖及天殘邪佬，\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 50;
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
    if( player->query("level") < 45 ) return 0;
   // 有技能者，就不能再解
    if( player->query_spell("moon-essence") ) return 0;

    if( player->query_spell("god-fire") < 90 ) return 0;
    if( player->query_spell("god-kill") < 90 ) return 0;
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
        "$N對著$n說道：如果你想要參研太陰凝精，你得要先幫為師除去四害。\n",
        "$N對著$n說道：一是天妖、二是天魔、三是貓妖、四是天殘邪佬。\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/frost/npc/tian-demon.c" : 1,
        "/open/world1/moonhide/area/under/npc/evil.c" : 1, 
        "/open/world1/ksj/east_island/npc/cat-oldwoman.c" : 1,
        "/open/world1/acme/area2/npc/xie.c" : 1,
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
        "$N對著$n說道：喔...你完成了不可能的任務啊，我這就傳授給你吧。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg = "學到「太陰凝精」。\n";
    return msg;
}

void reward(object player, object npc) {
    player->set_spell("moon-essence", 10);
    tell_object(player, HIY"(你學到了太陰凝精。)\n"NOR);
}

