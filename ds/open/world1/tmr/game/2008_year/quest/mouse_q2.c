#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "賽門的「鼠來運轉」集字";
}

// 任務描述
string getDetail() {
return "
給賽門(simon)搜集「鼠來運轉」四個字樣，你可以
隨機獲得搶福袋套裝一件。
";
}

// 任務等級
int getLevel() {
     return 1;
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
   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/game/2008_year/npc/simon.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/game/2008_year/npc/simon.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你能幫我搜集「鼠」、「來」、「運」、「轉」的字樣嗎？\n",
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
                "/open/world1/tmr/game/2008_year/obj/word1.c" : 1,
                "/open/world1/tmr/game/2008_year/obj/word2.c" : 1,
                "/open/world1/tmr/game/2008_year/obj/word4.c" : 1,
                "/open/world1/tmr/game/2008_year/obj/word5.c" : 1,
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
        "$N對著$n說道：你做的真是太棒了！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
     return "可換得搶福袋套裝中的一件裝備，增加你打到福袋的運氣。";
}

string *items = ({
        "f_ankle.c",
        "f_armor.c",
        "f_boots.c",
        "f_cloak.c",
        "f_cloth.c",
        "f_gloves.c",
        "f_hat.c",
        "f_leg.c",
        "f_neck.c",
        "f_pants.c",
        "f_ring.c",
        "f_waist.c",
        "f_wrists.c",
          "f_mask.c",
          "f_shield.c",
});

void reward(object player, object npc) {
        string file;
        object eq;
        file = items[random(sizeof(items))];
        eq = new("/open/world1/tmr/game/2008_year/eq/" + file );
        eq->move(player);

        message("world:world1:vision",
         sprintf(HIG"【鼠來運轉】"HIW"恭喜%s(%s)獲得一件%s。\n"NOR, player->query("name"), player->query("id"), eq->name())
        ,users());
}


