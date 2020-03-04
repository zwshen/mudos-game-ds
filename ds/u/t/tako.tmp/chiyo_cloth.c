#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"虎皮大衣"NOR,({"tiger cloth","cloth"}) );
        set("long",@LONG
這一件虎皮大衣是以前蚩尤製虎魄的時候,一並從猛虎的
身上取下來的,隨著身體的各別形狀服貼,但又不緊繃,是
一件上等的好衣,輕巧無比。
LONG

);
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("value",240);
        set("armor_prop/armor",20);
        set("armor_prop/dodge",40); 
        set("armor_prop/parry",5);
        set("armor_prop/blade",20);
        set("armor_prop/dex",1);
        setup();
}



