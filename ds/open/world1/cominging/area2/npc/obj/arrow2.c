// arrow 箭: 2, NPC 用箭
inherit ITEM;

void create()
{

	set_name("鐵箭",({"iron arrow","arrow"}));
	set_weight(1250);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
        	set("value", 10);
        	set("unit", "支");
        	set("long","一支整支都用鐵所做成的一把箭, 上面還有刻著些字, 看這的重量, 殺傷力必定不小。\n");
        }
	set("arrow/damage", 20);         //殺傷力
	setup();
}