// Room: /open/world1/tmr/bagi/hole.c

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
你正在一處約可容納二、三人的小山洞，你一眼發現山洞盡處躺著一
具骸骨，看其身上腐爛不堪的衣服，可知此人已死亡多年了。
LONG
        );
        set("light", 1);
        set("world", "past");
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"glade",
]));
        set("item_desc", ([ /* sizeof() == 1 */
             "骸骨" : "一具早已乾枯\的骸骨，看其骨骼雄健，似乎是個武林前輩？！\n",
        ]));
        set("no_clean_up", 0);

        setup();
}

int i=0;

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me,book;
        me=this_player();
        if(!arg || arg!="骸骨") return 0;
	message_vision("$N仔細地搜了搜骸骨...\n",me);
        if(i==0) {
        i=1;
        book=new(__DIR__"npc/obj/bagibook");
        book->move(me);
           tell_object(me,"你似乎搜到了一本書？\n");
         return 1;
        }
        else return notify_fail("你並沒有發現到什麼東西。\n");
        return 1;

}
