// Room: /u/s/sonicct/area/shop1.c

inherit ROOM;

void create()
{
        set("short", "酒吧");
        set("long", @LONG
這是一間Naboo有名的酒吧，一到夜晚就有很多人來喝酒的。
你不難發現這裡有很多名人出入，這裡是很多記者留連這裡。而
你可以從酒保口中得到一些情報。
LONG
        );
        set("no_clean_up", 0);
             set("light",1);
set("item_desc",(["酒櫃":"這是一個放酒的酒櫃。\n",]));  

        setup();
        replace_program(ROOM);
}
void init()
{
        add_action("typepush","push");
}
int typepush(string arg)
{
        object me;
        me=this_player();
        if (arg != "酒櫃") return 0;
        
        message_vision("只見你手一推，便連人帶櫃轉到另一個房間裡。\n\n" ,me);
        me->move("/u/a/alickyuen/area/bar2");
        tell_room(environment(me),me->query("name")+"突然出現在你眼前。\n",me);
        return 1;
}


