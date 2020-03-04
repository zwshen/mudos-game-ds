inherit COMBINED_ITEM;

void create()
{
        set_name( "獅肉乾" , ({"lion jerk", "jerk"}));
        if( !clonep() ) {
                set("unit", "些");
                set("long",@long
這是一塊風乾的獅肉乾，聞起來有點酸酸澀澀，不知道嚐起來味道如何。
long
);
                 set("base_unit", "片");
                set("base_value", 20) ;
                set("base_weight", 20 );
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
                  return notify_fail("你的肚子已經很撐了，無法吃下這片肉乾。\n");
        message_vision("$N吃下一片發酸的肉乾，臉上神色不是很好看。\n", me);
        me->consume_stat("water",30 );
        me->supplement_stat("food", 5);
        me->supplement_stat( "gin" , 30 );
        add_amount(-1);
        return 1;
}

