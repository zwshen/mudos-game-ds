inherit COMBINED_ITEM;

void create()
{
    set_name("飢渴丹", ({"hungry and thirsty pill", "pill" }));
    if( !clonep() ) {
        set("unit", "些");
        set("long", "會讓人拉肚子而達到飢渴的效果。");
        set("base_unit", "顆");
        set("base_value", 10 );
        set("base_weight", 20 );
    }
    set_amount(1);
    setup();
}

int stuff_ob(object me)
{
    if( me->query_stat("food") < 30 || me->query_stat("water") < 30 )
        return notify_fail("你又餓又渴，再吃下去你會脫肛而亡。\n");
    
    message_vision("$N吞下一顆飢渴丹後肚子發出咕嚕咕嚕的叫聲，而雙腳直發抖，好像有東西要出來一樣。\n", me);
    me->consume_stat("food", 30);
    me->consume_stat("water", 30);
    add_amount(-1);
    return 1;
}

