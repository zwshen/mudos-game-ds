// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "阿曼的狼皮收集";
}

// 任務描述
string getDetail() {
    string msg;
	msg = "替阿曼收集二十張的狼皮，\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 20;
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
   if( player->query("level") < 20 ) return 0;
   if( player->isSolved("/open/quest/hasake_q1.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/aman.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/aman.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：這位哈薩克勇士，你能幫我收集一些狼皮嗎。\n",
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
        "/open/world1/tmr/hasake/npc/obj/langpi.c": 20, // 狼皮
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
        "$N對著$n說道：感覺這位哈薩克勇士的幫忙，願阿拉祝福你。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "隨機60% 力量、體質、智慧、敏捷卷軸一張。\n";
    msg += "聲望 5 點。\n";
    return msg;
}

string *items = ({
         "60_str.c",
         "60_con.c",
         "60_dex.c",
         "60_int.c",
});

void reward(object player, object npc) {
    player->add("popularity", 5);
    tell_object(player, HIY"(你獲得了 5 點聲望。)\n"NOR);
    new("/open/enhance/" + items[random(4)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
}

