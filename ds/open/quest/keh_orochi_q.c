// tmr 2007/07/08
#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "殲滅八岐大蛇";
}

// 任務描述
string getDetail() {
    string msg;

    msg =  "遠在海外有個神祕的東方島，在島上的出雲山住著八岐大蛇，\n";
    msg += "那是八條非常兇猛、食人無數的妖蛇，如果您能殲滅八岐大蛇\n";
    msg += "，索貝克可以給您一份報酬。\n";

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
    if( player->query("level") < 45 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/whoami/birdarea/npc/hero.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/whoami/birdarea/npc/hero.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：遠在海外有個神祕的東方島，在島上的出雲山住著八岐大蛇。\n",
        "$N對著$n說道：那是八條非常兇猛、食人無數的妖蛇，如果您能殲滅八岐大蛇。\n",
        "$N對著$n說道：我可以給您一份不菲的報酬\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
         "/open/world1/ksj/east_island/npc/orochi-green-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-black-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-white-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-purple-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-blue-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-gold-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-red-head.c" : 1,
         "/open/world1/ksj/east_island/npc/orochi-grey-head.c" : 1,
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
        "$N對著$n說道：你的武藝的確非常驚人，我索貝克佩服到五體投地啊。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg = "經驗 800,000 點。\n";
    msg += "戰鬥藝術 80 點。\n";
    msg += "隨機素質10%卷軸一張。\n";
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

string *items = ({
        "10_bar.c",
        "10_bio.c",
        "10_wit.c",
        "10_sou.c",
        "10_tec.c",
});

void reward(object player, object npc) {        
    player->add("exp", 800000);
     tell_object(player, HIY"(你獲得了 800,000 點經驗值。)\n"NOR);
    player->add("war_art", 80);
    tell_object(player, HIY"(你獲得了 80 點戰鬥藝術。)\n"NOR);
    new("/open/enhance/" + items[random(5)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
}

