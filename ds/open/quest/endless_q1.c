#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "常德不離";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "「知其雄，守其雌，為天下谿。為天下谿，常德不離，復歸於嬰兒」。\n";
    msg += "你可以在與各門派的領袖人物的對決，來進一步鎖研《常德不離》的真諦。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 50;
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
        // 必須先得到技能
    if( player->query_skill("constant-virtue") == 0 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：知其雄，守其雌，為天下谿。為天下谿，常德不離，復歸於嬰兒。\n",
        "$N對著$n說道：你可以在與各門派的領袖人物的對決，來進一步鎖研《常德不離》的真諦。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/bagi/npc/advmaster.c": 1,             //吳鐘
        "/open/world1/cominging/area/npc/yuanlieh.c": 1,        //軒轅烈
        "/open/world1/tmr/advthief/thief_adv_master.c": 1,      //賊帥
        "/open/world1/kkeenn/love/npc/master_2.c": 1,           //香香
        "/open/world1/tmr/advbonze/npc/bonze_adv_master.c": 1,   //妙見
        "/open/world1/acme/area/npc/advmaster.c": 1,            //蕭日山
        "/open/world1/tmr/frost/npc/yun-zhong-zi.c": 1,         //雲中子
        "/open/world1/tmr/dragoncity/npc/kou-zhong.c" : 1,      // 寇仲
    ]);
    return kill;
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

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：不錯不錯，你的確証明出你的實力了！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg = "";
    msg += "獲得「常德不離」的加持(增加5%暴擊率，持續時間：常德不離等級*30分鐘)。\n";
    msg += "戰鬥藝術 50 點。\n";
    return msg;
}

void reward(object player, object npc) {
        player->add("war_art", 50 );
        tell_object(player, HIY"(你獲得了 50 點戰鬥藝術。)\n"NOR);

        if(!player->query_temp("constant-virtue")) {
                player->set_temp("constant-virtue", 5);
                player->add_temp("apply/hit_ratio", 5);
        }
        player->apply_condition("constant-virtue",
                4 * 30 * player->query_skill("constant-virtue")
        );
        tell_object(player, HIY"無極導師望入你眼底深處，你感受到一股力量源源而生。\n"NOR);
}

