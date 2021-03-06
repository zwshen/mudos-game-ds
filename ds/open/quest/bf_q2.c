// 2009/05/12

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "削弱夜禍大軍";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "發揮你的畢生武學，去血腥荒野削弱夜禍大軍的實力。\n";
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
    if( player->isSolved("/open/quest/bf_q1.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}


// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你的實力已經不容懷疑，但是還有更艱難的任務需要你去完成。\n",
        "$N對著$n說道：發揮你的武學跟毅力，去血腥荒野削弱夜禍大軍的實力！\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/blood_field2/npc/fetish.c": 30,
        "/open/world1/tmr/blood_field2/npc/cat.c": 30,
        "/open/world1/tmr/blood_field2/npc/fetish_wizard.c": 20,
        "/open/world1/tmr/blood_field2/npc/hulks.c": 10,
        "/open/world1/tmr/blood_field2/npc/wendigo.c": 10,
        "/open/world1/tmr/blood_field2/npc/wild_toast.c": 5,
        "/open/world1/tmr/blood_field2/npc/ents.c": 2,
    ]);
    return item;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
      return ([]);
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
        "$N對著$n說道：你又再一次證明你的能力，少帥軍全體上下都非常感謝你的付出。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "經驗值 1,500,000 點。\n";
    msg += "戰爭藝術 350 點。\n";
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
      player->add("exp", 1500000);
      tell_object(player, HIY"(你獲得了 1,500,000 點經驗值。)\n"NOR);
     player->add("war_art", 350 );
     tell_object(player, HIY"(你獲得了 350 點戰鬥藝術。)\n"NOR);
}

