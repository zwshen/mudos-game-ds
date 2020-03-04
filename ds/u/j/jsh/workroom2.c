#include <ansi2.h>
inherit ROOM;

void create()
{
        set("short", "世界之石");
        set("long", @LONG
none none none none none none none none none none 
none none none none none none none none none none none
none none none none none none none none none none none
none none none none none none none none none none none
(help stone) (through)
LONG
        );
        set("item_desc",([
        "魔法石":"help stone\n",
        ]));
        set("no_clean_up", 0);
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"workroom",
        ]));

        setup();
}
void init()
{
        add_action("do_help","help");
}
int do_help(string str)
{
        if(str != "stone") return 0;
        write(HIW"你要穿越(through)到哪一個時空？\n"NOR);
        add_action("do_through","through");
        return 1;
}
int do_through(string str1)
{
        if(!str1)
        {
        message_vision(
        HIW"現在有：\n\n"NOR
        HIY"1.磐龍城\n\n"NOR
        HIY"2.神龍大十字\n\n"NOR 
        HIG"Please use『through with number』\n"NOR,this_player()
        );
        return 1;
        }
        if(str1 =="1")
        {
        message_vision(
        HIW"$N將雙手放在魔法石上，大喊：磐龍城 !!\n"NOR
        HIW"白光一轉，$N竟消失不見了。\n"NOR,this_player()
        );
        
        this_player()->move(__DIR__"dragonarea/startroom.c");
        return 1;
        }
        if(str1 == "2")
        {
        message_vision(
        HIW"$N將雙手放在魔法石上，大喊：神龍大十字 !!\n"NOR
        HIW"白光一轉，$N竟消失不見了。\n"NOR,this_player()
        );
        
        this_player()->move(__DIR__"dragonarea/room_6.c");
        return 1;
        }
        else
        {
        write(HIW"要去"+str1+HIW"自己去吧....\n"NOR);
        }
        return 1;
}


