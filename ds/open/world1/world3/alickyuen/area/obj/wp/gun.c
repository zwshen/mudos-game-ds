#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name("�{��",({"shining gun","gun"}));
set("long","�@��H�̱`�Ϊ���C\n");
set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",500);
                set("rigidity",800);    
                set("material","iron");
 set("limit_lv",15);
                                set("limit_con",5);
                set("limit_int",15);
                set("limit_str",15);
        }

        set("wield_msg","$N�q��U�̮��X�@��$n�C\n");
        set("unwield_msg", "$N�N��W��$n��^��U�̡C\n");
        set("bullet_type","clip"); //�i�Τl�u����
        set("max_load",25);             //�̤j�˶�q
        init_gun(10);   // �׷i�ˮ`�O=set("weapon_prop/damage", 14);
        setup();
}