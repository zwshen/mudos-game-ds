// tmr 2007/02/28

#include <ansi.h>

void create() { seteuid(getuid()); }



// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "硬牛皮紙匣";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "牛博士不只精通武藝，還深悉裁縫之道，能幫你將二個牛皮紙匣縫製成一個。\n";
    msg += "牛皮紙匣可從瘋狂牯牛身上取得。\n";
    msg += "生牛皮可從大黃牯牛及野戰牯牛身上取得。\n";
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
        if( player->query("level") < 5 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/wilfred/meadow/npc/npc2.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/wilfred/meadow/npc/npc2.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：只要你拿來二個牛皮紙匣跟一張生牛皮，我就能幫你做裁縫。\n",
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
        "/open/world1/wilfred/meadow/npc/obj/paper-box.c": 2, // 牛皮紙匣
        "/open/world1/wilfred/meadow/npc/obj/cow-skin.c": 1, // 牛皮
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
        "$N對著$n說道：等我一下，我馬上就做給你。\n",
        "$N對著$n說道：喏∼∼這就是俗又好用的硬牛皮紙匣。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "硬牛皮紙匣。\n";
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
        new("/open/world1/wilfred/meadow/npc/obj/paper-box2")->move(player);
    tell_object(player, HIY"(你獲得了一個硬牛皮紙匣。)\n"NOR);
}
