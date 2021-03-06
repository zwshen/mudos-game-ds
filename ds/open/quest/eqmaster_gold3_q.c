// tmr 2007/07/11

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "打鐵老師傅的秘銀礦委託";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "打鐵老師傅需要高級的秘銀礦，你可以到霧洞深處的無間小道找找看。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 45;
}


int preCondition(object player) {
    if( player->query("level") < 35 ) return 0;
    if( player->isSolved("/open/quest/eqmaster_gold_q.c") == -1) return 0;
    if( player->isSolved("/open/quest/eqmaster_gold2_q.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：在步靈城旁的森林中，有個被蛇怪守護的霧洞。\n",
        "$N對著$n說道：在霧洞的深處有無間小道，可通往時無間、空無間及受業無間等洞穴。\n",
        "$N對著$n說道：聽說裡頭藏有非常稀有的「祕銀礦」，希望你能幫我取五個回來。\n",
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
          "/open/world1/tmr/wujian/npc/obj/mercury-mine.c": 5,
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
        "$N對著$n說道：喔喔！！你取來秘銀礦了，真是太辛苦你了！。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return "
經驗值 500,000 點
戰鬥藝術 20 點
10% 力量、體質、智慧、敏捷卷軸各一張。
";
}

string *items = ({
         "10_atk.c",
         "60_atk.c",
         "100_atk.c",
});

void reward(object player, object npc) {
    player->add("exp", 500000);
    tell_object(player, HIY"(你獲得了 500,000 點經驗值。)\n"NOR);
    player->add("war_art", 20);
    tell_object(player, HIY"(你獲得了 20 點戰鬥藝術。)\n"NOR);

    new("/open/enhance/10_str")->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/10_dex")->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/10_con")->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/10_int")->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);

}

