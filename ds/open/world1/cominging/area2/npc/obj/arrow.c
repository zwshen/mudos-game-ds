// arrow 箭
inherit ITEM;

void create()
{

	set_name("木箭",({"wood arrow","arrow"}));
	set_weight(250);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
        	set("value", 0);
        	set("unit", "支");
        	set("long","木頭製的弓箭, 弓箭雖然是木製的, 但是尖銳的箭鋒還是讓人冷汗直流。\n");
        }
	set("arrow/damage", 10);         //殺傷力
	setup();
}