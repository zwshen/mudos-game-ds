inherit COMBINED_ITEM;

void create()
{
        set_name("大鳳尾草", ({"large feng-wei herb", "feng-wei", "herb"}));
        if( !clonep() ) {
                set("unit", "些");
                set("long",@long
鳳尾草倒算是滿常見的藥草，似乎具有極神奇的恢復功效，但是對於
普通人就沒什麼用處的樣子。這是一株比較大的鳳尾草，上頭的草葉也
比一般的較鮮豔的多。
long
);
                set("base_unit", "株");
                 set("base_value", 1000);
                set("base_weight", 10);
        }
        set_amount(1);
        setup();
}

int stuff_ob(object me)
{
        if( me->query_stat_maximum("food") - me->query_stat("food") < 10 )
                return notify_fail("你的肚子已經撐得什麼東西也吞不下去了。\n");
        message_vision("$N拿出一株大鳳尾草放入口中、頗費力地嚼了嚼吞了下去。\n", me);
        me->consume_stat("water", 10);
        me->supplement_stat("food", 10);
        me->consume_stat("gin", 5);
        me->supplement_stat("nina", 50);
          me->heal_stat("nina", 5);
        add_amount(-1);
        return 1;
}

