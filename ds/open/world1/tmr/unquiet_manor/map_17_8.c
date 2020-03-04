#include <ansi.h>
inherit ROOM;


string file_path = "/open/world1/tmr/unquiet_manor/";         // 求援的npc位置

/* mob的檔案位置 */
string *mob_file = ({ "skeleton.c",
                      "evil.c",
                      "evil2.c",
                      "demon.c",
                      "grove-ghost.c",
                      "solider.c",
                      "general.c",
                   });

/* mob所要產生的數量 */
int *mob_amount = ({ 100, 100, 100, 100, 40, 40, 30});

/* mob產生後要移到的位置 */
string *mob_born = ({
"map_4_14.c", "map_4_15.c", "map_4_2.c", "map_4_6.c", 
"map_4_8.c", "map_5_1.c", "map_5_10.c", "map_5_15.c", 
"map_5_8.c", "map_6_1.c", "map_6_12.c", "map_6_15.c", 
"map_6_4.c", "map_6_9.c", "map_7_10.c", "map_7_14.c", 
"map_7_4.c", "map_7_6.c", "map_7_8.c", "map_8_11.c", 
"map_10_11.c", "map_13_1.c", "map_10_15.c", "map_10_9.c", 
"map_13_10.c", "map_14_14.c", "map_11_6.c", "map_11_8.c", 
"map_13_8.c", "map_15_13.c", "map_15_3.c", "map_7_1.c", 
"map_13_8.c", "map_14_14.c", "map_4_8.c", "map_5_2.c", 
"map_8_7.c", "map_8_5.c", "map_9_15.c", "map_9_9.c", 
"map_8_13.c", "map_8_4.c", "map_9_11", "map_9_5.c",     
                   });

void create()
{
        set("short", "無寧莊園-正門");
        set("long", @LONG

LONG
);
        set("exits",([
        "north" : __DIR__"map_16_8",
         "south" : "/open/world1/manto/pudu_mountain/way05n2",
        ]));
        set("outdoors","land");
        set("objects", ([
                __DIR__"npc/warnpc" :1,
                ]) );
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
    object me=this_player();
    if(me->id("_UNQUIET_MANOR_NPC_") ) {
        me->force_me("say 對莊園外的世界沒有什麼興趣。");
        me->force_me("go north");
    }
}


void do_start(int i)
{
    int amount, ct;
    string file;
    object mob;
    string room;

    ct = 0;
    file = file_path + "npc/" + mob_file[i];
    amount = sizeof(children(file));
    if( amount >= mob_amount[i] ) return;
    amount = mob_amount[i] - amount;
    // 產生至一定數量的 Mob
    while( amount && ct++ < 50) {
        mob = new(file);
        if(!mob) return;
        room = file_path + mob_born[random(sizeof(mob_born))];
        if(!room) continue;
        amount--;
        mob->move(room);
   }
}

void start0() { do_start(0); }
void start1() { do_start(1); }
void start2() { do_start(2); }
void start3() { do_start(3); }
void start4() { do_start(4); }
void start5() { do_start(5); }
void start6() { do_start(6); }

void open_war()
{
        message("world:world1:vision",
HIR "\n\t        咚！咚！咚！只聽見奧特蘭克的戰鼓聲大作！！\n"
+HIM "\n\t"HIC"無寧莊園"HIM"的眾妖邪都甦醒過來了，已全面進入備戰狀態！！\n\n" NOR
,users() );

        call_out( "start0", 1);
        call_out( "start0", 3);
        call_out( "start1", 5);
        call_out( "start1", 7);
        call_out( "start2", 9);
        call_out( "start2", 11);
        call_out( "start3", 13);
        call_out( "start3", 15);
        call_out( "start4", 17);
        call_out( "start5", 19);
        call_out( "start6", 21);
}

void start_war() {
    call_out("open_war", 7  );
}


