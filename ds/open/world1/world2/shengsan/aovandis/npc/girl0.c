// In room118.c �Ӫ���
inherit NPC;

void make_mark();

void create()
{
	set_name("�p�k��",({"girl"}) );
	set("long","�o�O�@��ĥ����p�ġC\n");		
	set("age",7);
	set("level",5);
    set("con",2);
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
		(:command("say ����u�n���I"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",3);
	set_skill("block",3);
	set_skill("parry",3);
	set_skill("unarmed",3);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	add_money("dollar",5);
}

void make_mark()
{
	object *enemy, ob;
	command("say ��~~�����򥴧ڡA�n�h��I");
	command("cry");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�O�a�H�C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
