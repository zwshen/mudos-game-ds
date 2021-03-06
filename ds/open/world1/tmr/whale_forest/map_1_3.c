
inherit ROOM;
void create()
{
        set("short", "林中小路");
        set("long", @LONG
林中小路走到這裡，路中間有塊頗大的灰色石頭，要是趕路趕的太急
，很有可能就被這塊石頭拌倒也說不定。
LONG
);
        set("exits",([
        "south" : __DIR__"map_2_3",
        "east" : __DIR__"map_1_4",
        ]));
        set("detail",([
        "石頭" : "你注意到石頭下似乎壓著一塊白色的布？！\n",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_search","search");
}
int have_eq=1;
void reset()
{
        have_eq=1;
        ::reset();
}

int do_search(string arg)
{
        object me=this_player(),eq;
        if(!arg || arg!="石頭") return 0;
        if(have_eq==1)
        {
                eq=new(__DIR__"npc/obj/gloves.c");
                eq->move(me);           
                message_vision("$N用雙手搬開了大石頭，結果發現一雙壓在石頭下的手套。\n",me);
                have_eq=0;
        }
        else {
                message_vision("$N用雙手舉起了大石頭，一把丟在路邊的草叢裡。\n",me);
        }
        return 1;
}
