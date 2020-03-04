#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
set("short",HIW"東北"NOR"澤林－"YEL"泥沼區"NOR"深處");
set("long", @LONG
你來到泥沼區的深處, 四周一片死寂, 在你的正前方有一塊
大石, 在大石的四周長滿了雜草, 無法繼續前進了....
LONG
        );
        set("exits",(["north":__DIR__"en69",
                      "northwest":__DIR__"en68",
               ]));
        
        set("item_desc",([
        "大石":"你仔細看了看這塊石頭, 發現石頭中央有一塊發光物體, 在大石上有一個手印,
你有一股衝動想要去推推看。\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","forest"); 
//        set("reborn",900);
        setup();
}
void init()
{ 
         add_action("do_push","push");
}
int do_push(string arg)
{
        object me=this_player();
        int stone = this_object()->query_temp("stone"); 
        if (!arg || arg =="")
        return notify_fail("你要推什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");

        if (arg != "大石") return 0;
        if(me->query_skill("force") >= 100 && me->query("ap") >=1200 )
          {
                message_vision("$N突然心血來潮，用雙手灌滿了內勁，只見$N用力的把雙手往大石上搥了下去！！\n",me); 
          if(stone != 1){
                message_vision("只見大石中的發光部份被$N的內勁震了出來。\n",me);
                me->receive_damage("ap",1000);
                this_object()->set_temp("stone",1);
                switch( random(10) ){
                default:
                new(__DIR__"npc/obj/iron")->move(this_player());
                message_vision(HIG"$N得到了一塊鐵石！！\n\n"NOR ,me);
                break;
                case 1:
                new(__DIR__"npc/obj/iron2")->move(this_player());
                message_vision(HIG"$N得到了一塊精鐵石！！\n\n"NOR ,me);
                break; 
                case 2:
                new(__DIR__"npc/obj/sun-stone")->move(this_player());
                message_vision(HIG"$N得到了一塊陽石！！\n\n"NOR ,me);
                break;
                case 3:
                new(__DIR__"npc/obj/moon-stone")->move(this_player());
                message_vision(HIG"$N得到了一塊陰石！！\n\n"NOR ,me);
                break;
                } 
                call_out("can_push",7200,this_object());
              } else { 
                message_vision("但大石卻沒有絲毫的動靜。\n",me);
              }
          }
          else{
                message_vision("$N突然心血來潮，用雙手灌滿了內勁。\n",me);
                message_vision("只見$N用力的把雙手往大石上搥了下去。\n",me);
                message_vision("也許\是$N的內功\不夠深厚，大石並沒有任何的反應。\n",me);
             }                               
        return 1;
}

void can_push()
{ 
        this_object()->set_temp("stone",0);
       return;
} 

