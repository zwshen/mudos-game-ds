// Room: /open/world1/tmr/freezetaoism/downroad3.c

inherit ROOM;

void create()
{
        set("short", "地下石室");
        set("long", @LONG
這裡是一處頗大的石室，已經溼悶的空氣中混雜著一股血腥味，四週
除了石壁之外，就再也沒有其他的東西了，在這兒越待得久，心中那陣煩
悶的感覺越是增強，真是讓人一點都不想待在這兒了。
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"downroad2",
]));
        set("no_clean_up", 0);

        setup();
        set("item_desc",([
                "石壁":"你發現南首的石壁和另三面牆特別不一樣，似乎是種機關牆。\n",
        ]));
        setup();
}
void init()
{
        add_action("do_push","push");
}
int do_push(string arg)
{
        object me=this_player();
        if (arg != "石壁") return 0;
        if (me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，無法觸動機關。\n");
        if(!me->move(__DIR__"downroad4") )
                return notify_fail("你無法成功\地觸動機關。\n");
        tell_room(environment(this_object()),
                me->query("name")+"使勁地推了一面可活動的石壁，身形隨即隱沒在石壁後方。\n",me);
                
        tell_room(environment(this_player()),
                me->query("name")+"忽然出現在你眼前。\n",me );
        return 1;
}

