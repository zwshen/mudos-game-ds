inherit F_BULLET;
inherit ITEM;
void create()
{

set_name("¤õ½b¼u",({"rockets"}));
if( clonep() )
set_default_object(__FILE__);
set("unit", "ªT");
set("value", 60);
set_weight(1220);
set("amount",3);
set("bullet/damage",22);
set("bullet/unit","ªT");
set("bullet/name","¤õ½b");
set("type","small");
setup();
}
