#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小廣場");
        set("long", @LONG
一座位於城中央的小廣場，廣場中有個大水缸提供給人喝水用，北邊
是座木橋，往東則是通往此地名勝「朝天湖」，不少的旅客從東邊走來，
由他們臉上驚喜、讚喜的表情，你不禁仰慕「朝天湖」的勝景。往西邊就
孟村的東村口。
LONG
        );  
              set("hide_exits", ([ /* sizeof() == 6 */
                  "fuck" : __DIR__"well32",
                        ]));

        set("objects", ([ /* sizeof() == 1 */
           __DIR__"gold-man":10 ,
         ]));
        set("outdoors","land");
        set("light",1);
        set("no_clean_up", 0);
        setup();

}
void init()
{
        add_action("do_take","take"); 
        add_action("do_take2","take2");
}
int do_take(string arg)
{
        object me, p;
        me = this_player();
        if( arg != "金絲漁網 "&& arg !="rob" ) return 0;
                {
                p=new(__DIR__"gcflower");
                p->move(this_player()); 
                    return 1; 
} 
}
int do_take2(string arg)
{
        object me, p;
        me = this_player();
        if( arg != "金絲漁網 "&& arg !="hbb" ) return 0;
                {
                p=new("/open/world1/acme/area2/npc/obj/you_ming_book.c");
                p->move(this_player()); 
                    return 1; 
} 
}

