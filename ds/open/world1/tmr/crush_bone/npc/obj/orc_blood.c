inherit ITEM;

void create()
{
    set_name("半獸人血液", ({"orc's blood", "blood", "_CRUSH_BONE_BLOOD_"}));
    if( !clonep() ) {
        set("long", "一瓶半獸人的綠色血液，不斷散出惡臭，有種想吐的感覺。");
        set("unit", "堆");
        set("value", 100);
        set("unit", "瓶");
        set("weight", 20);
        } else
		   set_default_object(__FILE__);
    setup();
}

