#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("緊身衣",({"suit"}) );
        set("long","這是一件很普通的衣服，穿上後會自動收窄，具有很好的防禦力。\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","件");
set("value",1000);
set("material","cloth");
set("armor_prop/armor", 10);
        }
        setup();
}
