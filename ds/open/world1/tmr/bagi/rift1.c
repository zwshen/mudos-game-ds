// Room: /open/world1/tmr/bagi/rift1.c

inherit ROOM;

void create()
{
        set("short", "山縫間");
        set("long", @LONG
你正擠身在一山縫間，身子兩旁堅硬的岩石刺得你胸心和後背隱隱作
痛，西首方向不時有陣涼風透過山縫吹向東邊。山壁上一條不知從何處長
出來的藤蔓，正隨風蕩漾著。
LONG
        );
        set("world", "past");
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"glade",
                "east" : __DIR__"rift",
        ]));
        set("item_desc", ([ /* sizeof() == 2 */
        "藤蔓" : "一條看來還滿堅固的藤蔓，如你夠膽量的話，不妨可以試著攀爬(climb)試試。\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="藤蔓" ) return 0;
          if(me->query("level") < 25) {
                message_vision("$N使盡了招式，仍然捉不到隨風搖擺\的藤蔓。\n",me);
                return 1;        
        }
        message_vision("$N一把捉住藤蔓，兩隻手一上一下迅速地攀爬上去。\n",me);
           me->move(__DIR__"ghat1");
        tell_room(environment(me),me->query("name")+"從崖邊探了探頭，隨即爬了上來。\n",me );
        return 1;
}


