#include <ansi.h>

inherit ROOM;

string show_songs();

void create()
{
        set("short", "步靈城火鳳凰台");
        set("long",@LONG
你正站在步靈城的火鳳凰台上，在這裡的周圍是由竹木所築成的
，看起來雖然容易倒塌，但火鳳凰台也存在上百年的時間了。在你面
前有座火鳳凰的銅像，傳說如果你搜集了七顆夜明珠，你就能在這邊
招換(evoke phoenix)出火鳳凰來到這個世界上，到時是福是禍，完
全沒有人可以預料。
LONG
        );
        set("exits", ([
  "enter" : __DIR__"survey.c",
]));

        set("objects",([
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init() {
        add_action("do_evoke","evoke");
}

int do_evoke(string arg) {
        object me, ob, mob;
        int ct = 0;
        if(arg != "phoenix") return 0;
        me = this_player();

        // lv 31 以下不能叫火鳳凰
        if( me->query("level") < 31 ) 
                return notify_fail("你的等級至少要31級，才能招喚火鳳凰。\n");

        foreach(ob in all_inventory(me))  {
                if( ob->query("phoenix") ) 
                ct++;
        }
        if(ct<7) return notify_fail("你沒有搜集到七顆夜明珠。\n");

        
        if( sizeof(filter_array( children(__DIR__"phoenix"), (: clonep :) )) ) {
                tell_object(me, HIR"呼叫火鳳凰失敗！請與Alickyuen聯絡。\n"NOR);
                return 1;
        }

         mob = new("/open/world1/alickyuen/phoenix/phoenix");
         if( mob->move("/open/world1/cominging/area/boo-lin") )
         {
                message("world:world1:vision", HIB"\n突然之間天上烏雲密佈....\n\n\t"HIW"原來是"+me->name()+"成功\找齊七顆夜明珠喚醒"HIR"火鳳凰"HIW"！\n\n"NOR, users());
                me->add("popularity", 1);
                me->add("exp", 3000);
                me->set_temp("no_quit", 1);
                tell_object(me, HIY"你得到了1點聲望及3000經驗值。\n"NOR);
                log_file("area/phoenix", me->name(1)+"("+me->query("id")+") 於 "+ctime(time())+" 呼叫phoenix。\n");
                foreach(ob in all_inventory(me))  {
                       if( ob->query("phoenix") )
                        destruct(ob);
                }
        }
    return 1;
}

