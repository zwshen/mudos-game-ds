#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name(HIB"���k�T"NOR,({"ai-hun robe","ai-hun","robe"}) );
        set("long", @LONG
�ǻ��������Ҭ÷R���k�T���@�A�����ɪ��o�X�\�H��z���f�Ū����A�C
LONG    );
	set_weight(4200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
		set("value",3300);
        	set("armor_prop/sou",1);
        	set("armor_prop/shield",5);
		set("armor_prop/bar",-1);
        }
        setup();
}

// int query_autoload() { return 1; }
