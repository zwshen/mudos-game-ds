inherit ROOM;
void create()
{
        set("short", "古井");
        set("long", @LONG
你四周昏暗不明，古井裡雖然乾枯已久，但仍十分潮溼，溼氣逼人，令你
十分難受，你四下張望時，發現這裡有株植物，一閃一閃的，煞是好看。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"backyard.c",
]));
     set("item_desc", ([
         "植物" : "這株植物上頭有七個紫金色的小點，是俗稱「七星紫金葉」\n"
                  "的植物，你可以摘(pick)下它。\n",
     ]) );      
        set("no_clean_up", 0);
        setup();
}
void init()
{
   add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object herb;
        object me;
        me=this_player();
        if(query_temp("herb2")) return notify_fail("什麼？\n");
        if(arg != "七星紫金葉")
        {
            notify_fail("你要摘下什麼？\n");
            return 0;
        }
        else {
        message_vision("$N小心翼翼的將七星紫金葉摘了下來。\n",me);
        herb=new(__DIR__"obj/herb2.c");
        herb->move(me);
      set("item_desc", ([
              "植物" : "這只是一堆雜草，並沒有特別之處。\n",
     ]) );      
        set("long", @LONG
你四周昏暗不明，古井裡雖然乾枯已久，但仍十分潮溼，溼氣逼人，令你
十分難受，你四下張望，發覺這裡空蕩蕩的，什麼東西也沒有。
LONG
        );
        set_temp("herb2",1);
        call_out("delay",600,this_object());
        return 1;
             }
}
void delay(object room)
{
     delete_temp("herb2");
     set("item_desc", ([
         "植物" : "這株植上頭有七個紫金色的小點，是俗稱「七星紫金葉」\n"
                  "的植物，你可以摘(pick)下它。\n",
     ]) );      
}
