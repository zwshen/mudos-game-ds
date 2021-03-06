#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"毒藥"NOR, ({ "poison" }));
        set("long", "這是毒藥, 可以throw在別人身上。\n");
        set("unit", "包");
        set("value", 10000);
        set_weight(1);
}

void init()
{
        add_action("do_throw","throw");
}

int do_throw(string arg)
{
        string obname, id;
        object item, ob;

        if(!arg) return notify_fail("throw <item> to <target>\n");
        if(sscanf(arg, "%s to %s", obname, id) != 2) return notify_fail("throw <item> to <target>\n");
        if(!item = present(obname, this_player())) return notify_fail("你沒有這種東西。\n");
        if(base_name(item) != base_name(this_object())) return notify_fail("那東西不能這樣用。\n");
        if(!ob = present(id, environment(this_player()))) return notify_fail("這裡沒有這個人。\n");
        if(!living(ob)) return notify_fail("那不是活物。\n");
        message_vision("$N把手上的毒粉灑向了$n, $n身上開始受到毒的侵蝕...\n", this_player(), ob);
        ob->apply_condition("poison", 6);
        destruct(this_object());
        return 1;
}

