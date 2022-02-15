// In room085.c ������| room102.c ������|�}�M��
inherit NPC;

void make_mark();

void create()
{
	set_name("�@�h",({"nurse"}) );
	set("long","�@����R���p�j�ˤ����V�z���n�۩I�C\n");		
	set("age",22);
	set("level",9);
    set("con",4);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-15);	// ���c�� -15 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
set_temp("apply/dodge",-10);    //�z�ư{���v
set_temp("apply/hit",-10);      //�z�ƩR���v
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �ର�f�H�A�ȬO�ڤ@�ͤ��ּ̧֪��ơI"):),
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

	add_money("dollar",100);
}

void make_mark()
{
	object *enemy, ob;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if(random(30)%2)
		command("say �z�I�ϩR���I");
	else
		command("slap "+ob->query("id"));

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
