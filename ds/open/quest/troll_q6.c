// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// 任務名稱
string getName() {
    return "暗矛部落的裝備材料";
}

// 任務描述
string getDetail() {
        return 
"苗大嬸為了感謝你對苗家村的幫忙，願意幫你製造暗矛部落的裝備，
其中森金之戒中藏有褲裙類的設計圖，你必須從冰霜巨魔處取得，另外
你還必須提供冰霜皮衣及幾個冰霜軟毛，做為製造的褲裙的材料。
"; 
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
   if( player->query("level") < 40 ) return 0;
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q3.c") == -1) return 0;

    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo-aunt.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo-aunt.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：真是非常感謝你對苗家村的幫忙。\n",
        "$N對著$n說道：要是你能取來相關的原料，我可以幫你縫製暗矛部落的裝備。\n",
        "$N對著$n說道：其中森金之戒中藏有褲裙類的設計圖，你必須從冰霜巨魔處取得。\n",
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
        "/open/world1/tmr/north_forest/npc/obj/troll-ring2.c": 1,
        "/open/world1/tmr/north_forest/npc/obj/frost-cloth2.c": 1,
        "/open/world1/tmr/north_forest/npc/obj/frost-fur.c": 3,
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
        "$N對著$n說道：你的原料都取來了，我馬上就製給你。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return 
"
男性角色可獲得暗矛巨魔毛褲；女性則獲得暗矛巨魔毛裙。
經驗值 50,000 點。
";
}



void reward(object player, object npc) {
    player->add("exp", 50000);
    tell_object(player, HIY"(你獲得了 50,000 點經驗值。)\n"NOR);

        if( player->query("gender")=="男性" ) {
                new("/open/world1/tmr/north_forest/npc/obj/troll-pants")->move(player);
                tell_object(player, HIY"(你獲得一件暗矛巨魔毛褲。)\n"NOR);
        } else {
                new("/open/world1/tmr/north_forest/npc/obj/troll-skirt")->move(player);
                tell_object(player, HIY"(你獲得一件暗矛巨魔毛裙。)\n"NOR);
        }
}


