#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"包子袋"NOR, ({ "dumping bag","bag" }) );
        set_weight(600);
        set_max_capacity(500);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "這是一口大袋子，紅白相間，似乎有奇妙的魔力。\n");
                set("value",10000);
               }
        setup();
}
void init()
{
      add_action("catchmob", "catch");
      add_action("freemob", "free");
}
int catchmob(string arg)
{
    object me, ob;
    string myid, myname, mobname;
    me = this_player();

    if( !arg ) return notify_fail("你要抓什麼東西﹖\n");
    if( !objectp(ob = present(arg, environment(me))) )
        return notify_fail("這裡沒有這樣東西。\n");
    if( stringp(me->query( "have_one" )))
        return notify_fail("你只能持有一隻。\n");
    if(userp(ob) || !living(ob))
        return notify_fail("使用對象是不合法的。\n");
    if(!ob->is_character() || ob->is_corpse())
        return notify_fail("你看清楚一點，那並不是活物。\n");

    myid    = capitalize(me->query("id"));
    myname  = me->query("name");
    mobname = ob->query("name");

    me->set("have_one", base_name( ob ));
    me->set("mob_name", mobname);
    message_vision("$N悄悄的靠近$n，然後把"HIW"神風"HIR"袋"NOR"往$n頭上一套。\n"NOR
                HIB"\n$N"HIB"把$n"HIB"給蓋\布袋了！\n"NOR, me, ob);;
    destruct(ob);
    return 1;
}
int freemob()
{
    object me, ob, charger;
    string charger_base;
    me = this_player();
    charger_base = me->query("have_one");
    if( !charger_base )
    return notify_fail("你的神風袋裡並沒有什麼東西可以讓你放出來的•\n");

    me->delete("short");
    me->delete("mobname");
    me->delete("have_one");

    charger = new( charger_base );
    charger->move( environment( me ) ); 
    charger->set("creater",me);
message_vision
("$N把"HIW"神風"HIR"袋"NOR"一甩，$n從"HIW"神風"HIR"袋"NOR"裡掉了出來•\n"NOR, me, charger);
    return 1;
}

