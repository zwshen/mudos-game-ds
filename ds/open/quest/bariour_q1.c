// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "辛若羽的委託";
}

// 任務描述
string getDetail() {
return "
辛若羽(Xin reu yue)是天城布莊的老闆娘，她店鋪所
賣的布匹都是上選的極品。最近由於她店鋪的生意非常
的好，導致毛料短缺，因此她希望妳能到北方大森林跑
一趟，幫她搜集一些高品質的羊毛。
";
}

// 任務等級
int getLevel() {
    return 15;
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
   if( player->query("level") < 15 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/acme/area/npc/lin.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/acme/area/npc/lin.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：最近生意太好，羊毛料短缺，希望你能幫我到北方大森林跑一趟。\n",
        "$N對著$n說道：在那森林深處，聽說有非常高品質的羊毛。\n",
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
    mapping item = ([
        "/open/world1/tmr/goat_maze/npc/obj/bariour_fur.c": 20, 
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
        "$N對著$n說道：真是太謝謝你的幫忙！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "一萬枚銅板。\n";
    msg += "經驗值 10 萬。\n";
    return msg;
}


void reward(object player, object npc) {
        player->add("bank/past", 10000);
    tell_object(player, HIY"(你獲得了一萬枚銅板。)\n"NOR);
        player->add("exp", 100000);
    tell_object(player, HIY"(你獲得了 10 萬點經驗值。)\n"NOR);
}

