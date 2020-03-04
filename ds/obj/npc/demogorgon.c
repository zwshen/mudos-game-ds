// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "�V�Ѱ���" NOR, ({ "demogorgon" }) );
	set("long",
		"�V�Ѱ��������жƦa���b�A���e�M�L���j�����߸�@�ѥO�H������\n"
		"�i�ȱ������o�A�X�G�ݤ��L��ӡM�A���߸̦��G���@���n���b�i\n"
		"�D�A�R�u �� �k �T�T�v\n");

	set("age", 7777);
	set("pursuer", 1);

	set("max_hp", 5000);
	set("max_mp", 5000);
	
	set("max_atman", 9999);
	set("atman", 9999);
	set("max_force", 5000);
	set("force", 5000);
	set("max_mana", 5000);
	set("mana", 5000);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 0);
	set("per", 0);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 500);

	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;

	message("system",
		HIR "\n�Ať��ѪŤ��ǨӤ@�}�i�Ȫ��H�� ....\n\n"
		HIW	"�V�Ѱ���" HIR "�ξ_�ձ�Ť���n���ܹD�R\n\n"
			"\t\t�� �� �U �� �� �� �� �� ť �� �T\n\n"
			"\t\t���A�̨��������ڪ��Y�`��X�� �T\n\n"
			"\t\t�� �M �� �� ..... �� .. �� �T\n\n" NOR,
		users() );
	call_out("countdown", 60, 2);
}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
			HIW "\n�V�Ѱ���" HIR "�ξ_�ձ�Ť���n���ܹD�R\n\n"
				"\t\t�A���٦�" + chinese_number(min) + "�������ɶ���X�ڪ��Y�`�T\n\n"
				"\t\t�w���w�n�w�R�w���w�N�w���w�ڢw�C�w�C�w��w�a�w�T\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
			HIW "\n�V�Ѱ���" HIR "�ξ_�ձ�Ť���n���ܹD�R\n\n"
				"\t\t�i��.....�u�O�i��....\n\n"
				"\t\t�a�Ѱڡ� �j�a�ڡ�  ���v�ڡ�  ���Ͱڡ�\n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	}
}

private void do_shutdown()
{
	message("system",
		HIW "\n\n�V�Ѱ���" HIR "�ξ_�ձ�Ť���n���ܹD�R\n\n"
		HIW "\t\t�q �q �M �� �@ �_ �U �a �� �a ����� �T\n\n"
		HIR "\t\t�n���@���M�Ѫťߨ��ܱo����M��....�A���e���@�����ܱo���...\n\n"
			"\t\t�Ҧ����@�����b�������J����....\n\n"
			"\t\t�M��A�����e�O�@���·t....�L��ɪ��·t....\n\n" NOR,
		users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;

	message("system",
		HIR "\n\n�Ať��@�n�a�ۼ���B�宣�B�P���~�몺�H���n�T����ӤѪšC\n\n"
		HIW "�V�Ѱ���" HIR "�R�צa�q�ۡR�i�c��" + ob->name(1) + "�M�ڤ@�w�|����������\n\n"
			"�M��@�D�¦���K�I�S�۽ĤW���ݡM�j�a�S��_�F���R�C\n\n" NOR,
		users() );
	destruct(this_object());
}