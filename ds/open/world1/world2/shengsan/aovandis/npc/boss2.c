// In room081.c �ѥ]��
inherit NPC;
inherit SELLMAN;

void make_mark();

void create()
{
	set_name("�ѥ]������",({"boss"}) );
	set("long","�L�����ѥ]�H�H���R�Y�C\n");		
	set("age",32);
	set("level",10);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",2);
	set("chat_msg",({
		(:command("say ���Q�Q���ѥ]�X�l�o�I"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");

	set("sell_list",([
		__DIR__"food/ladyfinger":30,
		__DIR__"food/smallcake"	:30,
	]));

	setup();

	add_money("dollar",200);
}

void init() 
{
	::init();
	add_action("do_list","list");
	add_action("do_buy" ,"buy");
}

void make_mark()
{
	object *enemy, ob;
	command("say �z�I���n���ڡI");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
