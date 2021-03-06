// Room: /u/t/tmr/area/hotel.c

#include <ansi2.h>
inherit ROOM;
string look_list(object me);
void create()
{
        set("short", "朝天樓");
        set("long", @LONG
一間因「朝天湖」而興起的客棧，朝天樓東北方約兩箭之地即到湖邊
，故此間客棧大受過往遊客歡迎，常常於此住宿、用膳。眼前有個鑲花樓
梯，一樓大都是江湖豪士或是尋常百姓在此喝酒吃肉，充耳的吵雜，店小
二忙著招呼客人，入店門的客人更是絡驛不絕。左邊隔著竹簾傳來鍋鏟相
碰、盤碗互撞的聲音，看來是這裡的廚房了。牆上貼了張富翁排行榜 ---
(rich_list)。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inn_2f",
  "east" : __DIR__"street4",
  "down" : "/open/world1/wilfred/newbie/eq_bank",
  "newbie" : __DIR__"school/school1", 
  "bug" : "/open/world2/anfernee/start/bug",    
 //"west" : "/u/a/alickyuen/open/moon/en1", 
]));
        set("objects", ([ /* sizeof() == 1 */
//  "/open/world1/mirror.c": 1,
  __DIR__"npc/waiter" : 1,
  __DIR__"npc/basic_master" : 1,  

//  __DIR__"npc/eq-man":1, 
// "/open/world1/promise/xmas-lady" : 1,
]));
        set("item_desc",([
     "rich_list": (: look_list :),
        ]));
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);

        setup();
     call_other("/obj/board/tmr_hotel_b", "???");
}

string look_list(object me)
{
        return RECORD_D->query_past_money_rec();
}
int valid_leave(object me, string dir)
{
        if( dir=="newbie" || dir=="bug" && !userp(me))
        return notify_fail("那裡只有玩家才能進去。\n");    
        if( dir!="newbie" )return ::valid_leave(me, dir);
        else if( me->query("not_newbie") )
                return notify_fail("你已不是新手了！\n");

        return ::valid_leave(me, dir);
}

void update_player() {

        object me = this_player();
        // delete unused skills
        me->delete_skill("sevenstar-sword");
        me->delete_skill("lan_pu");

        // 將money-dart改成nine-waterfall
        // 更新 quest
        me->delSolved("/open/quest/mouse_q1.c");
        me->delSolved("/open/quest/mouse_q2.c");
        me->delSolved("/open/quest/mouse_q3.c");
        me->delToDo("/open/quest/mouse_q1.c");
        me->delToDo("/open/quest/mouse_q2.c");
        me->delToDo("/open/quest/mouse_q3.c");
        if( me->query_skill("money-dart") > 0) {
                me->set_skill("nine-waterfall", me->query_skill("money-dart") );
                me->delete_skill("money-dart");
        }

        // 將sorsin_force改成 indicate-knack
        if( me->query_skill("sorsin_force") > 0) {
                me->set_skill("indicate-knack", me->query_skill("sorsin_force") );
                me->delete_skill("sorsin_force");
        }

        // 更新天賦屬性
        if( me->query("class1") == "天梟派") {
                me->set("guild_gifts", ({2,7,8,3 }) );
        }
        if( me->query("class1") == "寒澈派") {
                me->set("guild_gifts", ({0,5,9,6}) );
        }
        if( me->query("class1") == "少帥軍") {
                me->set("guild_gifts", ({8,8,0,4}) );
        }
        if( me->query("class1") == "凌雲寺") {
                   me->set("guild_gifts", ({8,4,8,0}) );
        }
        if( me->query("class1") == "神武教") {
                me->set("guild_gifts", ({2,4,9,5}) );
        }
        if( me->query("class1") == "情城池") {
                me->set("guild_gifts", ({4,6,3,7}) );
        }
          if( me->query("class1") == "邪極宗") {
                  me->set("guild_gifts", ({7,4,7,2}) );
          }
         if( me->query("class1") == "疾風門") {
                 me->set("guild_gifts", ({5,7,0,8}) );
          }

         if( me->query("class1") == "thief") {
                 me->set("guild_gifts", ({3,7,0,10}) );
          }



}

void init()
{
         if( !wizardp(this_player()) && this_player()->query("class1") != "神武教" && this_player()->query_spell("god-fire") ) 
         {
                 write(HIR"\n\n\t你頭腦一陣混沌，遺忘了 祈神式-神真火(god-fire) 法術。\n\n"NOR);
                 log_file("del_spell", "delete " + this_player()->query("name") + "(" + getuid(this_player()) + ") god-fire spell.."+ this_player()->query_spell("god-fire") +"\n");
                 this_player()->delete_spell("god-fire");
         }
    update_player(); // add by tmr 2007/01/04
}

