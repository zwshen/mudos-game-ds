#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("�Q�����",({"ten long staff","staff"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�@��۷�������A�����e�h����A���b���Y���a��o�x���C\n");
            set("value",2500);
       set("volume",3);
               set("material", "wood");
        }
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
        set("limit_str",10);
        init_staff(36);
   setup();
}
