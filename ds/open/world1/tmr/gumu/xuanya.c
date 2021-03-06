// Room: /d/gumu/xuanya.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

// 仙人劍舞
void open_sword2() {
        "/adm/daemons/event/gumu.c"->trigger_event();
}
void open_sword() {
        call_out("open_sword2", 60+random(30));
}

void create()
{
        set("short", HIM"懸崖"NOR);
        set("long", @LONG
此處已是終南山絕路，前頭是一大片光滑的石壁，下面則是雲霧
瀰漫的萬丈深崖(cliff)，傳聞中有個古墓弟子因受不了古墓之清苦
寡欲，從此處一躍而下，了卻一生。近懸崖邊有棵摩天大樹(tree)，
枝葉極盛，如大傘一張遮掩住方圓之地。
LONG    );
        set("outdoors","forest");
        set("exits", ([
                "west" : __DIR__"mumen",
        ]));
        set("item_desc", ([
                "cliff" : "懸崖下一片雲霧繚繞。跳下去恐是有去無回。\n",
                "tree"   : "一棵高大的巨樹，上面留下曾經被人搖晃的痕跡。\n", 
        ]));
        set("no_clean_up", 0);


        setup();
}

void init()
{
        object room, me = this_player();

                 add_action("do_climb", "climb");
        if (random(me->query("int")) <= 15 )
        {
                if(!( room = find_object(__DIR__"tree")))
                        room = load_object(__DIR__"tree");
                if(!(present("du mang", room))) return;
                message_vision(HIR "突然聞到一股腥臭之氣，大樹上倒懸下一條碗口粗細的三角頭巨蟒，把$N卷走了。\n\n"NOR, me);
                me->move(__DIR__"tree");
                me->start_busy(3);
        }
}


int do_climb(string arg)
{ 
        object me = this_player(); 

        if (arg == "tree")
        {
                message_vision(YEL"$N騰身往大樹上爬去。\n"NOR, me);
                if (me->query_skill("dodge", 1) < 30)
                {
                        message_vision(HIR"結果$N從樹上一個筋斗掉下來。\n"NOR, me);
                        me->receive_wound("hp", random(5) + 5);
                        return 1;
                }
                message_vision(HIY"$N很快消失在濃蔭密葉中。\n"NOR, me);
                me->move(__DIR__"tree");
                return 1;
        }
        return notify_fail("你想往哪爬？\n");
}

