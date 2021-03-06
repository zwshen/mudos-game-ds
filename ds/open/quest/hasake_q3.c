// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "哈薩克勇士的証明 II";
}

// 任務描述
string getDetail() {
    string msg;
	msg = "在針葉林中還有領頭的灰狼王，最是狡猾，殺害過非常多的生命，\n";
	msg += "希望你能再替哈薩克除掉這些禍害，恢復大草原的寧靜生活。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 30;
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
   if( player->query("level") < 30 ) return 0;
   if( player->isSolved("/open/quest/hasake_q1.c") == -1) return 0;
   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：在針葉林中還有領頭的灰狼王，最是狡猾，也殺害過不少生命。\n",
        "$N對著$n說道：我希望你能再替哈薩克除掉這些禍害。\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
          "/open/world1/tmr/hasake/npc/wolf-king.c": 7, 
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
        "$N對著$n說道：你又再一次証明你是位哈薩克勇士。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "五萬枚銅板。\n";
    msg += "聲望 10 點。\n";
    msg += "戰鬥藝術 5 點。\n";
    return msg;
}


void reward(object player, object npc) {
        player->add("bank/past", 50000);
    tell_object(player, HIY"(你獲得了五萬枚銅板。)\n"NOR);
        player->add("popularity", 10);
    tell_object(player, HIY"(你獲得了 10 點聲望。)\n"NOR);
        player->add("war_art", 5);
    tell_object(player, HIY"(你獲得了 5 點戰鬥藝術。)\n"NOR);
}

