#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"�ȯS���C"NOR, ({"art longsword","longsword","sword"}) );
	set_weight(8300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����C�M�W����ۡu�ȯS�v��Ӧr�C\n");
		set("value", 4130);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
	set("weapon_prop/bar",1);
	set("weapon_prop/bio",-1);
	init_sword(20);
	setup();
}

//int query_autoload() { return 1; }
