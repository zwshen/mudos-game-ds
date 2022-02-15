// In room093.c ���ŻȦ�
inherit NPC;
inherit BANKMAN;

void make_mark();

void create()
{
	set_name("�Ȧ�k���",({"miss"}) );
	set("long","�@����R���p�j�ˤ����V�z���n�۩I�C\n");		
	set("age",38);
	set("level",15);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",3);
	set("chat_msg",({
		(:command("say ������Ȧ�~�ȭn�ڬ��z�A�ȶܡH"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	add_money("dollar",200);
}

void init()
{
	::init();
	add_action("do_deposit","deposit");
	add_action("do_withdraw","withdraw");
}

void make_mark()
{
	object *enemy, ob;
	command("sob");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
