// Room: /tmr/garea/tree_up.c

inherit ROOM;

void do_clear() {
        if(this_object()) return;
        delete_temp("quest");
}

void create()
{
        set("short", "樹枝上");
        set("long", @LONG
你正站著一根頗為粗大的樹枝上，上方繁盛的綠葉蓋頂，約略有些光
線透下來，你隱隱約約瞧見在樹枝末端有個大鳥巢，少說也有一般鳥巢的
數十倍大。
LONG
        );
        set("no_clean_up", 0);
        set("item_desc",([
        "鳥巢":"巢裡頭似乎有幾顆大若人頭的不知名鳥蛋。\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "down" : __DIR__"forest5",
        ]));
        set("objects",([
        __DIR__"npc/chisel":2,
        ]) );
        set("outdoors","forest");
        setup();
}
void init()
{
          add_action("do_search","search");
}

int do_search(string arg)
{
        object egg,me;
        me=this_player();
        if(!arg || arg!="鳥巢") return 0;
        if ( !query_temp("quest") ) 
        {
                message_vision("$N從鳥巢中搜出了一顆白色的大圓球。\n",me);
                set_temp("quest",1);
                egg=new(__DIR__"npc/obj/egg");
                egg->move(me);
                 call_out("do_clear", 600);     // 10分鐘

        } else
                message_vision("$N在鳥巢中搜了搜，似乎沒有發現到什麼...\n",me);
        return 1;
}

