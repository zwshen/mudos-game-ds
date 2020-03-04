inherit COMBINED_ITEM;

void create()
{
        set_name( "熊肉乾" , ({"bear jerk", "jerk"}));
        if( !clonep() ) {
                set("unit", "些");
                set("long",@long
這是一塊風乾的熊肉乾，有股濃厚的腥味，讓人聞著不禁作嘔起來。
long
);
                 set("base_unit", "片");
                set("base_value", 40) ;
                set("base_weight", 20 );
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                  return notify_fail("你的肚子已經很撐了，無法吃下這片肉乾。\n");
        message_vision("$N吃下一片腥羶的肉乾，臉上露出痛苦的表情。\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->supplement_stat( "gin" , 10 );
        me->heal_stat("gin", 15 );
        add_amount(-1);

        return 1;
}

