// In room052.c �ǳN���D
inherit NPC;

void make_mark();

void create()
{
	set_name("�k����",({"citizen"}) );
	set("long","�o��ۻ��K��A�A���|�ܬ��R�C\n");		
	set("age",33);
	set("level",7);
    set("con",3);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �ա�ա�ա�ڰ۪��q�n���nť�C�H�H�C"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
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

	add_money("dollar",40);
}

void make_mark()
{
	object *enemy, ob;
	command("say �ϩR���I����T��~~");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�O�ޤK�١C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
