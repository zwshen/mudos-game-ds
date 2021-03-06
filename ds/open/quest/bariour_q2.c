// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "繪理香的委託";
}

// 任務描述
string getDetail() {
return "
在朝天樓經營的彩卷的繪理香(Sawqjiri erika)，擁有
一顆非常漂亮的白色石頭，叫做「天使之卵」。然而這
顆石頭卻被人偷走，經過這陣子的調查，最後發現這顆
石頭失落在羊男的迷宮中，繪理香希望你能幫她找回天
使之卵。
";
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
   if( player->isSolved("/open/quest/bariour_q1.c") == -1) return 0;

   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/lottery/erika.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/lottery/erika.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：我有顆非常漂亮的寶物，叫做「天使之卵」，但是它卻被偷走了。\n",
        "$N對著$n說道：經過調查之後，只知道它目前在蒼綠半羊人身上。\n",
        "$N對著$n說道：希望你能幫我取回天使之卵。\n",
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
        "/open/lottery/angle_egg.c": 1, 
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
        "$N對著$n說道：你真好，幫我找回來了，真是太謝謝你的幫忙了！\n",
        "$N對著$n說道：這五十張獎券送給你，祝你中大獎。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg = "50 張獎券。\n";
    msg += "1 點戰爭藝術。\n";
    return msg;
}

void reward(object player, object npc) {
        object ticket;
        int i;
        player->add("war_art", 1);
        tell_object(player, HIY"(你獲得了 1 點戰爭藝術。)\n"NOR);
        // 五十張彩卷
        for(i=0;i<50;i++) {
                ticket = LOTTERY_D->createTicket();
                ticket->move(player);
        }
        tell_object(player, HIY"(你獲得了 50 張彩券。)\n"NOR);
}

