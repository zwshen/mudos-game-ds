// In room096.c �}�G��
inherit NPC;
inherit SELLMAN;

void make_mark();

void create()
{
	set_name("�}�G�Ω���",({"clerk"}) );
	set("long","�o�O�@��N�֥i�R�����֤k�C\n");		
	set("age",20);
	set("level",9);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �������I�߿}�G�O�Ҧn�Y�I"):),
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
		__DIR__"food/chocolateb"	:22,
		__DIR__"food/softsweets"	:16,
		__DIR__"food/milkcandy"		:13,
	])	);
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
	command("say �A���ۭt�@�Ӯz�k�l�I�ϩR���I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
