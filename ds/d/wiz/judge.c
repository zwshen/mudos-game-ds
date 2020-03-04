// judge.c

#include <login.h>
#include <ansi.h>

inherit NPC;

int in_ask, answer;

void create()
{
	set_name("�f�P�x", ({ "judge" }) );
	set("short", "�M����I�����H��" HIY "�f�P�x" NOR "(judge)" );
	set("long",
		"�o�O�@��f�d���a�O�_�O�����H���f�P�x�M�A��������(answer)�L�T�Ӱ��D�~��\n"
		"�����L���x���C\n");

	set("gender", "�k��");
	set("age", 40);
	set("combat_exp", 9000000);
	set("level", 100);
	set_temp("apply/armor", 500);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);

	setup();

	in_ask = 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer", "answer");
}

void chat()
{
	int a, b, c;
	string oper;
	
	if( in_ask || random(20) > 10 ) return;
	delete_temp("wrong");
	a = random(100) + 1;
	b = random(100) + 1;
	switch(random(5)) {
		case 0: 
			answer = a + b;
			oper = chinese_number(a) + "�[�W" + chinese_number(b)+ "����h�֡S";
			break;
		case 1: 
			answer = a - b;
			oper = chinese_number(a) + "��h" + chinese_number(b)+ "����h�֡S";
			break;
		case 2: 
			if( a * b < 200 ) {
				answer = a * b;
				oper = chinese_number(a) + "���W" + chinese_number(b)+ "����h�֡S";
			} else {
				answer = (a * b) % 10;
				oper = chinese_number(a) + "���W" + chinese_number(b)+ "�M�Ӧ�Ƶ���h�֡S";
			}
			break;
		case 3: 
			answer = a % b;
			oper = chinese_number(a) + "���H" + chinese_number(b)+ "�l��h�֡S";
			break;
		case 4:
			oper = chinese_number(a) + "�M" + chinese_number(b)+ "���̤j���]�ƬO�h�֡S";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
	}
	command("say " + oper + "�M�Цb�G�Q�����@��(answer)�C");
	in_ask = 1;
	call_out("say_answer", 20);
}

void say_answer()
{
	command("say �o��²�泣���|�S���׵���" + chinese_number(answer) + "�C");
	in_ask = 0;	
}

int do_answer(string arg)
{
	string s;
	int ans;

	if( !in_ask ) return notify_fail("�A�������U�@�D�C\n");
	if( !arg ) return notify_fail("�ЧA�^���@�ӼƦr�C\n");

	message_vision( CYN "$N���D�R" + arg + "\n" NOR, this_player());
	
	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add_temp("robot_check", 1);
			command("say ����F�T");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query_temp("robot_check") >= 3 ) {
				command("say �ܦn�M�A�ݰ_�Ӥ��������H�M�A�i�H���F�C\n");
				if( stringp(s = this_player()->query("accuse_position")) )
					this_player()->set("startroom", s);
				this_player()->delete_temp("robot_check");
				if( stringp(s = this_player()->query("accuse_position")) )
					this_player()->move(s);
				else
					this_player()->move(START_ROOM);
			}
		} else {
			command("say ���T");
			add_temp("wrong/" + this_player()->query("id"), 1);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 )
			{
				command("say " + this_player()->name() + "�A�A���ڶòq�ڡM�h���a�C\n");
				this_player()->receive_damage("hp", 100, this_object());
				this_player()->die();
			}
		}
	}
	return 1;
}