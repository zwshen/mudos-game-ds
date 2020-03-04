inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("ド艶う", ({ "u-len pill", "pill" }));
        set("long",@LONG
采屡︹媚莱琌チ丁硄盽ド艶うパㄤず玪菠Τ
痲矪程琌︽ǐ打猌畍单┮稲ノ
LONG
);
        set_weight(455);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
        	set("unit", "采");
        }
        set("value", 150);
	set("heal",([ "ap": 40,]));
        setup();
}


