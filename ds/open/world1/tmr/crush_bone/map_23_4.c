// File: /d/crush_bone/map_23_4.c
// Updated by tmr (Sat Jun 19 19:41:34 2004)

#include <ansi.h>

inherit ROOM;

string file_path = "/open/world1/tmr/crush_bone/";         // 求援的npc位置

/* mob的檔案位置 */
string *mob_file = ({ "orc_follower.c",
                      "orc.c",
                      "orc_hundred_leader.c",
                      "orc_thousand_leader.c",
                      "orc_commander.c",
                      "orc_herald.c",
                      "orc_envoy.c",
                      "orc_emperor.c"
                   });

/* mob所要產生的數量 */
int *mob_amount = ({ 40, 40, 40, 40, 40, 40, 40, 1 });

/* mob產生後要移到的位置 */
string *mob_born1 = ({ "map_22_1.c",
                       "map_11_1.c",
                       "map_1_1.c",
                       "map_1_12.c",
                       "map_1_22.c",
                       "map_11_22.c",
                       "map_22_22.c",
                       "map_22_12.c"
                   });

string *mob_born2 = ({ "map_7_9.c",
                       "map_9_16.c",
                       "map_11_9.c",
                       "map_13_16.c",
                       "map_16_14.c",
                       "map_16_10.c",
                       "map_13_7.c",
                       "map_7_7.c"
                   });


void create()
{
          set("short", "小徑");
          set("long", @LONG

LONG
          );
          set("outdoors", "land");
          set("map_long", 1);
          set("exits", ([ /* 3 element(s) */
        "north" : __DIR__"map_22_4",
      "southwest" : "/open/world1/tmr/dragoncity/caodi8",
]));

        setup();
}
void init()
{
    object me=this_player();
    if(me->id("_CRUSH_BONE_ORC_") ) {
        me->force_me("say 目前還不能外出，要為碎骨寨計劃作好準備，皇帝萬歲萬歲萬萬歲！！");
        me->force_me("go north");
    }
}

void do_start()
{
      int i, amount;
    string file;
    object mob;
    string room;

    for(i=0;i<3;i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // 產生至一定數量的 Mob
            while( amount-- ) {
                mob = new(file);
                room = file_path + mob_born1[random(sizeof(mob_born1))];
                mob->move(room);
            }
        }        
    }
}

void do_start2()
{
      int i, amount;
    string file;
    object mob;
    string room;

    for(i=3;i<6;i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // 產生至一定數量的 Mob
            while( amount-- ) {
                mob = new(file);
                // 軍團長等級以上的MOB
                room = file_path + mob_born2[random(sizeof(mob_born2))];
                mob->move(room);
            }
        }        
    }
}


void do_start3()
{
      int i, amount;
    string file;
    object mob;
    string room;

    for(i=6;i<8;i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // 產生至一定數量的 Mob
            while( amount-- ) {
                mob = new(file);
                // 軍團長等級以上的MOB
                room = file_path + mob_born2[random(sizeof(mob_born2))];
                mob->move(room);
            }
        }        
    }
}



void open_war()
{
        message("world:world1:vision",
HIR "\n\t        咚！咚！咚！只聽見奧特蘭克的戰鼓聲大作！！\n"
+HIG "\n\t碎骨寨半獸人大軍進駐寨內，已全面進入備戰狀態！！\n\n" NOR
,users() );

        call_out( "do_start", 2);
        call_out( "do_start2", 8);
        call_out( "do_start3", 16);
}

void start_war() {
  call_out("open_war", 12  );
}


