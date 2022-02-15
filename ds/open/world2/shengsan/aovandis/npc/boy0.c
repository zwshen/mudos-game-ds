// In room118.c �Ӫ���
inherit NPC;

void make_mark();
string s_water();
string s_mother();

void create()
{
	set_name("�p�k��",({"boy"}) );
	set("long","�L�O�@��x�֪��p�ġC\n");		
	set("age",7);
	set("level",3);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
set_temp("apply/hit",-20);      //�z�ƩR���v
set_temp("apply/dodge",-20);    //�z�ư{���v
	set("chat_chance",3);
	set("chat_msg",({
		(:command("say �n�γ�I�o�Ӷg�������n�a�ڥh�����D�����C�C"):),
		(:command("laugh"):),
		(: this_object(), "random_move" :),
	})	);

	set("inquiry/�����D��",(: s_water :) );
	set("inquiry/����",(: s_mother :) );
	set("inquiry/���}",(: s_mother :) );
	set("inquiry/mother",(: s_mother :) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",5);
	set_skill("block",4);
	set_skill("parry",4);
	set_skill("unarmed",4);

	set("talk_reply","���A�Ӫ���̦��n�h�n�����F���C");
	setup();

	add_money("dollar",5);
}

void make_mark()
{
	object *enemy, ob;

	command("say ���}�E�E�E�ϩR�ڡI�I�I�I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�|����������C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}

string s_water()
{
	return "�@�H�A�O�������D���ܡH�ڷQ�A���Ӱݰݧڶ��}�~��C";
}

string s_mother()
{
	return "�ڶ��}�H�x�H�ڶ��}��򤣨��F�H�A���D�o�b���̶ܡH";
}
