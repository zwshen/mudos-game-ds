// tmr 2007/02/28

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "清除黃沙賊";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "孟村的西邊為滾滾黃沙，常有無惡不作的黃沙賊出沒，劫取過往的商人或旅客，\n";
    msg += "，造成大家的不便。邊界守衛希望你能幫忙清除黃沙賊，好換取旅人的平安。\n";

    return msg;
}

// 任務等級
int getLevel() {
      return 5;
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
         if( player->query("level") < 5) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/wilfred/sand/npc/npc48.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/wilfred/sand/npc/npc48.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N高興的跳了起來。\n"NOR,
        "$N對著$n說道：為了孟村的平安，我們一定要掃蕩黃沙賊！！\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/wilfred/sand/npc/npc20_0.c": 15,  // 嘍囉
        "/open/world1/wilfred/sand/npc/npc20_1.c": 8,   // 地痞
        "/open/world1/wilfred/sand/npc/npc20_2.c": 4,   // 匪盜
        "/open/world1/wilfred/sand/npc/npc20_3.c": 2,   // 強盜
        "/open/world1/wilfred/sand/npc/npc20_4.c": 1,   // 小頭目
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
    msg  = "一萬枚銅板。\n";
    msg += "聲望 3 點。\n";
    msg += "戰鬥藝術 1 點。\n";
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
        player->add("bank/past", 10000);
    tell_object(player, HIY"(你獲得了一萬枚銅板。)\n"NOR);
        player->add("popularity", 3);
    tell_object(player, HIY"(你獲得了 3 點聲望。)\n"NOR);
        player->add("war_art", 1);
    tell_object(player, HIY"(你獲得了 1 點戰鬥藝術。)\n"NOR);
}
