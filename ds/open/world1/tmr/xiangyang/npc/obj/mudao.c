// mudao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��M", ({ "mu dao", "blade", "dao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "�`");
		set("long", "�o�O�@�`��K������M�A��u�۷���ӡC\n");
		set("value", 50);
		set("material", "steel");
		set("wield_msg", "$N�q�y�a�̩�X�@�`$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���^�y�a�W�C\n");
	}
	init_blade(3);
	setup();
}