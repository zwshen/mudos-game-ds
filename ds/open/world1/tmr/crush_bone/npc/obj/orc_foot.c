inherit ITEM;

void create()
{
    set_name("¥bÃ~¤H¸}´x", ({"orc's foot", "foot", "_CRUSH_BONE_FOOT_"}));
    if( !clonep() ) {
        set("long", "¤@¤ä¦å²O²Oªº¸}´x¡A©ÇÀ~¤Hªº.. ~.~!");
        set("unit", "°¦");
        set("value", 10);
        set("weight", 20);
        } else
		   set_default_object(__FILE__);
    setup();
}
