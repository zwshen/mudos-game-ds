// In room078.c �Ȫ�
inherit NPC;

void make_mark();

void create()
{
	set_name("�Ȫ��d�O�p�j",({"miss"}) );
	set("long","�o���ͦR�������o�X�k�ʯS���������C\n�o�̪��ȫȭn��J�e���������V�o�n�O�åI�O(pay)�C\n");		
	set("age",32);
	set("level",10);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",4);
	set("chat_msg",({
		(:command("say �١I�z�n�A���ݭn���z�A�Ȫ��a��ܡH"):),
		(:command("smile"):),
		(: command,"say �n��J�ܡH" :),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);
	set("inquiry",([
  	"��J" : "��J�@���u�n 200 �����I\n",
  	"�I�O" : "�ڭ̥��b�S����..�@���u�n 200 ���I\n",
  	"pay" : "�ڭ̥��b�S����..�@���u�n 200 ���I\n",
  	"�n�O" : "���Ψ���·аա㤣�ެO�n�H�a�H, �u�n�O�����H�N�i�H��C\n",
	]));
	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	add_money("dollar",50);
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_pay","pay");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(random(2)) command("say �z�n!�w����{!!");
}
int do_pay(string arg) // rest & sleep
{
	object me,miss;
	string c;
	me = this_player();
	miss = this_object();

	if( !arg || arg!="miss")
	{
		notify_fail("�I������??\n");
		return 0;
	}

	if( !me->can_afford(200) )
		return notify_fail("�z���W����������C(200��)\n");
	if( me->query_temp("hotel_1")>0 )
		return notify_fail("�z�w�g�I�L���F�A�ФW�ӥ�(sleep)�a�C\n");
	me->receive_money(-200);
	me->add_temp("hotel_1",1);
	message_vision("$N�I���F$n��ʤ���J�O�C\n",me,miss);
	command("smile "+me->query("id"));
	return 1;
}

void make_mark()
{
	object *enemy, ob;
	command("say �z�I�ϩR���I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
