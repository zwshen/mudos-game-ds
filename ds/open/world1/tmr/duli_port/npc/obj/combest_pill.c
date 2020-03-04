inherit COMBINED_ITEM;

void create()
{
        set_name("康仔保濟丸", ({ "comebest pill", "pill"}));
        if( !clonep() ) {
                set("unit", "些");
                set("long",@long
這是一粒隨便都能在藥店買到的藥丸，對於恢復精神滿有療效的。
long
);
                set("base_unit", "粒");
                set("base_value", 20);
                set("base_weight", 20);
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                return notify_fail("你的肚子已經很撐了，無法吃下這株藥丸。\n");
        message_vision("$N吃下了一粒康仔保濟丸。\n", me);
        me->consume_stat("water",20 );
        me->supplement_stat("food", 5);
        me->supplement_stat("gin", 15);
        add_amount(-1);
        return 1;
}

