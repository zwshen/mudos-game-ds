#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me,object ob);

void create()
{
        set_name(HIY"黃金鐘"NOR ,({"golden bell","bell"}) );
        set_weight(5000000); 
        set("long", @long
黃金其實是空島上沒有的物質，而這座黃金鐘，據說是四百年前由藍
色大地升上來的。黃金鐘前擺有處水晶火盆，裡面滿滿地都是燒過的灰燼
，或許你可以試試在這火盆裡燒(fire)一些東西。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","座");
                set("no_get",1);
                set("no_sac",1);
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_firing","fire");
}

string WAR_FILE = "/open/war/soul_war.c";
int do_firing(string arg)
{
        object me,ob,torch;
        me=this_player();
        ob=this_object();
        if( WAR_D->isActive(WAR_FILE))
                return notify_fail("「空島之戰」還沒有結束。\n");
        if(!objectp(torch=present("torch",me) ) )
                return notify_fail("你身上沒有火把。\n");
          if(!arg || arg!="火盆")
                return notify_fail("你要點燃什麼東西?\n");
        message_vision(HIW"$N拿起"HIR"火把"HIW"點燃了火盆裡的東西。\n"NOR,me);
        destruct(torch);
        call_out("open_war",3,me,ob);
        return 1;
}

void open_war(object me,object ob)
{
        message_vision(HIM"燃燒的火盆冒出漫漫烏雲，像是打開了某個通道...\n"NOR,me);
        
        if( !WAR_D->doStartWar(me, WAR_FILE) ) {
                        tell_room(ob, "但是什麼事也沒有發生。\n");
        }
}


