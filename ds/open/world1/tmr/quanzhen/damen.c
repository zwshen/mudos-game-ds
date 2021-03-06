// damen.c 大門
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int valid_leave();
string look_gate();
int do_knock(string arg);

void create()
{
        set("short", "全真教大門");
        set("long", @LONG
你已走到了終南山半山腰，前面就是全真教的總部重陽宮了。殿
宇依山而築，高低錯落有致。周圍古木森森，翠竹成林，景色清幽。
正前方黃牆碧瓦，飛檐翹檁，正中一道二丈來寬，三丈來高的朱紅杉
木包銅大門(gate)，氣勢不凡。門上掛著一塊匾(bian)，門前的石柱
上掛著一副對聯(duilian)。
LONG
        );
        set("exits", ([
                "westdown" : __DIR__"jiaobei",
        ]));
        set("outdoors", "chongyang");
        set("item_desc", ([
            "gate":
"一道三丈來高的"HIR"朱紅杉木"HIY"包銅"NOR"大門。\n",
            "bian": HIG"
＊＊＊＊＊＊＊＊＊＊＊＊＊
＊＊　　　　　　　　　＊＊
＊＊　全　真　古　教  ＊＊
＊＊　　　　　　　　　＊＊
＊＊＊＊＊＊＊＊＊＊＊＊＊
\n"NOR,
            "duilian": BLINK+HIW"
一生二二生三三生萬物\n
地法天天法道道法自然
\n"NOR
        ]) );
        set("objects",([
                CLASS_D("quanzhen")+"/zhike" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
}

void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"datang1")) )
        room = load_object(__DIR__"datang1");
    if(objectp(room))
    {
        delete("exits/east");
        message("vision", "乒地一聲，裡面有人把大門關上了。\n",
            this_object());
        room->delete("exits/south");
        if (objectp(present("qingguan", room)))
            message("vision", "知客道長上前把大門關了起來。\n", room);
        else
            message("vision", "道童上前把大門關了起來。\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("大門已經是開著了。\n");

    if (!arg || (arg != "gate" && arg != "east"))
        return notify_fail("你要敲什麼？\n");

    if(!( room = find_object(__DIR__"datang1")) )
        room = load_object(__DIR__"datang1");
    if(objectp(room))
    {
        set("exits/east", __DIR__"datang1");
        message_vision("$N輕輕地敲了敲門，只聽吱地一聲，"
            "一位道童應聲打開大門，\n"
            "他用警惕的目光上上下下打量著$N。\n",
            this_player());
        room->set("exits/west", __FILE__);
        message("vision", "外面傳來一陣敲門聲，道童應聲上前把大門開。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if ( dir != "east" )
    {
        return ::valid_leave(me, dir);
    }
    if (!query("exits/east"))
        return 0;

    if (!::valid_leave(me, dir))
        return 0;

    if ( (me->query("family/family_name") == "全真教"))
    {
        if (me->query("class") != "quanzhen")
        {
            return notify_fail("道童說道：對不起，俗家弟子不得入宮修行。\n");
        }
        write("道童側身讓開，說道：師兄辛苦了，請進。\n");
        return 1;
    }
    else if( present("chongyang ling", me) )
    {
        write("道童打個稽首，側身讓開，說道：原來是貴客駕到，請進請進！\n");
        return 1;
    }
    if (me->query("shen") >= 0)
         return notify_fail("道童說道：這位施主請回罷，重陽宮不接待俗人。\n");
    return notify_fail("道童說道：你等邪魔外道，重陽宮向不接納，請了！\n");

}