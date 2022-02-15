#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;

void create()
{
        set_name(HIM "�I�G�I��" NOR,({ "dab-aqua-armor","armor" }) );
        set("long",
"�o�O�@�j���u���s  �I�G�v�I�W������A�ݨ�����Q�������p�C�A\n"
"��������Q�ӬݮɡA�~�a�o�{���������o�X�@�Ѥ����W�������A�����l\n"
"�J(suck)�L�h�A�����|���|���ͤ���@�ΡC\n"
);
	set_weight(18000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",30);
        set("limit_level",15);
        set("value",16000);
        set("replica_ob",__DIR__"dab-aqua-armor2");
	set("armor_prop/armor",40);
        set("armor_prop/dex", -4);
	}
	set("beast_armor_prop/armor",40);
	set("beast_armor_prop/dex",-4);
	set("beast_armor_type","armor");
        setup();
}

void init()
{
	add_action("do_suck","suck");
}

int do_suck(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();

	if(!arg || arg!="�I�G�I��") return 0;
        if( !ob->query("equipped") ) return 0;
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("�A�����ۡA�S���Ű���L�ơC\n");
	if( me->query("hp") < 500 )
	{	
	message_vision("$N�`�`�a�l�F��b���W���I�G�I��o�X�������C\n",me);
	tell_object(me,HIY"�Aı�o�������G�ΪA�F���֡C\n" NOR);
	me->receive_heal("hp",35);
	}
	else 
	{
	message_vision("$N�`�`�a�l�F��b���W���I�G�I��o�X�������C\n",me);
	tell_object(me,"�A�èS��ı�o�����򤣤@�ˡC\n");
	}
	return 1;
}
